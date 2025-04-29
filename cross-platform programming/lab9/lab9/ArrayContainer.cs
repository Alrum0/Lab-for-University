namespace lab5;

public class ArrayContainer<T> : IContainer<T>, IEnumerable<T> where T : IName
{
    private T[] items;
    private int[] additionOrders; 
    private int count;
    private int additionCounter;
    
    public ArrayContainer()
    {
        items = new T[4]; 
        additionOrders = new int[4]; 
        count = 0;
        additionCounter = 0;
    }
    
    public int GetAdditionOrderAt(int index)
    {
        if (index < 0 || index >= count)
            throw new IndexOutOfRangeException();
        return additionOrders[index];
    }
    
    public int GetAdditionOrder(IName item)
    {
        int index = 0;
        foreach (var element in this)
        {
            if (element.Equals(item))
                return additionOrders[index];
            index++;
        }
        throw new KeyNotFoundException("Product not found in container");
    }

    // Індексатор за порядком додавання
    public T this[int additionOrder]
    {
        get
        {
            if (additionOrder < 1 || additionOrder > count)
                throw new IndexOutOfRangeException("Invalid addition order");

            int index = 0;
            foreach (var item in this)
            {
                if (additionOrders[index] == additionOrder)
                    return item;
                index++;
            }

            throw new KeyNotFoundException($"No product with addition order {additionOrder} found");
        }
        set
        {
            if (additionOrder < 1 || additionOrder > count)
                throw new IndexOutOfRangeException("Invalid addition order");

            int index = 0;
            foreach (var item in this)
            {
                if (additionOrders[index] == additionOrder)
                {
                    items[index] = value;
                    return;
                }
                index++;
            }

            throw new KeyNotFoundException($"No product with addition order {additionOrder} found");
        }
    }

    // Індексатор за ім'ям
    public T this[string name]
    {
        get
        {
            if (string.IsNullOrEmpty(name))
                throw new ArgumentException("Product name cannot be null or empty");

            foreach (var item in this)
            {
                if (string.Equals(item.Name, name, StringComparison.OrdinalIgnoreCase))
                    return item;
            }


            throw new KeyNotFoundException($"Product with name '{name}' not found");
        }
        set
        {
            if (string.IsNullOrEmpty(name))
                throw new ArgumentException("Product name cannot be null or empty");

            int index = 0;
            foreach (var item in this)
            {
                if (string.Equals(item.Name, name, StringComparison.OrdinalIgnoreCase))
                {
                    items[index] = value;
                    return;
                }
                index++;
            }

            throw new KeyNotFoundException($"Product with name '{name}' not found");
        }
    }

    public IEnumerable<T> GetAllByPrice(decimal price)
    {
        List<T> result = new List<T>();
        foreach (var item in this)
        {
            if (item.Price == price)
                result.Add(item);
        }

        return result;
    }

    public IEnumerable<T> GetAllByName(string name)
    {
        List<T> result = new List<T>();
        foreach (var item in this)
        {
            if (string.Equals(item.Name, name, StringComparison.OrdinalIgnoreCase))
                result.Add(item);
        }
        return result;
    }

    public void Add(T item)
    {
        if (count == items.Length)
        {
            Array.Resize(ref items, items.Length * 2);
            Array.Resize(ref additionOrders, additionOrders.Length * 2);
        }

        items[count] = item;
        additionOrders[count] = ++additionCounter; 
        count++;
    }

    public void SortByName(bool ascending = true)
    {
        if (count <= 1) return;
        
        int[] indices = new int[count];
        for (int i = 0; i < count; i++)
            indices[i] = i;

        if (ascending)
        {
            Array.Sort(indices, (a, b) => items[a].CompareTo(items[b]));
        }
        else
        {
            Array.Sort(indices, (a, b) => items[b].CompareTo(items[a]));
        }

        ReorderItems(indices);
    }

    public void RemoveAt(int index)
    {
        if (index < 0 || index >= count)
            throw new IndexOutOfRangeException();

        for (int i = index; i < count - 1; i++)
        {
            items[i] = items[i + 1];
            additionOrders[i] = additionOrders[i + 1]; 
        }

        items[count - 1] = default(T);
        additionOrders[count - 1] = 0;
        count--;
    }

    public void SortByPrice(bool ascending = true)
    {
        if (count <= 1) return;


        int[] indices = new int[count];
        for (int i = 0; i < count; i++)
            indices[i] = i;

        if (ascending)
        {
            Array.Sort(indices, (a, b) => items[a].CompareByPrice(items[b]));
        }
        else
        {
            Array.Sort(indices, (a, b) => items[b].CompareByPrice(items[a]));
        }

        ReorderItems(indices);
    }

    private void ReorderItems(int[] newOrder)
    {
        T[] newItems = new T[items.Length];
        int[] newAdditionOrders = new int[additionOrders.Length];

        for (int i = 0; i < count; i++)
        {
            newItems[i] = items[newOrder[i]];
            newAdditionOrders[i] = additionOrders[newOrder[i]];
        }

        items = newItems;
        additionOrders = newAdditionOrders;
    }
    
    public T GetAt(int index)
    {
        if (index < 0 || index >= count)
            throw new IndexOutOfRangeException();
        return items[index];
    }

    public int Count => count;

    public override string ToString()
    {
        string result = "";
        foreach (var item in this)
        {
            result += item.ToString() + "\n";
        }
        return result;
    }
    public IEnumerator<T> GetEnumerator()
    {
        return new ArrayContainerEnumerator<T>(items, count);
    }

    System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
    {
        return GetEnumerator();
    }
}


public class ArrayContainerEnumerator<T> : IEnumerator<T> where T : IName
{
    private readonly T[] _items;
    private readonly int _count;
    private int _position = -1;

    public ArrayContainerEnumerator(T[] items, int count)
    {
        _items = items;
        _count = count;
    }

    public T Current => _items[_position];
    object System.Collections.IEnumerator.Current => Current;

    public bool MoveNext()
    {
        _position++;
        return _position < _count;
    }

    public void Reset() => _position = -1;

    public void Dispose() { }
}
