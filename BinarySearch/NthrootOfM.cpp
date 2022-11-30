// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    double multiply(int num, int n)
    {
        double ans = 1;
        for (int i = 1; i < n + 1; i++)
        {
            ans *= num;
        }

        return ans;
    }

    int NthRoot(int n, int m)
    {

        int low = 1, high = m;

        while (low <= high)
        {

            int mid = low + (high - low) / 2;
            ///cout<<"mid "<<mid<<endl;
            double temp = multiply(mid, n);
            //cout<<"temp "<<temp<<endl;
            if (temp > m)
            {
                high = mid - 1;
                //cout<<"high "<<high<<endl;
            }
            else if (temp < m)
            {

                low = mid + 1;
                //cout<<"low "<<low<<endl;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.NthRoot(n, m);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends