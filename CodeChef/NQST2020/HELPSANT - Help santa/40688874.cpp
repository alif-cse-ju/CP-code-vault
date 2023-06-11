#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,x;
    cin >> n;
    set<int>st;
    while(n--)
    {
        cin >> x;
        st.insert(x);
    }
    for(int it : st)cout << it << ' ';
    return 0;
}