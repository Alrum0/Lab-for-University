namespace lab5;

public class Container
{
    private class Node
    {
        public Product Data { get; set; }
        public Node Previous { get; set; }
        public Node Next { get; set; }
        public int AdditionOrder { get; set; }
        
        public Node(Product data, int additionOrder)
        {
            Data = data;
            Previous = null;
            Next = null;
            AdditionOrder = additionOrder;
        }
    }

    private Node head;
    private Node tail;
    private int count;
    private int additionCounter;
    
    public Container()
    {
        head = null;
        tail = null;
        count = 0;
        additionCounter = 0;
    }

    public int GetAdditionOrderAt(int index)
    {
        return GetNodeAt(index).AdditionOrder;
    }
    
    public int GetAdditionOrder(Product product)
    {
        Node current = head;
        while (current != null)
        {
            if (current.Data == product)
                return current.AdditionOrder;
            current = current.Next;
        }
        throw new KeyNotFoundException("Product not found in container");
    }
    public Product this[int additionOrder]
    {
        get
        {
            if (additionOrder < 1 || additionOrder > count)
                throw new IndexOutOfRangeException("Invalid addition order");

            Node current = head;
            while (current != null)
            {
                if (current.AdditionOrder == additionOrder)
                    return current.Data;
                current = current.Next;
            }

            throw new KeyNotFoundException($"No product with addition order {additionOrder} found");
        }
        set
        {
            if (additionOrder < 1 || additionOrder > count)
                throw new IndexOutOfRangeException("Invalid addition order");

            Node current = head;
            while (current != null)
            {
                if (current.AdditionOrder == additionOrder)
                {
                    current.Data = value;
                    return;
                }
                current = current.Next;
            }

            throw new KeyNotFoundException($"No product with addition order {additionOrder} found");
        }
    }
    
    //індексація за імʼям
    
    
    public Product this[string name]
    {
        get
        {
            if (string.IsNullOrEmpty(name))
                throw new ArgumentException("Product name cannot be null or empty");

            Node current = head;
            while (current != null)
            {
                if (string.Equals(current.Data.Name, name, StringComparison.OrdinalIgnoreCase))
                    return current.Data;
                current = current.Next;
            }

            throw new KeyNotFoundException($"Product with name '{name}' not found");
        }
        set
        {
            if (string.IsNullOrEmpty(name))
                throw new ArgumentException("Product name cannot be null or empty");

            Node current = head;
            while (current != null)
            {
                if (string.Equals(current.Data.Name, name, StringComparison.OrdinalIgnoreCase))
                {
                    current.Data = value;
                    return;
                }
                current = current.Next;
            }

            throw new KeyNotFoundException($"Product with name '{name}' not found");
        }
    }

    //індексація за ціною
    
    public Product this[decimal price]
    {
        get
        {
            Node current = head;
            while (current != null)
            {
                if (current.Data.Price == price)
                    return current.Data;
                current = current.Next;
            }

            throw new KeyNotFoundException($"No product with price {price} found");
        }
    }
    
    public IEnumerable<Product> GetAllByPrice(decimal price)
    {
        Node current = head;
        while (current != null)
        {
            if (current.Data.Price == price)
                yield return current.Data;
            current = current.Next;
        }
    }
    
    public IEnumerable<Product> GetAllByName(string name)
    {
        Node current = head;
        while (current != null)
        {
            if (string.Equals(current.Data.Name, name, StringComparison.OrdinalIgnoreCase))
                yield return current.Data;
            current = current.Next;
        }
    }
    
    public void Add(Product product)
    {
        Node newNode = new Node(product, additionCounter + 1);
        additionCounter++;
        
        if (head == null)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail.Next = newNode;
            newNode.Previous = tail;
            tail = newNode;
        }
        count++;
    }
    
    
    //сортування вмісту контейнеру
    public void SortByName(bool ascending = true)
    {
        if (count <= 1) return;
        
        bool swapped;
        do
        {
            swapped = false;
            Node current = head;
            
            while (current != null && current.Next != null)
            {
                int comparison = string.Compare(current.Data.Name, current.Next.Data.Name, StringComparison.OrdinalIgnoreCase);
                bool shouldSwap = ascending ? comparison > 0 : comparison < 0;
                
                if (shouldSwap)
                {
                    SwapNodes(current, current.Next);
                    swapped = true;
                }
                else
                {
                    current = current.Next;
                }
            }
        } while (swapped);
    }
    
    //видалення з контейнеру товару
    
    public void RemoveAt(int index)
    {
        if (index < 0 || index >= count)
            throw new IndexOutOfRangeException();
        
        Node current = GetNodeAt(index);
        
        if (current.Previous != null)
            current.Previous.Next = current.Next;
        else
            head = current.Next;
            
        if (current.Next != null)
            current.Next.Previous = current.Previous;
        else
            tail = current.Previous;
            
        count--;
    }
    
    //сортування по колонці прайсу
    
    public void SortByPrice(bool ascending = true)
    {
        if (count <= 1) return;
        
        bool swapped;
        do
        {
            swapped = false;
            Node current = head;
            
            while (current != null && current.Next != null)
            {
                bool shouldSwap = ascending 
                    ? current.Data.Price > current.Next.Data.Price 
                    : current.Data.Price < current.Next.Data.Price;
                
                if (shouldSwap)
                {
                    SwapNodes(current, current.Next);
                    swapped = true;
                }
                else
                {
                    current = current.Next;
                }
            }
        } while (swapped);
    }
    
    public Product GetAt(int index)
    {
        return GetNodeAt(index).Data;
    }
    
    public int Count => count;
    
    private Node GetNodeAt(int index)
    {
        if (index < 0 || index >= count)
            throw new IndexOutOfRangeException();
            
        Node current;
        if (index < count / 2)
        {
            current = head;
            for (int i = 0; i < index; i++)
                current = current.Next;
        }
        else
        {
            current = tail;
            for (int i = count - 1; i > index; i--)
                current = current.Previous;
        }
        return current;
    }
    
    //функція сортування
    
    private void SwapNodes(Node a, Node b)
    {
        Product temp = a.Data;
        a.Data = b.Data;
        b.Data = temp;
    }
    
    //перевантажена функція toString()
    
    public override string ToString()
    {
        string result = "";
        Node current = head;
        while (current != null)
        {
            result += current.Data.ToString() + "\n";
            current = current.Next;
        }
        return result;
    }
}