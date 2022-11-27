

/*

https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

*/

#include<bits/stdc++.h>
using namespace std;

struct meeting
{
    int start, end, pos;
};

bool comparator(struct meeting p1, meeting p2)
{
    return p1.end < p2.end;
}

vector<int> mxmeeting(int s[], int e[], int n)
{
    vector<int> v;
    meeting m[n];
    for (int i = 0; i < n; i++)
    {
        m[i].start = s[i];
        m[i].end = e[i];
        m[i].pos = i + 1;
    }

    sort(m, m + n, comparator);
    v.push_back(m[0].pos);
    int f = m[0].end;
    for (int i = 1; i < n; i++)
    {
        if (m[i].start >= f)
            v.push_back(m[i].pos), f = m[i].end;
    }

    return v;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v;
        int s[n], e[n];
        for (int i = 0; i < n; i++)
            cin >> s[i];
        for (int i = 0; i < n; i++)
            cin >> e[i];
        v = mxmeeting(s, e, n);
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << endl;
    }
}