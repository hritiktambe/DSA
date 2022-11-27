//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
public:
    void merge(int arr[], int l, int m, int r)
    {

        int lz = m - l, rz = r - m + 1;

        int al[lz], ar[rz];
        memset(al, 0, sizeof al);
        memset(ar, 0, sizeof ar);

        for (int i = 0; i < lz; i++)
            al[i] = arr[l + i];

        for (int i = 0; i < rz; i++)
            ar[i] = arr[m + i];

        int il = 0, ir = 0, indexofarray = l;

        while (il < lz and ir < rz)
        {

            if (al[il] <= ar[ir])
            {
                arr[indexofarray] = al[il];
                il++;
            }
            else
            {

                arr[indexofarray] = ar[ir];
                ir++;
            }
            indexofarray++;
        }

        while (il < lz)
        {
            arr[indexofarray++] = al[il++];
        }

        while (ir < rz)
        {
            arr[indexofarray++] = ar[ir++];
        }
    }

public:
    void mergeSort(int arr[], int l, int r)
    {

        if (l >= r)
            return;

        int mid = l + (r - l) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid + 1, r);
    }
};

//{ Driver Code Starts.

int main()
{
    int n, T, i;

    scanf("%d", &T);

    while (T--)
    {

        scanf("%d", &n);
        int arr[n + 1];
        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        Solution ob;
        ob.mergeSort(arr, 0, n - 1);
        printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends