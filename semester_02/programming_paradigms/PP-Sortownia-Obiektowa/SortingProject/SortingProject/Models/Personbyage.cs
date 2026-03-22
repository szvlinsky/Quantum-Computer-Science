using SortingProject.Interfaces;
namespace SortingProject.Models
{
    public class PersonByAge : IMyComparable
    {
        // Inner - przechowuje referencję do oryginalnego obiektu Person.
        // Wrapper/dekorator - opakowanie istniejącego obiekt, nie modyfikując jego klasy.
        public Person Inner { get; }

        public PersonByAge(Person person)
        {
            Inner = person;
        }
        public int CompareTo(IMyComparable other)
        {
            if (other is not PersonByAge otherWrapper)
                throw new ArgumentException("Obiekt nie jest typu PersonByAge.");

            // Porównanie int bez ryzyka overflow.
            int diff = Inner.Age - otherWrapper.Inner.Age;
            return diff < 0 ? -1 : diff > 0 ? 1 : 0;
        }
        // Spójny output
        public override string ToString() => Inner.ToString() ?? string.Empty;
    }
}