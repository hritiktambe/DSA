
/*

https://practice.geeksforgeeks.org/problems/shortest-unique-prefix-for-every-word/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{

    class Trie
    {
    private:
        class TrieNode
        {
            unordered_map<char, TrieNode *> children;
            int countprefix;

        public:
            TrieNode() : countprefix(0) {}

        public:
            bool findChild(char val)
            {
                return children.find(val) != children.end();
            }

            int getCount()
            {
                return countprefix;
            }

            void increaseCount()
            {
                countprefix++;
            }

            void setChild(char a)
            {
                children[a] = new TrieNode();
                return;
            }

            TrieNode *getChild(char a)
            {
                return children[a];
            }
        };

        TrieNode *root;

    public:
        Trie()
        {
            root = new TrieNode();
        }

        void insert(string s)
        {

            TrieNode *cur = root;
            for (int i = 0; i < s.size(); i++)
            {

                if (!cur->findChild(s[i]))
                {
                    cur->setChild(s[i]);
                }
                cur = cur->getChild(s[i]);
                cur->increaseCount();
            }
        }

        string prefixSearch(string s)
        {

            TrieNode *cur = root;
            string ans = "";
            for (int i = 0; i < s.size(); i++)
            {
                ans += s[i];
                cur = cur->getChild(s[i]);
                if (cur->getCount() == 1)
                    return ans;
            }

            return ans;
        }
    };

public:
    vector<string> findPrefixes(string arr[], int n)
    {
        Trie *tree = new Trie();

        for (int i = 0; i < n; i++)
        {
            tree->insert(arr[i]);
        }

        vector<string> ans;

        for (int i = 0; i < n; i++)
        {
            ans.push_back(tree->prefixSearch(arr[i]));
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
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends