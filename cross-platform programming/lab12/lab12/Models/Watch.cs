namespace lab5;

[Serializable]
public class Watch : Product, IName<Watch>, IBinarySerializable
{
    public string Mechanism { get; set; }
    public string Brand { get; set; }

    public Watch() : base()
    {
        Mechanism = "Кварцовий"; 
        Brand = "Невідомий бренд";
    }

    public Watch(string name, decimal price, string mechanism, string brand)
        : base(name, price)
    {
        if (string.IsNullOrEmpty(mechanism))
            throw new InvalidProductDataException("Тип механізму не може бути порожнім.");
        if (string.IsNullOrEmpty(brand))
            throw new InvalidProductDataException("Бренд не може бути порожнім");
        
        this.Mechanism = mechanism;
        this.Brand = brand;
    }
    public override string ToString() { return $"{base.ToString()}, Механізм: {Mechanism}, Бренд: {Brand}"; }
    
    public new void WriteToBinary(BinaryWriter writer)
    {
        base.WriteToBinary(writer); 
        writer.Write(Mechanism ?? "");
        writer.Write(Brand ?? "");
    }

    public new void ReadFromBinary(BinaryReader reader)
    {
        base.ReadFromBinary(reader);
        Mechanism = reader.ReadString();
        Brand = reader.ReadString();
    }
}