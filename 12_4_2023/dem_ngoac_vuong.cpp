#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    string s;
    cin >> s;
    stack<char> st;
    ll res = 0, cnt2 = 0;
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            continue;
        if (s[i] == '(' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if (s[i] == ')')
            {
                if (!st.empty() && st.top() == '(')
                    st.pop();
                else
                    cnt2 = 0;
            }
            else
            {
                if (s[i] == ']')
                {
                    if (!st.empty() && st.top() == '[')
                    {
                        st.pop();
                        cnt2++;
                    }
                    else
                        cnt2 = 0;
                }
            }
        }
        res = max(res, cnt2);
    }
    cout << res << endl;
}