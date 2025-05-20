namespace lab5;

[Serializable]
public class MetalAccessory : Accessory, IName<MetalAccessory>, IBinarySerializable
{
    public string MetalType { get; set; }  
    public bool IsPolished { get; set; }   

    public MetalAccessory() : base()
    {
        MetalType = "Нержавіюча сталь";
        IsPolished = true;
    }

    public MetalAccessory(string name, decimal price, string type, string metalType, bool isPolished)
        : base(name, price, type)
    {
        this.MetalType = metalType;
        this.IsPolished = isPolished;
    }

    public override string ToString()
    {
        return $"{base.ToString()}, Тип металу: {MetalType}, Полірований: {ToYesNo(IsPolished)}";
    }

    private string ToYesNo(bool value) => value ? "Так" : "Ні";
    
    public new void WriteToBinary(BinaryWriter writer)
    {
        base.WriteToBinary(writer);       
        writer.Write(MetalType ?? "");
        writer.Write(IsPolished);
    }

    public new void ReadFromBinary(BinaryReader reader)
    {
        base.ReadFromBinary(reader);   
        MetalType = reader.ReadString();
        IsPolished = reader.ReadBoolean();
    }
}