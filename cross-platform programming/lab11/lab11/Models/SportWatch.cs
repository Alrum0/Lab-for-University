namespace lab5;

[Serializable]
public class SportWatch : Watch, IName<SportWatch>, IBinarySerializable
{
    public int WaterResistance { get; set; }
    public bool SmartFeatures { get; set; }

    public SportWatch() : base() { WaterResistance = 50; SmartFeatures = false; }

    public SportWatch(string name, decimal price, string mechanism, string brand, int waterResistance, bool smartFeatures)
        : base(name, price, mechanism, brand)
    {
        if (waterResistance < 0 || waterResistance > 1000)
            throw new InvalidProductDataException(
                "Неприпустиме значення водозахисту (по доброму має бути від 0 до 1000)");
        
        this.WaterResistance = waterResistance;
        this.SmartFeatures = smartFeatures;
    }
    public override string ToString() { return $"{base.ToString()}, Водозахист: {WaterResistance} м, Розумні функції: {ToYesNo(SmartFeatures)}"; }
    
    private string ToYesNo(bool value) => value ? "Так" : "Ні";
    
    public new void WriteToBinary(BinaryWriter writer)
    {
        base.WriteToBinary(writer); 
        writer.Write(WaterResistance);
        writer.Write(SmartFeatures);
    }

    public new void ReadFromBinary(BinaryReader reader)
    {
        base.ReadFromBinary(reader); 
        WaterResistance = reader.ReadInt32();
        SmartFeatures = reader.ReadBoolean();
    }
}