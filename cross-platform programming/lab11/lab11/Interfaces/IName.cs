using System.Runtime.Serialization;

namespace lab5;

public interface IName : IComparable
{
    string Name { get; set; }
    decimal Price { get; set; }

    public int CompareByPrice(object obj);
    public int CompareTo(object obj);
}

public interface IName<T>
{
    string Name { get; set; }
}


public interface IContainer<T>: IEnumerable<T> where T : IName
{
    int Count { get; }
    void Add(T item);
    T GetAt(int index);
    void RemoveAt(int index);
    void SortByName(bool ascending);
    void SortByPrice(bool ascending);
    IEnumerable<T> GetAllByName(string name);
    IEnumerable<T> GetAllByPrice(decimal price);
    public int GetAdditionOrder(IName item);
    T this[int index] { get; set; }
    public int GetAdditionOrderAt(int index);
    IEnumerable<T> GetReverseOrder();
    IEnumerable<T> GetItemsWithSubstring(string substring);
    IEnumerable<T> GetOrderedByName();
    IEnumerable<T> GetOrderedByPrice();
    void SerializeJson(string fileName);
    IContainer<T> DeserializeFromFileJson(string fileName);
}

public interface IBinarySerializable
{
    void WriteToBinary(BinaryWriter writer);
    void ReadFromBinary(BinaryReader reader);
}