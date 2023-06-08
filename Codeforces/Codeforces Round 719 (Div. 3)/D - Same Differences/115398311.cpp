#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    FAST();
    int i,n,t,x;
    long long ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        map<int,long long>cnt;
        for(i=1;i<=n;i++)
        {
            cin >> x;
            x-=i,++cnt[x];
        }
        ans=0;
        for(auto it : cnt)ans+=(it.second*(it.second-1))/2;
        cout << ans << '\n';
    }
    return 0;