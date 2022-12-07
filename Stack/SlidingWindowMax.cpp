/*

https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

approach :- we will be maintaining a decreasing order and storing index and will be using deque data structure
whose internal implementation is doubly linked list when we will encounter an element larger than that is in deque 
we will pop it out because it is longer required since we only want numbers that are max,
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k)
    {

        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {

            if (!dq.empty() and dq.front() == i - k)
                dq.pop_front();

            while (!dq.empty() and arr[dq.back()] < arr[i])
            {
                //cout<<dq.back()<<endl;
                dq.pop_back();
            }

            dq.push_back(i);

            if (!dq.empty() and i >= k - 1)
            {
                //cout<<"ans "<<arr[dq.front()];
                ans.push_back(arr[dq.front()]);
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends