#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left , *right;
};

struct Info
{
    int sz ; //size of tree
    int maxi; //maximum of value in subtree
    int mini; //minimum value in subtree
    int ans; //ans of 
    bool isbst;
};

Info largestBst(Node* root)
{

    if(!root)
    return {0,INT_MIN,INT_MAX,0,true};

    if(!root->left and !root->right)

    return {1,root->data,root->data,1,true};

    Info l = largestBst(root->left);
    Info r = largestBst(root->right);

    Info ret ; 
    ret.sz = l.sz+r.sz+1;

    if(l.isbst and r.isbst and l.maxi<root->data and r.mini>root->data)
    {
        ret.mini = min(root->data,l.mini);
        ret.maxi = max(root->data,r.maxi);

        ret.ans = l.ans+r.ans+1;

        return ret;
    }

    ret.ans = max(l.ans,r.ans);
    ret.isbst = false;

    return ret;

}
