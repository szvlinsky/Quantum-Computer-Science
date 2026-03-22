using SortingProject.Interfaces;
using SortingProject.Models;
using SortingProject.SortingAlgorithms;

ISortingAlgorithm bubbleSort = new BubbleSort();
ISortingAlgorithm mergeSort = new MergeSort();

var people = new List<Person>
{
    new Person("Robert","Lewandowski","90876540000", 37),
    new Person("Adam","Małysz","76500000987", 48),
    new Person("Arkadiusz", "Milik", "92345000001", 32),
    new Person("Jan","Brzechwa","57000056789", 67),
    new Person("Jan","Bednarek","90000890123", 29),
};

// OSOBY po imieniu
Console.WriteLine("BubbleSort - osoby po imieniu");
foreach (var p in bubbleSort.Sort(people))
    Console.WriteLine(p);

Console.WriteLine("\nMergeSort — osoby po imieniu");
foreach (var p in mergeSort.Sort(people))
    Console.WriteLine(p);

// OSOBY po wieku
var peopleByAge = people.Select(p => new PersonByAge(p)).ToList();

Console.WriteLine("\nBubbleSort — osoby po wieku");
foreach (var p in bubbleSort.Sort(peopleByAge))
    Console.WriteLine(p);

Console.WriteLine("\nMergeSort — osoby po wieku");
foreach (var p in mergeSort.Sort(peopleByAge))
    Console.WriteLine(p);

// PRODUKTY po cenie
var products = new List<Product>
{
    new Product("Telefon",3000.00m),
    new Product("Buty",10999.00m),
    new Product("Koszula",99.99m),
    new Product("Guzik",1.50m),
    new Product("Tablet",1000.00m),
};

Console.WriteLine("\nBubbleSort — produkty po cenie");
foreach (var p in bubbleSort.Sort(products))
    Console.WriteLine(p);

Console.WriteLine("\nMergeSort — produkty po cenie");
foreach (var p in mergeSort.Sort(products))
    Console.WriteLine(p);