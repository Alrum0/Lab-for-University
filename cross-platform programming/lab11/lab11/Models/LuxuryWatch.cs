namespace lab5;

[Serializable]
public class LuxuryWatch : Watch, IName<LuxuryWatch>, IBinarySerializable
{
    public string Material { get; set; }
    public bool LimitedEdition { get; set; }
    
    public LuxuryWatch() : base()
    {
        Material = "Золото"; 
        LimitedEdition = false; 
    }
    public LuxuryWatch(string name, decimal price, string mechanism, string brand, string material, bool limitedEdition)
        : base(name, price, mechanism, brand)
    {
        if (string.IsNullOrEmpty(brand))
            throw new InvalidProductDataException("Матеріал не може бути порожнім");
        
        this.Material = material;
        this.LimitedEdition = limitedEdition;
    }
    public override string ToString() { return $"{base.ToString()}, Матеріал: {Material}, Обмежений випуск: {ToYesNo(LimitedEdition)}"; }
    
    private string ToYesNo(bool value) => value ? "Так" : "Ні";

    public new void WriteToBinary(BinaryWriter writer)
    {
        base.WriteToBinary(writer);
        writer.Write(Material ?? "");
        writer.Write(LimitedEdition);
    }

    public new void ReadFromBinary(BinaryReader reader)
    {
        base.ReadFromBinary(reader);
        Material = reader.ReadString();
        LimitedEdition = reader.ReadBoolean();
    }
}