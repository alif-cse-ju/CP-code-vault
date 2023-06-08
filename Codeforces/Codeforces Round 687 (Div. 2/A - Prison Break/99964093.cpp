#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int m,n,t,x,y,ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> x >> y;
        cout << max(max(abs(1-x)+abs(1-y),abs(1-x)+abs(m-y)),max(abs(n-x)+abs(1-y),abs(n-x)+abs(m-y))) << '\n';
    }
    return 0;