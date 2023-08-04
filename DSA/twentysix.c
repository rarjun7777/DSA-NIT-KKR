// Build max heap

#include <stdio.h>
#include <stdlib.h>

void maxheapify(int arr[], int i, int size)
{
    int largest = i;
    int child1 = 2 * i + 1;
    int child2 = 2 * i + 2;

    if (child1 < size && arr[child1] > arr[largest])
        largest = child1;

    if (child2 < size && arr[child2] > arr[largest])
        largest = child2;

    if (largest != i)
    {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;

        maxheapify(arr, largest, size);
    }

    return;
}

void buildheap(int arr[], int size)
{
    int i;
    for (i = size / 2; i >= 0; i--)
        maxheapify(arr, i, size);

    return;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    buildheap(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }

    return 0;
}
