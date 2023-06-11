#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        set<int>st;
        while(n--)
        {
            cin >> x;
            if(x)st.insert(x);
        }
        cout << st.size() << '\n';
    }
    return 0;
}