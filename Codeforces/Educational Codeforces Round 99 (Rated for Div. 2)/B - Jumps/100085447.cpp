#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,t,x,y,ans;
    cin >> t;
    while(t--)
    {
        cin >> x;
        y=ans=0;
        for(i=1;y<x;i++)y+=i,ans++;
        cout << ans+(y-x == 1) << '\n';
    }
    return 0;