//{ Driver Code Starts
/*
https : //practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

Approach : Compare arrays A and B if array A has element smaller than elment of array B increment pointer of A
if B has element smaller than A then swap elements,now Array A is sorted we have to check whether the element is in correct
position in B we will use insertion sort to check
Time complexity will O(n*m)
space complexity O(1)

*/
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        int i = 0, j = 0;

        while (i < n and j < m)
        {

            if (arr1[i] <= arr2[j])
                i++;
            else
            {
                swap(arr1[i], arr2[j]);
                i++;

                if (j < m - 1 and arr2[j + 1] < arr2[j])
                {
                    int tmp = arr2[j];
                    int k = j + 1;

                    while (arr2[k] < tmp and k < m)
                    {
                        arr2[k - 1] = arr2[k];
                        k++;
                    }
                    arr2[k - 1] = tmp;
                }
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{

    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        long long arr1[n], arr2[m];

        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);

        for (int i = 0; i < n; i++)
            cout << arr1[i] << " ";

        for (int i = 0; i < m; i++)
            cout << arr2[i] << " ";

        cout << endl;
    }

    return 0;
}

// } Driver Code Ends