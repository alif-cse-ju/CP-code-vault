#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,x,y;
    long long ans,sum;
    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        ans=sum=0;
        for(i=0;i<n;i++)
        {
            cin >> y;
            sum+=y;
            ans+=(y+x-1)/x;
        }
        cout << (sum+x-1)/x << ' ' << ans << '\n';
    }
    return 0;