namespace lab5;

public class ArrayContainer<T> : IContainer<T> where T : IName
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
        for (int i = 0; i < count; i++)
        {
            if (items[i].Equals(item))
                return additionOrders[i];
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

            for (int i = 0; i < count; i++)
            {
                if (additionOrders[i] == additionOrder)
                    return items[i];
            }

            throw new KeyNotFoundException($"No product with addition order {additionOrder} found");
        }
        set
        {
            if (additionOrder < 1 || additionOrder > count)
                throw new IndexOutOfRangeException("Invalid addition order");

            for (int i = 0; i < count; i++)
            {
                if (additionOrders[i] == additionOrder)
                {
                    items[i] = value;
                    return;
                }
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

            for (int i = 0; i < count; i++)
            {
                if (string.Equals(items[i].Name, name, StringComparison.OrdinalIgnoreCase))
                    return items[i];
            }

            throw new KeyNotFoundException($"Product with name '{name}' not found");
        }
        set
        {
            if (string.IsNullOrEmpty(name))
                throw new ArgumentException("Product name cannot be null or empty");

            for (int i = 0; i < count; i++)
            {
                if (string.Equals(items[i].Name, name, StringComparison.OrdinalIgnoreCase))
                {
                    items[i] = value;
                    return;
                }
            }

            throw new KeyNotFoundException($"Product with name '{name}' not found");
        }
    }

    public IEnumerable<T> GetAllByPrice(decimal price)
    {
        for (int i = 0; i < count; i++)
        {
            if (items[i].Price == price)
                yield return items[i];
        }
    }

    public IEnumerable<T> GetAllByName(string name)
    {
        for (int i = 0; i < count; i++)
        {
            if (string.Equals(items[i].Name, name, StringComparison.OrdinalIgnoreCase))
                yield return items[i];
        }
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
        for (int i = 0; i < count; i++)
        {
            result += items[i].ToString() + "\n";
        }
        return result;
    }
}
