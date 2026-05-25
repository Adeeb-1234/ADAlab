#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50000

int a[MAX], b[MAX];

void merge(int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while (i <= mid)
        b[k++] = a[i++];

    while (j <= high)
        b[k++] = a[j++];

    for (i = low; i <= high; i++)
        a[i] = b[i];
}

void merge_sort(int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;

        merge_sort(low, mid);
        merge_sort(mid + 1, high);

        merge(low, mid, high);
    }
}

int main()
{
    int n, i;
    clock_t start, end;
    double time_taken;

    srand(time(NULL));

    printf("Input Size\tTime Taken (seconds)\n");

    for (n = 10000; n <= 50000; n += 10000)
    {
        for (i = 0; i < n; i++)
            a[i] = rand() % 100000;

        start = clock();

        merge_sort(0, n - 1);

        end = clock();

        time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%d\t\t%f\n", n, time_taken);
    }

    return 0;
}
