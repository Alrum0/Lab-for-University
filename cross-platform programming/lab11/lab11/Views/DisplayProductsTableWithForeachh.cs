namespace lab5.Views;

public class DisplayProductsTableWithForeachh
{
    const string BLACK = "\u001b[30m";
    const string YELLOW = "\u001b[33m";
    const string MAGENTA = "\u001b[35m";
    const string WHITE = "\u001b[37m";
    const string BRIGHT_BLACK = "\u001b[90m";
    const string BRIGHT_RED = "\u001b[91m";
    const string BRIGHT_GREEN = "\u001b[92m";
    const string BRIGHT_YELLOW = "\u001b[93m";
    const string BRIGHT_BLUE = "\u001b[94m";
    const string BRIGHT_MAGENTA = "\u001b[95m";
    const string BRIGHT_CYAN = "\u001b[96m";     
    const string BRIGHT_WHITE = "\u001b[97m";
    const string RESET = "\u001b[0m";
    const string RED = "\u001b[31m";
    const string TABUL = "\t\t\t\t\t\t\t";
    
    public static void DisplayProductsTableWithForeach(IContainer<IName> products)
    {
        var currentProducts = new List<IName>(products);
        
        
        if (products.Count == 0)
        {
            Console.WriteLine($"{RED}\nНемає доданих товарів.{RESET}");
            return;
        }
        
        const int col1Width = 6;
        const int col2Width = 20;
        const int col3Width = 10;
        const int col4Width = 20;
        const int col5Width = 15;
        const int col6Width = 15;
        const int col7Width = 15;
        const int col8Width = 15;
        const int col9Width = 16;
        
        // border
        
        string separator = new string('-', 
            col1Width + col2Width + col3Width + col4Width + col5Width + 
            col6Width + col7Width + col8Width + col9Width + 28);

        Console.WriteLine($"\n" + separator);
        Console.WriteLine(
            $"| {$"{BRIGHT_YELLOW}№ п/п".PadRight(col1Width)} " +
            $"| {"Назва".PadRight(col2Width)} " +
            $"| {"Ціна".PadRight(col3Width)} " +
            $"| {"Тип".PadRight(col4Width)} " +
            $"| {"Механізм".PadRight(col5Width)} " +
            $"| {"Бренд".PadRight(col6Width)} " +
            $"| {"Матеріал".PadRight(col7Width)} " +
            $"| {"Водозахист".PadRight(col8Width)} " +
            $"| {"Функції ".PadRight(col9Width)} |{RESET}");
        Console.WriteLine(separator);

        int counter = 1;
        foreach (var product in currentProducts)  
        {
            string num = counter.ToString();
            string name = product.Name.Length > col2Width ? product.Name.Substring(0, col2Width-3) + "..." : product.Name;
            string price = product.Price.ToString();
            string type = "-";
            string mechanism = "-";
            string brand = "-";
            string material = "-";
            string waterResistance = "-";
            string features = "-";
            
            if (product is Watch watch)
            {
                mechanism = watch.Mechanism;
                brand = watch.Brand;
                type = "Годинник";
                
                if (watch is LuxuryWatch lw)
                {
                    type = "Люксовий";
                    material = lw.Material;
                    features = lw.LimitedEdition ? "Обмежений" : "-";
                }
                else if (watch is SportWatch sw)
                {
                    type = "Спортивний";
                    waterResistance = sw.WaterResistance.ToString() + " м";
                    features = sw.SmartFeatures ? "Так" : "-";
                }
                else if (watch is SmartWatch smw)
                {
                    type = "Смарт";
                    features = (smw.HasGps ? "GPS+" : "") + (smw.HasHeartRateMonitor ? " HR+" : "");
                    if (features == "") features = "-";
                }
            }
            else if (product is Accessory accessory)
            {
                type = accessory.Type;
                
                if (accessory is LeatherAccessory la)
                {
                    material = la.StrapMaterial;
                    features = la.HasBuckle ? "Пряжка" : "-";
                }
                else if (accessory is MetalAccessory ma)
                {
                    material = ma.MetalType;
                    features = ma.IsPolished ? "Полірований" : "-";
                }
            }
            
            mechanism = mechanism.Length > col5Width ? mechanism.Substring(0, col5Width-3) + "..." : mechanism;
            brand = brand.Length > col6Width ? brand.Substring(0, col6Width-3) + "..." : brand;
            material = material.Length > col7Width ? material.Substring(0, col7Width-3) + "..." : material;
            features = features.Length > col9Width ? features.Substring(0, col9Width-3) + "..." : features;
            
            Console.WriteLine(
                $"| {num.PadRight(col1Width)} " +
                $"| {name.PadRight(col2Width)} " +
                $"| {price.PadRight(col3Width)} " +
                $"| {type.PadRight(col4Width)} " +
                $"| {mechanism.PadRight(col5Width)} " +
                $"| {brand.PadRight(col6Width)} " +
                $"| {material.PadRight(col7Width)} " +
                $"| {waterResistance.PadRight(col8Width)} " +
                $"| {features.PadRight(col9Width)} |");
            Console.WriteLine(separator);
            
            counter++;
        }
    }
}