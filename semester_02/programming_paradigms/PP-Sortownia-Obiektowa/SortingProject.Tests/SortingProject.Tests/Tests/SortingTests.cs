using Microsoft.VisualStudio.TestTools.UnitTesting;
using SortingProject.Models;
using SortingProject.SortingAlgorithms;

namespace SortingProject.Tests
{
    [TestClass]
    public class SortingTests
    {
        // SORTOWANIE PO IMIENIU
        [TestMethod]
        public void BubbleSort_SortsByFirstName()
        {
            var people = new List<Person>
            {
                new Person("Robert",    "Lewandowski", "9", 37),
                new Person("Adam",      "Małysz",      "1", 48),
                new Person("Arkadiusz", "Milik",       "7", 32),
            };

            var sorted = new BubbleSort().Sort(people);

            // Assert.AreEqual(oczekiwana, rzeczywista)
            Assert.AreEqual("Adam", sorted[0].FirstName);
            Assert.AreEqual("Arkadiusz", sorted[1].FirstName);
            Assert.AreEqual("Robert", sorted[2].FirstName);
        }

        [TestMethod]
        public void MergeSort_SortsByFirstName()
        {
            var people = new List<Person>
            {
                new Person("Robert", "Lewandowski", "9", 37),
                new Person("Adam", "Małysz","1", 48),
                new Person("Arkadiusz", "Milik","7", 32)
            };

            var sorted = new MergeSort().Sort(people);

            Assert.AreEqual("Adam", sorted[0].FirstName);
            Assert.AreEqual("Arkadiusz", sorted[1].FirstName);
            Assert.AreEqual("Robert", sorted[2].FirstName);
        }

        // SORTOWANIE PO NAZWISKU
        [TestMethod]
        public void BubbleSort_SameFirstName_SortsByLastName()
        {
            var people = new List<Person>
            {
                new Person("Jan", "Wiśniewski", "3", 40),
                new Person("Jan", "Bednarek",   "1", 29),
                new Person("Jan", "Kowalski",   "2", 35),
            };

            var sorted = new BubbleSort().Sort(people);

            Assert.AreEqual("Bednarek", sorted[0].LastName);
            Assert.AreEqual("Kowalski", sorted[1].LastName);
            Assert.AreEqual("Wiśniewski", sorted[2].LastName);
        }

        [TestMethod]
        public void MergeSort_SameFirstName_SortsByLastName()
        {
            var people = new List<Person>
            {
                new Person("Jan", "Wiśniewski", "3", 40),
                new Person("Jan", "Bednarek",   "1", 29),
                new Person("Jan", "Kowalski",   "2", 35),
            };

            var sorted = new MergeSort().Sort(people);

            Assert.AreEqual("Bednarek", sorted[0].LastName);
            Assert.AreEqual("Kowalski", sorted[1].LastName);
            Assert.AreEqual("Wiśniewski", sorted[2].LastName);
        }

        // SORTOWANIE PO WIEKU
        // (PersonByAge jest wrapperem, po posortowaniu zwraca List<PersonByAge>)
        [TestMethod]
        public void BubbleSort_PersonByAge_SortsByAge()
        {
            var people = new List<Person>
            {
                new Person("Robert",    "Lewandowski", "9", 37),
                new Person("Adam",      "Małysz",      "1", 48),
                new Person("Arkadiusz", "Milik",       "7", 32),
                new Person("Jan",       "Brzechwa",    "6", 67),
                new Person("Jan",       "Bednarek",    "5", 29),
            };

            // List<PersonByAge> — każdy element to wrapper opakowujący Person.
            var byAge = people.Select(p => new PersonByAge(p)).ToList();
            var sorted = new BubbleSort().Sort(byAge);

            // .Inner to oryginalny obiekt Person przechowywany wewnątrz wrappera.
            Assert.AreEqual(29, sorted[0].Inner.Age);
            Assert.AreEqual(32, sorted[1].Inner.Age);
            Assert.AreEqual(37, sorted[2].Inner.Age);
            Assert.AreEqual(48, sorted[3].Inner.Age);
            Assert.AreEqual(67, sorted[4].Inner.Age);
        }

        // SORTOWANIE PRODUKTÓW PO CENIE
        [TestMethod]
        public void MergeSort_SortsByPrice()
        {
            var products = new List<Product>
            {
                new Product("Telefon", 3000.00m),
                new Product("Zapałki", 1.50m),
                new Product("Tablet", 1000.00m),
            };

            var sorted = new MergeSort().Sort(products);

            Assert.AreEqual(1.50m, sorted[0].Price);
            Assert.AreEqual(1000.00m, sorted[1].Price);
            Assert.AreEqual(3000.00m, sorted[2].Price);
        }

        // TEST GRANICZNY
        [TestMethod]
        public void CompareTo_ThrowsWhenWrongType()
        {
            var person = new Person("Jan", "Kowalski", "1", 30);
            var product = new Product("Laptop", 2500m);

            try
            {
                person.CompareTo(product);
                Assert.Fail("Oczekiwano ArgumentException, ale nie zostało rzucone.");
            }
            catch (ArgumentException)
            {
                // Pusta klauzula catch - test poprawny
            }
        }
    }
}