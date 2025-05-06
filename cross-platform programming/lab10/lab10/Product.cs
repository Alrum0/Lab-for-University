namespace lab5;

public class Product : IName, IName<Product>
{
    public string Name { get; set; } 
    public decimal Price { get; set; }
    
    public Product() { Name = "Невідомий товар"; Price = 0; }

    public Product(string name, decimal price)
    {

        if (string.IsNullOrWhiteSpace(name))
            throw new InvalidProductDataException("Назва товару не може бути порожньою");
        if (price < 0)
            throw new InvalidProductDataException("Ціна товару не може бути відємною");
        
        
        this.Name = name;
        this.Price = price;
    }

    public int CompareTo(object obj)
    {
        if (obj == null) return 1;

        if (obj is IName other)
        {
            return StringComparer.OrdinalIgnoreCase.Compare(this.Name, other.Name);
        }

        throw new InvalidProductDataException("Object is not an IName");
    }

    public int CompareByPrice(object obj)
    {
        if (obj == null) return 1;
        
        if ( obj is IName other)
        {
            return StringComparer.OrdinalIgnoreCase.Compare(this.Price, other.Price);
        }
        throw new InvalidProductDataException("Object is not an IName");
    }
    
    
    public override string ToString() { return $"Назва: {Name}, Ціна: {Price}"; }
}