/* Dynamic Programming implementation of Box Stacking problem */
#include <stdio.h>
#include <stdlib.h>

/* Representation of a box */
struct Box
{
    // h --> height, w --> width, d --> depth
    int h, w, d; // for simplicity of solution, always keep w <= d
};

// A utility function to get minimum of two integers
int min(int x, int y)
{
    return (x < y) ? x : y;
}

// A utility function to get maximum of two integers
int max(int x, int y)
{
    return (x > y) ? x : y;
}

/* Following function is needed for library function qsort(). We
use qsort() to sort boxes in decreasing order of base area.
Refer following link for help of qsort() and compare()
http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ */
int compare(const void *a, const void *b)
{
    return ((*(Box *)b).d * (*(Box *)b).w) -
           ((*(Box *)a).d * (*(Box *)a).w);
}

/* Returns the height of the tallest stack that can be
formed with give type of boxes */
int maxStackHeight(Box arr[], int n)
{
    /* Create an array of all rotations of given boxes
        For example, for a box {1, 2, 3}, we consider three
        instances{{1, 2, 3}, {2, 1, 3}, {3, 1, 2}} */
    Box rot[3 * n];
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        // Copy the original box
        rot[index].h = arr[i].h;
        rot[index].d = max(arr[i].d, arr[i].w);
        rot[index].w = min(arr[i].d, arr[i].w);
        index++;

        // First rotation of box
        rot[index].h = arr[i].w;
        rot[index].d = max(arr[i].h, arr[i].d);
        rot[index].w = min(arr[i].h, arr[i].d);
        index++;

        // Second rotation of box
        rot[index].h = arr[i].d;
        rot[index].d = max(arr[i].h, arr[i].w);
        rot[index].w = min(arr[i].h, arr[i].w);
        index++;
    }

    // Now the number of boxes is 3n
    n = 3 * n;

    /* Sort the array 'rot[]' in non-increasing order
        of base area */
    qsort(rot, n, sizeof(rot[0]), compare);

    // Uncomment following two lines to print all rotations
    // for (int i = 0; i < n; i++ )
    // printf("%d x %d x %d\n", rot[i].h, rot[i].w, rot[i].d);

    /* Initialize msh values for all indexes
        msh[i] --> Maximum possible Stack Height with box i on top */
    int msh[n];
    for (int i = 0; i < n; i++)
        msh[i] = rot[i].h;

    /* Compute optimized msh values in bottom up manner */
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (rot[i].w < rot[j].w &&
                rot[i].d < rot[j].d &&
                msh[i] < msh[j] + rot[i].h)
            {
                msh[i] = msh[j] + rot[i].h;
            }

    /* Pick maximum of all msh values */
    int max = -1;
    for (int i = 0; i < n; i++)
        if (max < msh[i])
            max = msh[i];

    return max;
}

/* Driver program to test above function */
int main()
{
    Box arr[] = {{4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32}};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The maximum possible height of stack is %d\n",
           maxStackHeight(arr, n));

    return 0;
}

/* Dynamic Programming top-down implementation of Box
 * Stacking problem */
#include <bits/stdc++.h>
using namespace std;

/* Representation of a box */
class Box
{
public:
    int length;
    int width;
    int height;
};

// dp array
int dp[303];

/*
    boxes -> vector of Box
    bottom_box_index -> index of the bottom box
    index -> index of current box
*/
/* NOTE: we can use only one variable in place of bottom_box_index and index
    but it has been avoided to make it simple */
int findMaxHeight(vector<Box> &boxes, int bottom_box_index, int index)
{

    // base case
    if (index < 0)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int maximumHeight = 0;

    // recurse
    for (int i = index; i >= 0; i--)
    {

        // if there is no bottom box
        if (bottom_box_index == -1

            // or if length & width of new box is < that of
            // bottom box
            || (boxes[i].length < boxes[bottom_box_index].length && boxes[i].width < boxes[bottom_box_index].width))

            maximumHeight = max(maximumHeight,
                                findMaxHeight(boxes, i, i - 1) + boxes[i].height);
    }

    return dp[index] = maximumHeight;
}

/* wrapper function for recursive calls which
Returns the height of the tallest stack that can be
formed with give type of boxes */
int maxStackHeight(int height[], int width[], int length[],
                   int types)
{
    // creating a vector of type Box class
    vector<Box> boxes;

    // Initialize dp array with -1
    memset(dp, -1, sizeof(dp));

    Box box;

    /* Create an array of all rotations of given boxes
    For example, for a box {1, 2, 3}, we consider three
    instances{{1, 2, 3}, {2, 1, 3}, {3, 1, 2}} */
    for (int i = 0; i < types; i++)
    {

        // copy original box
        box.height = height[i];
        box.length = max(length[i], width[i]);
        box.width = min(length[i], width[i]);

        boxes.push_back(box);

        // First rotation of box
        box.height = width[i];
        box.length = max(length[i], height[i]);
        box.width = min(length[i], height[i]);

        boxes.push_back(box);

        // Second rotation of box
        box.height = length[i];
        box.length = max(width[i], height[i]);
        box.width = min(width[i], height[i]);

        boxes.push_back(box);
    }

    // sort by area in ascending order .. because we will be dealing with this vector in reverse
    sort(boxes.begin(), boxes.end(), [](Box b1, Box b2)
         {
		// if area of box1 < area of box2
		return (b1.length * b1.width)
			< (b2.length * b2.width); });

    // Uncomment following two lines to print all rotations
    // for (int i = boxes.size() - 1; i >= 0; i-- )
    // printf("%d x %d x %d\n", boxes[i].length, boxes[i].width, boxes[i].height);

    return findMaxHeight(boxes, -1, boxes.size() - 1);
}

int main()
{

    // where length, width and height of a particular box
    // are at ith index of the following arrays
    int length[] = {4, 1, 4, 10};
    int width[] = {6, 2, 5, 12};
    int height[] = {7, 3, 6, 32};

    int n = sizeof(length) / sizeof(length[0]);

    printf("The maximum possible height of stack is %d\n",
           maxStackHeight(height, length, width, n));

    return 0;
}
