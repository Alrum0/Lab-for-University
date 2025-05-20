namespace lab5;

public class InvalidProductDataException : Exception
{
    public InvalidProductDataException(string message) : base(message) { }
}