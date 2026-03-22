namespace SortingProject.Interfaces
{
    // Sort zwraca nową List<T> zamiast modyfikować oryginalną.
    public interface ISortingAlgorithm
    {
        List<T> Sort<T>(List<T> items) where T : IMyComparable;
    }
}
    // "where T : IMyComparable" to OGRANICZENIE GENERYCZNE.
    // T może być dowolnym typem, lecz musi implementować IMyComparable.
    // Bez tego kompilator odrzuciłby wywołanie list[j].CompareTo(...) — bo skąd ma wiedzieć, że T ma tę metodę?