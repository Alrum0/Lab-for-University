namespace lab5;

public class Accessory : Product
{
    public string Type { get; set; }

    public Accessory() : base()
    {
        Type = "Аксесуар";
    }

    public Accessory(string name, decimal price, string type) : base(name, price)
    {
        this.Type = type;
    }

    public override string ToString()
    {
        return $"{base.ToString()}, Тип: {Type}";
    }
}