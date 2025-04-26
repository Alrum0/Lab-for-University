namespace lab5;

public class SportWatch : Watch
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
}