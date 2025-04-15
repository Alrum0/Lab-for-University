namespace lab5;

public class MetalAccessory : Accessory
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
        if (string.IsNullOrEmpty(MetalType))
            throw new InvalidProductDataException("Тип металу не може бути порожнім");
        
        this.MetalType = metalType;
        this.IsPolished = isPolished;
    }

    public override string ToString()
    {
        return $"{base.ToString()}, Тип металу: {MetalType}, Полірований: {ToYesNo(IsPolished)}";
    }

    private string ToYesNo(bool value) => value ? "Так" : "Ні";
}