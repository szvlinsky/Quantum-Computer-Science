using SortingProject.Interfaces;

namespace SortingProject.Models
{
    public class Person : IMyComparable
    {
        private string firstName = string.Empty;
        private string lastName = string.Empty;
        private string pesel = string.Empty;
        private int age;

        // public string FirstName { get { return firstName; } }
        public string FirstName => firstName;
        public string LastName => lastName;
        public string Pesel => pesel;
        public int Age => age;
        public Person(string firstName, string lastName, string pesel, int age)
        {
            this.firstName = firstName;
            this.lastName = lastName;
            this.pesel = pesel;
            this.age = age;
        }
        // Najpierw porównanie imion, jeśli równe, porównanie nazwiska.
        public int CompareTo(IMyComparable other)
        {
            if (other is not Person otherPerson)
                throw new ArgumentException("Obiekt nie jest typu Person.");

            int cmp = string.Compare(firstName, otherPerson.firstName,
                                     StringComparison.OrdinalIgnoreCase); // lepsza opcja niż ToLower()

            // NORMALIZACJA do -1/0/1
            if (cmp != 0)
                return cmp < 0 ? -1 : 1;

            int cmp2 = string.Compare(lastName, otherPerson.lastName,
                                      StringComparison.OrdinalIgnoreCase);
            return cmp2 < 0 ? -1 : cmp2 > 0 ? 1 : 0;
        }

        // Nadpisanie ToString() daje czytelny output Console.WriteLine(person)
        public override string ToString() =>
            $"{firstName} {lastName} (PESEL: {pesel}, wiek: {age})";
    }
}