namespace lab5;

public class SportWatch : Watch
{
    public int WaterResistance { get; set; }
    public bool SmartFeatures { get; set; }

    public SportWatch() : base() { WaterResistance = 50; SmartFeatures = false; }

    public SportWatch(string name, decimal price, string mechanism, string brand, int waterResistance, bool smartFeatures)
        : base(name, price, mechanism, brand)
    {
        this.WaterResistance = waterResistance;
        this.SmartFeatures = smartFeatures;
    }
    public override string ToString() { return $"{base.ToString()}, Водозахист: {WaterResistance} м, Розумні функції: {ToYesNo(SmartFeatures)}"; }
    
    private string ToYesNo(bool value) => value ? "Так" : "Ні";
}