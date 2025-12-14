#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define LIMIT 60.0

void selection_sort(int *A, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int tmp = A[i];
            A[i] = A[min_idx];
            A[min_idx] = tmp;
        }
    }
}

void insert_sort(int *A, int n) {
    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

void bubble_sort(int *A, int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                int t = A[j];
                A[j] = A[j + 1];
                A[j + 1] = t;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

void merge(int *A, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }

    while (i < n1)
        A[k++] = L[i++];

    while (j < n2)
        A[k++] = R[j++];

    free(L);
    free(R);
}

void merge_sort_rec(int *A, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_rec(A, left, mid);
        merge_sort_rec(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}

void merge_sort(int *A, int n) {
    merge_sort_rec(A, 0, n - 1);
}

void quick_sort_rec(int *A, int left, int right) {
    int i = left, j = right;
    int pivot = A[left + (right - left) / 2];

    while (i <= j) {
        while (A[i] < pivot) i++;
        while (A[j] > pivot) j--;

        if (i <= j) {
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
            i++;
            j--;
        }
    }

    if (left < j)  quick_sort_rec(A, left, j);
    if (i < right) quick_sort_rec(A, i, right);
}

void quick_sort(int *A, int n) {
    quick_sort_rec(A, 0, n - 1);
}

void count_sort(int *A, int n, int max_val) {
    int *count = calloc(max_val + 1, sizeof(int));
    if (!count) return;

    for (int i = 0; i < n; i++)
        count[A[i]]++;

    int idx = 0;
    for (int v = 0; v <= max_val; v++) {
        while (count[v]--) {
            A[idx++] = v;
        }
    }

    free(count);
}

void count_sort_100(int *A, int n) {
    count_sort(A, n, 100);
}

void count_sort_n(int *A, int n) {
    count_sort(A, n, n);
}

void fill_sorted_inc(int *A, int n) {
    for (int i = 0; i < n; i++) A[i] = i + 1;
}

void fill_sorted_dec(int *A, int n) {
    for (int i = 0; i < n; i++) A[i] = n - i;
}

void fill_random(int *A, int n, int max_val) {
    for (int i = 0; i < n; i++)
        A[i] = rand() % (max_val + 1);
}

void copy_array(int *src, int *dst, int n) {
    for (int i = 0; i < n; i++) dst[i] = src[i];
}

void print_array(int *A, int n) {
    for (int i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\n");
}

double measure(void (*sort)(int*, int), int *A, int n) {
    clock_t start = clock();
    sort(A, n);
    clock_t stop = clock();
    return (stop - start) / (double)CLOCKS_PER_SEC;
}

int main() {
    srand((unsigned) time(NULL));

    int select_limit_inc  = 5;
    int select_limit_rand = 5;
    int select_limit_dec  = 5;

    int insert_limit_inc  = 10;
    int insert_limit_rand = 5;
    int insert_limit_dec  = 5;

    int bubble_limit_inc  = 10;
    int bubble_limit_rand = 5;
    int bubble_limit_dec  = 5;

    int merge_limit_inc  = 10;
    int merge_limit_rand = 10;
    int merge_limit_dec  = 10;

    int quick_limit_inc  = 10;
    int quick_limit_rand = 10;
    int quick_limit_dec  = 10;

    int count_limit_inc  = 10;
    int count_limit_rand = 10;
    int count_limit_dec  = 10;

    for (int k = 1; k <= 8; k++) {

        int n = 1;

        for (int i = 0; i < k; i++) n *= 10;
        printf("\nrozmiar: 10^%d\n", k);

        for (int type = 0; type < 3; type++) {

            if (type == 0) printf("niemalejaco:\n");
            if (type == 1) printf("losowo:\n");
            if (type == 2) printf("nierosnaco:\n");

            int *ins_lim, *bub_lim, *sel_lim, *mer_lim, *qs_lim, *ct_lim;
            if (type == 0) { ins_lim = &insert_limit_inc;  bub_lim = &bubble_limit_inc; sel_lim = &select_limit_inc; 
                mer_lim = &merge_limit_inc; qs_lim = &quick_limit_inc; ct_lim = &count_limit_inc;}
            if (type == 1) { ins_lim = &insert_limit_rand; bub_lim = &bubble_limit_rand; sel_lim = &select_limit_rand;
                mer_lim = &merge_limit_rand; qs_lim = &quick_limit_rand; ct_lim = &count_limit_rand;}
            if (type == 2) { ins_lim = &insert_limit_dec;  bub_lim = &bubble_limit_dec; sel_lim = &select_limit_dec; 
                mer_lim = &merge_limit_dec; qs_lim = &quick_limit_dec; ct_lim = &count_limit_dec;}

            bool need_array = (k <= *ins_lim) || (k <= *bub_lim) || (k <= *sel_lim) || (k <= *mer_lim) || (k <= *qs_lim) || (k <= *ct_lim);
            int *base = NULL;

            if (need_array) {
                base = malloc(n * sizeof(int));
                if (!base) return 1;

                if (type == 0) fill_sorted_inc(base, n);
                else if (type == 1) {
                    if (k == 1)
                        fill_random(base, n, 10);   // <<< 0–10 tylko dla 10 elementów
                    else
                        fill_random(base, n, 100);  // <<< normalnie
                }
                else fill_sorted_dec(base, n);

                if (k == 1) print_array(base, n);   // <<< PRZED SORTOWANIEM
            }
            // SELECTION SORT
            if (k <= *sel_lim) {
                int *copy = malloc(n * sizeof(int));
                copy_array(base, copy, n);

                double t = measure(selection_sort, copy, n);

                printf("SELECT-SORT: ");
                if (t > LIMIT) {
                    printf("60+\n");
                    *sel_lim = k - 1;
                } else {
                    printf("%.1f\n", t);
                }

                if (k == 1) print_array(copy, n);   // <<< PO SORTOWANIU
                free(copy);
            } else {
                printf("SELECT-SORT: 60+\n");
            }
            // INSERT SORT
            if (k <= *ins_lim) {
                int *copy = malloc(n * sizeof(int));
                copy_array(base, copy, n);

                double t = measure(insert_sort, copy, n);

                printf("INSERT-SORT: ");
                if (t > LIMIT) {
                    printf("60+\n");
                    *ins_lim = k - 1;
                } else {
                    printf("%.1f\n", t);
                }

                if (k == 1) print_array(copy, n);   // <<< PO SORTOWANIU
                free(copy);
            } else {
                printf("INSERT-SORT: 60+\n");
            }

            // BUBBLE SORT
            if (k <= *bub_lim) {
                int *copy = malloc(n * sizeof(int));
                copy_array(base, copy, n);

                double t = measure(bubble_sort, copy, n);

                printf("BUBBLE-SORT: ");
                if (t > LIMIT) {
                    printf("60+\n");
                    *bub_lim = k - 1;
                } else {
                    printf("%.1f\n", t);
                }

                if (k == 1) print_array(copy, n);   // <<< PO SORTOWANIU
                free(copy);
            } else {
                printf("BUBBLE-SORT: 60+\n");
            }

            // MERGE SORT
            if (k <= *mer_lim) {
                int *copy = malloc(n * sizeof(int));
                copy_array(base, copy, n);

                double t = measure(merge_sort, copy, n);

                printf("MERGE-SORT: ");
                if (t > LIMIT) {
                    printf("60+\n");
                } else {
                    printf("%.1f\n", t);
                }

                if (k == 1) print_array(copy, n);   // <<< PO SORTOWANIU
                free(copy);
            } else printf("MERGE-SORT: 60+\n");

            // QUICK SORT
            if (k <= *qs_lim) {
                int *copy = malloc(n * sizeof(int));
                copy_array(base, copy, n);

                double t = measure(quick_sort, copy, n);

                printf("QUICK-SORT: ");
                if (t > LIMIT) {
                    printf("60+\n");
                } else {
                    printf("%.1f\n", t);
                }

                if (k == 1) print_array(copy, n);   // <<< PO SORTOWANIU
                free(copy);
            } else printf("QUICK-SORT: 60+\n");
            
            // COUNT SORT
            if (k <= *ct_lim) {
                int *copy = malloc(n * sizeof(int));
                copy_array(base, copy, n);

                double t;
                if (type == 1) {
                    t = measure(count_sort_100, copy, n);
                } else {
                    t = measure(count_sort_n, copy, n);
                }

                printf("COUNT-SORT: ");
                printf(t > LIMIT ? "60+\n" : "%.1f\n", t);

                if (k == 1) print_array(copy, n);
                free(copy);
            } else {
                printf("COUNT-SORT: 60+\n");
            }


            free(base);
        }
    }

    return 0;
}
