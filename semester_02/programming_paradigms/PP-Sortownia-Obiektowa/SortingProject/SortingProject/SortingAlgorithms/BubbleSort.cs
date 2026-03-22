using SortingProject.Interfaces;
namespace SortingProject.SortingAlgorithms
{
    // BubbleSort implementuje ISortingAlgorithm
    // Złożoność czasowa: O(n²)
    public class BubbleSort : ISortingAlgorithm
    {
        public List<T> Sort<T>(List<T> items) where T : IMyComparable
        {
            // new List<T>(items) tworzy płytką kopię (shallow copy) — kopiuje referencje do obiektów, nie same obiekty.
            var list = new List<T>(items);

            int n = list.Count;
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    // CompareTo zwraca >0 gdy list[j] jest "większy" niż list[j+1].
                    if (list[j].CompareTo(list[j + 1]) > 0)
                    {
                        T temp = list[j];
                        list[j] = list[j + 1];
                        list[j + 1] = temp;
                    }
                }
            }
            return list;
        }
    }
}