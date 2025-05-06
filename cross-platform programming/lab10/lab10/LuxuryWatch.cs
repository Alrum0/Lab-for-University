namespace lab5;

public class LuxuryWatch : Watch, IName<LuxuryWatch>
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
}