namespace lab5;

public class Product
{
    public string Name { get; set; } 
    public decimal Price { get; set; }
    
    public Product() { Name = "Невідомий товар"; Price = 0; }
    public Product(string name, decimal price) { this.Name = name; this.Price = price; }
    public override string ToString() { return $"Назва: {Name}, Ціна: {Price}"; }
}