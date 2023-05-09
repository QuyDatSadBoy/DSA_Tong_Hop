#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t = 4;
    while (t--)
    {
        string s;
        cin >> s;
        int cnt = 0, res = 0;
        stack<pair<char, int>> st;
        st.push({'*', 0});
        for (char &i : s)
        {
            if (st.size() && ((i == ')' && st.top().first == '(') || (i == ']' && st.top().first == '[')))
            {
                st.pop();
                if (st.size())
                    res = max(res, cnt - st.top().second);
            }
            else
            {
                cnt += i == '[';
                st.push({i, cnt});
            }
        }
        cout << res << endl;
    }
    return 0;
}