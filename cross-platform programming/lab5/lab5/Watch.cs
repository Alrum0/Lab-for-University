namespace lab5;

public class Watch : Product
{
    public string Mechanism { get; set; }
    public string Brand { get; set; }
    
    public Watch() : base() {Mechanism = "Кварцовий"; Brand = "Невідомий бренд";}

    public Watch(string name, decimal price, string mechanism, string brand)
        : base(name, price)
    {
        this.Mechanism = mechanism;
        this.Brand = brand;
    }
    public override string ToString() { return $"{base.ToString()}, Механізм: {Mechanism}, Бренд: {Brand}"; }
}