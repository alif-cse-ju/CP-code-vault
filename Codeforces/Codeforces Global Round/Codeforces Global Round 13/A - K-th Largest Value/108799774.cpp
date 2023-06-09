#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int a[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,q,x,y,cnt=0;
    cin >> n >> q;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        cnt+=(a[i] == 1);
    }
    while(q--)
    {
        cin >> x >> y;
        if(x == 1)
        {
            if(a[y])--cnt;
            else ++cnt;
            a[y]=1-a[y];
        }
        else cout << (cnt >= y) << '\n';
    }
    return 0;