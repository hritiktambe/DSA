


#include<bits/stdc++.h>
using namespace std;

int uniquePath(int row,int col)
{

    //formula of nCr is used 

    int n= row+col-2;
    int r = row-1;
    int res=1;
    for(int i=1;i<=r;i++)
    {
        res=res*(n-r+i)/i;
    }

    return res;
}