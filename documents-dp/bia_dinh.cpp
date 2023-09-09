#include <iostream>
#include <cstdlib>

// A utility function to find min of two integers
int min(int x, int y) { return (x < y) ? x : y; }

/* A binary tree node has data, pointer to left child and a pointer to
right child */
struct node
{
    int data;
    node *left, *right;
};

// The function returns size of the minimum vertex cover
int vCover(node *root)
{
    // The size of minimum vertex cover is zero if tree is empty or there
    // is only one node
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return 0;

    // Calculate size of vertex cover when root is part of it
    int size_incl = 1 + vCover(root->left) + vCover(root->right);

    // Calculate size of vertex cover when root is not part of it
    int size_excl = 0;
    if (root->left)
        size_excl += 1 + vCover(root->left->left) + vCover(root->left->right);
    if (root->right)
        size_excl += 1 + vCover(root->right->left) + vCover(root->right->right);

    // Return the minimum of two sizes
    return min(size_incl, size_excl);
}

// A utility function to create a node
node *newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}

// Driver program to test above functions
int main()
{
    // Let us construct the tree given in the above diagram
    node *root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);

    std::cout << "Size of the smallest vertex cover is " << vCover(root) << std::endl;

    return 0;
}

#include <iostream>
#include <stdlib.h>

// A utility function to find min of two integers
int min(int x, int y) { return (x < y) ? x : y; }

/* A binary tree node has data, pointer to left child and a pointer to
right child */
struct node
{
    int data;
    int vc;
    struct node *left, *right;
};

// A memoization based function that returns size of the minimum vertex cover.
int vCover(struct node *root)
{
    // The size of minimum vertex cover is zero if tree is empty or there
    // is only one node
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 0;

    // If vertex cover for this node is already evaluated, then return it
    // to save recomputation of same subproblem again.
    if (root->vc != 0)
        return root->vc;

    // Calculate size of vertex cover when root is part of it
    int size_incl = 1 + vCover(root->left) + vCover(root->right);

    // Calculate size of vertex cover when root is not part of it
    int size_excl = 0;
    if (root->left)
        size_excl += 1 + vCover(root->left->left) + vCover(root->left->right);
    if (root->right)
        size_excl += 1 + vCover(root->right->left) + vCover(root->right->right);

    // Minimum of two values is vertex cover, store it before returning
    root->vc = min(size_incl, size_excl);

    return root->vc;
}

// A utility function to create a node
struct node *newNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->vc = 0; // Set the vertex cover as 0
    return temp;
}

// Driver program to test above functions
int main()
{
    // Let us construct the tree given in the above diagram
    struct node *root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);

    std::cout << "Size of the smallest vertex cover is " << vCover(root) << std::endl;

    return 0;
}

// C++ implementation for the above approach
#include <bits/stdc++.h>
using namespace std;

// An utility function to add an edge in the tree
void addEdge(vector<int> adj[], int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

void dfs(vector<int> adj[], vector<int> dp[], int src,
         int par)
{
    for (auto child : adj[src])
    {
        if (child != par)
            dfs(adj, dp, child, src);
    }

    for (auto child : adj[src])
    {
        if (child != par)
        {
            // not including source in the vertex cover
            dp[src][0] += dp[child][1];

            // including source in the vertex cover
            dp[src][1] += min(dp[child][1], dp[child][0]);
        }
    }
}

// function to find minimum size of vertex cover
void minSizeVertexCover(vector<int> adj[], int N)
{
    vector<int> dp[N + 1];

    for (int i = 1; i <= N; i++)
    {
        // 0 denotes not included in vertex cover
        dp[i].push_back(0);

        // 1 denotes included in vertex cover
        dp[i].push_back(1);
    }

    dfs(adj, dp, 1, -1);

    // printing minimum size vertex cover
    cout << min(dp[1][0], dp[1][1]) << endl;
}

// Driver Code
int main()
{
    /*						 1

                        /		 \

                    2			 7

            /			 \

            3			 6

    /	 |	 \

4		 8		 5

*/

    // number of nodes in the tree
    int N = 8;

    // adjacency list representation of the tree
    vector<int> adj[N + 1];

    addEdge(adj, 1, 2);
    addEdge(adj, 1, 7);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 6);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 8);
    addEdge(adj, 3, 5);

    minSizeVertexCover(adj, N);

    return 0;
}
