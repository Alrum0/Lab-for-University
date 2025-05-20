namespace lab5;

[Serializable]
public class Accessory : Product, IName<Accessory>, IBinarySerializable
{
    public string Type { get; set; }

    public Accessory() : base()
    {
        Type = "Аксесуар";
    }

    public Accessory(string name, decimal price, string type) : base(name, price)
    {
        if (string.IsNullOrEmpty(type))
            throw new InvalidProductDataException("Тип аксесуару не може бути порожнім");
        
        this.Type = type;
    }

    public override string ToString()
    {
        return $"{base.ToString()}, Тип: {Type}";
    }
    
    
    public new void WriteToBinary(BinaryWriter writer)
    {
        base.WriteToBinary(writer); 
        writer.Write(Type ?? "");
    }

    public new void ReadFromBinary(BinaryReader reader)
    {
        base.ReadFromBinary(reader); 
        Type = reader.ReadString();
    }
}