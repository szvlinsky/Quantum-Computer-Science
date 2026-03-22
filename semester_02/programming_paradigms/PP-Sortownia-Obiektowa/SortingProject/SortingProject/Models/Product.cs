using SortingProject.Interfaces;

namespace SortingProject.Models
{
    // Product implementuje ten sam interfejs IMyComparable co Person.
    public class Product : IMyComparable
    {
        private string name = string.Empty;
        private decimal price;
        public string Name => name;
        public decimal Price => price;
        public Product(string name, decimal price)
        {
            this.name = name;
            this.price = price;
        }

        // Sortowanie po cenie rosnąco, -1/0/1 zgodnie z kontraktem.
        public int CompareTo(IMyComparable other)
        {
            if (other is not Product otherProduct)
                throw new ArgumentException("Obiekt nie jest typu Product.");

            return price < otherProduct.price ? -1
                 : price > otherProduct.price ? 1
                 : 0;
        }

        public override string ToString() => $"{name} — {price:C}";
    }
}