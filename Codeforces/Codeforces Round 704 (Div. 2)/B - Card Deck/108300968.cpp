#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int a[N],pos[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=1;i<=n;i++)
        {
            if(a[i] > a[pos[i-1]])pos[i]=i;
            else pos[i]=pos[i-1];
        }
        for(i=pos[n];i;i=pos[pos[i]-1])
        {
            for(j=i;j<=n;j++)cout << a[j] << ' ';
            n=i-1;
        }
        cout << '\n';
    }
    return 0;