namespace lab5;

public interface IName : IComparable
{
    string Name { get; set; }
    decimal Price { get; set; }

    public int CompareByPrice(object obj);
    public int CompareTo(object obj);
}