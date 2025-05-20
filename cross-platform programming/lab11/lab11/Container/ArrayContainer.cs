using System.Text.Json;
using System.Text.Json.Serialization;

namespace lab5;

[Serializable]
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
    
    // implement the iterators
    
    public IEnumerable<T> GetReverseOrder()
    {
        for (int i = count - 1; i >= 0; i--)
        {
            yield return items[i];
        }
    }

    public IEnumerable<T> GetItemsWithSubstring(string substring)
    {
        for (int i = 0; i < count; i++)
        {
            if (items[i].Name.Contains(substring, StringComparison.OrdinalIgnoreCase))
                yield return items[i];
        }
    }

    public IEnumerable<T> GetOrderedByName()
    {
        int[] indices = new int[count];
        for (int i = 0; i < count; i++)
            indices[i] = i;

        Array.Sort(indices, (a, b) => items[a].CompareTo(items[b]));
    
        for (int i = 0; i < count; i++)
        {
            yield return items[indices[i]];
        }
    }

    public IEnumerable<T> GetOrderedByPrice()
    {
        int[] indices = new int[count];
        for (int i = 0; i < count; i++)
            indices[i] = i;

        Array.Sort(indices, (a, b) => items[a].CompareByPrice(items[b]));
    
        for (int i = 0; i < count; i++)
        {
            yield return items[indices[i]];
        }
    }

    public void Serialize(string fileName)
    {
        using var fs = new FileStream(fileName, FileMode.Create);
        using var writer = new BinaryWriter(fs);

        writer.Write(count);
        writer.Write(additionCounter);

        for (int i = 0; i < count; i++)
        {
            writer.Write(additionOrders[i]);
            var item = items[i];
            
            string typeName = item switch
            {
                SmartWatch => "smartwatch",
                LuxuryWatch => "luxurywatch",
                MetalAccessory => "metalaccessory",
                LeatherAccessory => "leatheraccessory",
                SportWatch => "sportwatch",
                Accessory => "accessory",
                Watch => "watch",
                Product => "product",
                _ => throw new InvalidOperationException("Unknown item type")
            };
            writer.Write(typeName);

            if (item is IBinarySerializable serializable)
            {
                serializable.WriteToBinary(writer);
            }
        }
    }

    public IContainer<T> DeserializeFromFile(string fileName)
    {
        var container = new ArrayContainer<T>();

        using var fs = new FileStream(fileName, FileMode.Open);
        using var reader = new BinaryReader(fs);

        container.count = reader.ReadInt32();
        container.additionCounter = reader.ReadInt32();

        container.items = new T[container.count];
        container.additionOrders = new int[container.count];

        for (int i = 0; i < container.count; i++)
        {
            container.additionOrders[i] = reader.ReadInt32();

            string typeName = reader.ReadString();
            IName instance = typeName switch
            {
                "product" => new Product(),
                "smartwatch" => new SmartWatch(),
                "luxurywatch" => new LuxuryWatch(),
                "metalaccessory" => new MetalAccessory(),
                "leatheraccessory" => new LeatherAccessory(),
                "sportwatch" => new SportWatch(),
                "accessory" => new Accessory(),
                "watch" => new Watch(),
                _ => throw new InvalidOperationException($"Unknown type: {typeName}")
            };

            if (instance is IBinarySerializable serializable)
            {
                try
                {
                    serializable.ReadFromBinary(reader);
                }
                catch (Exception ex)
                {
                    throw new InvalidOperationException($"Failed to deserialize {typeName}: {ex.Message}");
                }
            }

            container.items[i] = (T)instance;
        }

        return container;
    }
    
    public void SerializeJson(string fileName)
    {
        string filePath = Path.Combine(Directory.GetCurrentDirectory(), fileName);

        var options = new JsonSerializerOptions
        {
            WriteIndented = true,
            Converters = { new INameConverter() }
        };

        List<T> items = this.ToList();
        string json = JsonSerializer.Serialize(items, options);
        File.WriteAllText(filePath, json);
    }

    public IContainer<T> DeserializeFromFileJson(string fileName)
    {
        string filePath = Path.Combine(Directory.GetCurrentDirectory(), fileName);

        if (!File.Exists(filePath))
            throw new FileNotFoundException("JSON file not found", filePath);

        var options = new JsonSerializerOptions
        {
            Converters = { new INameConverter() }
        };

        string json = File.ReadAllText(filePath);
        List<T> items = JsonSerializer.Deserialize<List<T>>(json, options)!;

        var container = new ArrayContainer<T>();
        foreach (var item in items)
        {
            container.Add(item);
        }

        return container;
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
