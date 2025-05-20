namespace lab5;

[Serializable]
public class LeatherAccessory : Accessory, IName<LeatherAccessory>, IBinarySerializable
{
    public string StrapMaterial { get; set; }
    public bool HasBuckle { get; set; }        

    public LeatherAccessory() : base()
    {
        StrapMaterial = "Шкіра";
        HasBuckle = true;
    }

    public LeatherAccessory(string name, decimal price, string type, string strapMaterial, bool hasBuckle)
        : base(name, price, type)
    {
        if (string.IsNullOrEmpty(strapMaterial))
            throw new InvalidProductDataException("Матеріал ремінця не може бути порожнім");
        
        this.StrapMaterial = strapMaterial;
        this.HasBuckle = hasBuckle;
    }

    public override string ToString()
    {
        return $"{base.ToString()}, Матеріал ремінця: {StrapMaterial}, Має пряжку: {ToYesNo(HasBuckle)}";
    }

    private string ToYesNo(bool value) => value ? "Так" : "Ні";

    public new void WriteToBinary(BinaryWriter writer)
    {
        base.WriteToBinary(writer);
        writer.Write(StrapMaterial ?? "");
        writer.Write(HasBuckle);
    }

    public new void ReadFromBinary(BinaryReader reader)
    {
        base.ReadFromBinary(reader);      
        StrapMaterial = reader.ReadString();
        HasBuckle = reader.ReadBoolean();
    }
}