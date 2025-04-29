namespace lab5;

public class LinkedListContainer<T> : IContainer<T>, IEnumerable<T> where T : IName
{
    private class Node
    {
        public T Data { get; set; }
        public Node Previous { get; set; }
        public Node Next { get; set; }
        public int AdditionOrder { get; set; }
        
        public Node(T data, int additionOrder)
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
    
    public LinkedListContainer()
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
    // FfffFFFFfFFFFFFFFFFfffffFFFFFFfffff
    public int GetAdditionOrder(IName item)
    {
        Node current = head;
        while (current != null)
        {
            if (current.Data.Equals(item))
                return current.AdditionOrder;
            current = current.Next;
        }
        throw new KeyNotFoundException("Product not found in container");
    }
    public T this[int additionOrder]
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
    
    
    public T this[string name]
    {
        get
        {
            if (string.IsNullOrEmpty(name))
                throw new ArgumentException("Product name cannot be null or empty");

            Node current = head;
            while (current != null)
            {
                if (string.Equals(((IName)current.Data).Name, name, StringComparison.OrdinalIgnoreCase))
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
                if (string.Equals(((IName)current.Data).Name, name, StringComparison.OrdinalIgnoreCase))
                {
                    current.Data = value;
                    return;
                }
                current = current.Next;
            }

            throw new KeyNotFoundException($"Product with name '{name}' not found");
        }
    }
    public IEnumerable<T> GetAllByPrice(decimal price)
    {
        Node current = head;
        while (current != null)
        {
            if (current.Data.Price == price)
                yield return current.Data;
            current = current.Next;
        }
    }
    
    public IEnumerable<T> GetAllByName(string name)
    {
        Node current = head;
        while (current != null)
        {
            if (string.Equals(((IName)current.Data).Name, name, StringComparison.OrdinalIgnoreCase))
                yield return current.Data;
            current = current.Next;
        }
    }
    
    public void Add(T item)
    {
        Node newNode = new Node(item, additionCounter + 1);
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

        // Конвертуємо зв'язаний список у List
        List<Node> nodes = new List<Node>();
        Node current = head;
        while (current != null)
        {
            nodes.Add(current);
            current = current.Next;
        }
        
        if (ascending)
        {
            nodes.Sort((a, b) => a.Data.CompareTo(b.Data));
        }
        else
        {
            nodes.Sort((a, b) => b.Data.CompareTo(a.Data));
        }
        
        RebuildLinkedList(nodes);
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

        // Конвертуємо зв'язаний список у List
        List<Node> nodes = new List<Node>();
        Node current = head;
        while (current != null)
        {
            nodes.Add(current);
            current = current.Next;
        }
        
        if (ascending)
        {
            nodes.Sort((a, b) => a.Data.CompareByPrice(b.Data));
        }
        else
        {
            nodes.Sort((a, b) => b.Data.CompareByPrice(a.Data));
        }
        
        RebuildLinkedList(nodes);
    }
    
    private void RebuildLinkedList(List<Node> nodes)
    {
        head = nodes[0];
        tail = nodes[nodes.Count - 1];
        
        for (int i = 0; i < nodes.Count; i++)
        {
            nodes[i].Previous = i > 0 ? nodes[i - 1] : null;
            nodes[i].Next = i < nodes.Count - 1 ? nodes[i + 1] : null;
        }
    }
    
    public T GetAt(int index)
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
    private class NodeEnumerator : IEnumerator<T>
    {
        private Node _current;
        private readonly Node _head;
        private bool _started;

        public NodeEnumerator(Node head)
        {
            _head = head;
            Reset();
        }

        public T Current => _current.Data;

        object System.Collections.IEnumerator.Current => Current;

        public bool MoveNext()
        {
            if (!_started)
            {
                _current = _head;
                _started = true;
            }
            else
            {
                _current = _current?.Next;
            }
            return _current != null;
        }

        public void Reset()
        {
            _current = null;
            _started = false;
        }

        public void Dispose() { }
    }
    public IEnumerator<T> GetEnumerator()
    {
        return new NodeEnumerator(head);
    }

    System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
    {
        return GetEnumerator();
    }
}