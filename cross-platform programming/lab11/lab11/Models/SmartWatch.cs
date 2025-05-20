namespace lab5;

[Serializable]
public class SmartWatch : Watch, IName<SmartWatch>, IBinarySerializable
{
    public bool HasGps { get; set; }
    public bool HasHeartRateMonitor { get; set; }
    
    public SmartWatch() : base() { HasGps = false; HasHeartRateMonitor = false; }
    public SmartWatch(string name, decimal price, string mechanism, string brand, bool hasGps, bool hasHeartRateMonitor)
        : base(name, price, mechanism, brand)
    {
        this.HasGps = hasGps;
        this.HasHeartRateMonitor = hasHeartRateMonitor;
    }

    public override string ToString()
    {
        return $"{base.ToString()}, GPS: {ToYesNo(HasGps)}, Монітор серця: {ToYesNo(HasHeartRateMonitor)}";
    }
    
    private string ToYesNo(bool value) => value ? "Так" : "Ні";
    
    public new void WriteToBinary(BinaryWriter writer)
    {
        base.WriteToBinary(writer);       
        writer.Write(HasGps);
        writer.Write(HasHeartRateMonitor);
    }

    public new void ReadFromBinary(BinaryReader reader)
    {
        base.ReadFromBinary(reader);     
        HasGps = reader.ReadBoolean();
        HasHeartRateMonitor = reader.ReadBoolean();
    }
}