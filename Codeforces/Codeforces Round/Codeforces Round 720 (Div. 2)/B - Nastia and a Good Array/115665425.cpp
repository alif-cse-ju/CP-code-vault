#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int a[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t,pos;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        pos=1;
        for(i=2;i<=n;i++)
        {
            if(a[i] < a[pos])pos=i;
        }
        cout << n-1 << '\n';
        for(i=pos-1;i;i--)cout << pos << ' ' << i << ' ' << a[pos] << ' ' << a[pos]+pos-i << '\n';
        for(i=pos+1;i<=n;i++)cout << pos << ' ' << i << ' ' << a[pos] << ' ' << a[pos]+i-pos << '\n';
    }
    return 0;