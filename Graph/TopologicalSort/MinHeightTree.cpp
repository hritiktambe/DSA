

/*

https://leetcode.com/problems/minimum-height-trees/

"Basic idea: the roots of MHT must be the mid points of the longest leaf to leaf path in the tree.
And to find the longest path, we can first find the farthest leaf from any node, and then find
the farthest leaf from the node found above. Then these two nodes we found are the end points
of the longest path. And last, we find the centers of the longest path."

Steps:

1.Create adjcent list(neighbors)

2.Count in-degree of all vertices.

3.Pick any vertex 'v' which has in-degree of 0.

4.Print 'v'. Remove the vertex 'v' and all edges coming out of it. Decrement in-degrees of all neighbors of vertex 'v' by 1.

5.Repeat steps 3 and 4 till u either have just 1 or 2 nodes available.

*/

#include <bits/stdc++.h>
using namespace std;
