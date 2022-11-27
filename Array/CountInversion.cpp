
/*

https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.

    int merge(long long arr[], vector<long long> &tmp, int left, int mid, int right)
    {

        int i = left, j = mid, k = left, inv = 0;

        while (i < mid and j <= right)
        {
            if (arr[i] <= arr[j])
            {
                tmp[k++] = arr[i++];
            }
            else
            {
                tmp[k++] = arr[j++];
                inv += mid - i;
                // cout<<"inv "<<inv<<endl;
            }
        }

        while (i < mid)
            tmp[k++] = arr[i++];

        while (j <= right)
            tmp[k++] = arr[j++];

        for (int i = left; i <= right; i++)
            arr[i] = tmp[i];

        return inv;
    }

    int merge_sort(long long arr[], vector<long long> &tmp, int left, int right)
    {
        int invCount = 0;
        if (left < right)
        {

            int mid = left + (right - left) / 2;

            invCount += merge_sort(arr, tmp, left, mid);
            invCount += merge_sort(arr, tmp, mid + 1, right);

            invCount += merge(arr, tmp, left, mid + 1, right);
        }

        return invCount;
    }

    long long int inversionCount(long long arr[], long long N)
    {
        vector<long long> tmp(N);

        int ans = merge_sort(arr, tmp, 0, N - 1);

        return ans;
    }
};

// { Driver Code Starts.

int main()
{

    long long T;
    cin >> T;

    while (T--)
    {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}
// } Driver Code Ends