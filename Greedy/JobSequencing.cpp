/*
https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
*/

// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

bool compare(struct Job j1, Job j2)
{
    if (j1.profit == j2.profit)
        return j1.id < j2.id;

    return j1.profit > j2.profit;
}
class Solution
{

public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        vector<int> ans;
        sort(arr, arr + n, compare);

        int maxd = 0;
        for (auto i : arr)
        {
            maxd = max(maxd, i.dead);
        }

        vector<int> js(-1, maxd + 1);
        int profit = 0, jobsdone = 0;
        for (auto i : arr)
        {

            int j = i.dead;
            while (j >= 0 and js[j] != -1)
                j--;

            if (js[j] == -1)
            {
                profit += i.profit;
                js[j] = i.id;
                jobsdone++;
            }
            if (j <= 0)
                break;
        }
        ans.push_back(jobsdone);
        ans.push_back(profit);
        return ans;
    }
};

// { Driver Code Starts.
// Driver program to test methods
int main()
{
    int t;
    //testcases
    cin >> t;

    while (t--)
    {
        int n;

        //size of array
        cin >> n;
        Job arr[n];

        //adding id, deadline, profit
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends