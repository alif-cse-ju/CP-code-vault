#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        set<int>st;
        vector<int>v;
        while(n--)
        {
            cin >> x;
            if(st.find(x) == st.end())st.insert(x);
            else v.emplace_back(x);
        }
        sort(v.begin(),v.end());
        for(int it : st)cout << it << ' ';
        for(int it : v)cout << it << ' ';
        cout << '\n';
    }
    return 0;