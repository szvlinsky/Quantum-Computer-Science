using SortingProject.Interfaces;

namespace SortingProject.SortingAlgorithms
{
    // Złożoność czasowa: O(n log n)
    public class MergeSort : ISortingAlgorithm
    {
        public List<T> Sort<T>(List<T> items) where T : IMyComparable
        {
            // Przypadek bazowy
            if (items.Count <= 1)
                return new List<T>(items);

            int mid = items.Count / 2;

            // GetRange(start, count) metoda List<T>, zwraca nową listę.
            var left = Sort(items.GetRange(0, mid));
            var right = Sort(items.GetRange(mid, items.Count - mid));

            return Merge(left, right);
        }
        private static List<T> Merge<T>(List<T> left, List<T> right) where T : IMyComparable
        {
            // Alokacja rozmiaru z góry
            var result = new List<T>(left.Count + right.Count);
            int i = 0, j = 0;

            while (i < left.Count && j < right.Count)
            {
                if (left[i].CompareTo(right[j]) <= 0)
                    result.Add(left[i++]);
                else
                    result.Add(right[j++]);
            }
            while (i < left.Count) result.Add(left[i++]);
            while (j < right.Count) result.Add(right[j++]);

            return result;
        }
    }
}