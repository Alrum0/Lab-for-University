namespace lab5;

public class Product
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
    public override string ToString() { return $"Назва: {Name}, Ціна: {Price}"; }
}