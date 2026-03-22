namespace SortingProject.Interfaces
{
    public interface IMyComparable
    {
        // Kontrakt: zwróć -1 (mniejszy), 0 (równy), 1 (większy)
        int CompareTo(IMyComparable other);
    }
}