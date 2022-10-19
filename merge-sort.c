#include <stdio.h>
#include <stdlib.h>

void mergesort(int *arr, int start, int end);
void merge(int *arr, int start, int mid, int end);

int main(void)
{
    int arr[] = { 5, 2, 3, 4, 7, 8, 9, 6, 1 };
    int nrOfElements = sizeof(arr) / sizeof(*arr);

    mergesort(arr, 0, nrOfElements);

    // Print the sorted array
    for(int i = 0; i < nrOfElements; i++)
    {
        printf("%d ", arr[i]);
    }
    puts("");

    return EXIT_SUCCESS;
}

// Recursive merge sort function
void mergesort(int *arr, int start, int end)
{
    if(start < end)
    {
        int mid = (start + end) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, (mid + 1), end);
        merge(arr, start, mid, end);
    }
}

void merge(int *arr, int start, int mid, int end)
{
    int tempArr[end];
    int i = start;
    int k = start;
    int j = mid + 1;
    int lowerbound = mid + 1;
    int upperbound = end + 1;

    // While we are within bounds, compare and sort elements from smallest to largest
    while ((i < lowerbound) && (j < upperbound))
    {
        if (arr[i] > arr[j])
        {
            tempArr[k++] = arr[j++];
        }
        else
        {
            tempArr[k++] = arr[i++];
        }
    }

    // Copy over any remaining elements on the left portion
    while (i < lowerbound)
    {
        tempArr[k++] = arr[i++];
    }

    // Copy over any remaining elements on the right portion
    while (j < upperbound)
    {
        tempArr[k++] = arr[j++];
    }

    // Replace the current sorted elements of temp into the original array
    for (int p = start; p < upperbound; p++)
    {
        arr[p] = tempArr[p];
    }
}