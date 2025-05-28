#include <stdio.h>
#include <stdlib.h>

int found = 0;

// Utility to sort the subset before printing
void sortSubset(int subset[], int size) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            if (subset[j] > subset[j + 1]) 
            {
                int temp = subset[j];
                subset[j] = subset[j + 1];
                subset[j + 1] = temp;
            }
        }
    }
}

// Print the subset in required format
void printSubset(int subset[], int size) 
{
    sortSubset(subset, size);
    printf("{");
    for (int i = 0; i < size; i++) 
    {
        printf("%d", subset[i]);
        if (i < size - 1) 
            printf(",");
    }
    printf("}\n");
}

void subsetSum(int arr[], int n, int subset[], int subsetSize, int sum, int index, int target) 
{
    if (sum == target) 
    {
        found = 1;
        printSubset(subset, subsetSize);
        return;
    }

    if (index == n || sum > target)
        return;

    // Include arr[index]
    subset[subsetSize] = arr[index];
    subsetSum(arr, n, subset, subsetSize + 1, sum + arr[index], index + 1, target);

    // Exclude arr[index]
    subsetSum(arr, n, subset, subsetSize, sum, index + 1, target);
}

int main() 
{
    int n, d;
    scanf("%d", &n);
    int arr[n], subset[n];

    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &d);

    subsetSum(arr, n, subset, 0, 0, 0, d);

    if (!found) 
    {
        printf("Subset construction is not possible\n");
    }

    return 0;
}
