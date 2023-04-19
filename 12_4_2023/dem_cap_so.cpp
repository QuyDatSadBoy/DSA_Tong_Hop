#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int count_pairs(vector<int> a)
{
    int n = a.size();
    int ans = 0;
    stack<int> s;
    int top_index = -1;
    sort(a.begin(), a.end(), greater<int>()); // sắp xếp mảng giảm dần
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && s.top() < a[i])
        {
            s.pop();
            top_index--;
        }
        s.push(a[i]);
        top_index++;
        int j = n - 1;
        while (j > i && a[j] < s.top())
        {
            j--;
        }
        ans += (j - top_index - 1) * (s.top() - i);
    }
    return ans;
}

int main()
{
    vector<int> a = {2, 4, 1, 2, 2, 5, 1};
    int res = count_pairs(a);
    cout << res << endl; // expected output: 10
    return 0;
}