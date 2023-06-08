#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,x,cnt=0;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> x;
        cnt+=(x & 1);
    }
    if(!cnt)cout << "-1";
    else cout << n-cnt;
    return 0;