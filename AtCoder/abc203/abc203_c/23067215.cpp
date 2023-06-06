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

pair<long long,long long>a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n;
    unsigned long long k,ans=0;
    cin >> n >> k;
    for(i=1;i<=n;i++)cin >> a[i].first >> a[i].second;
    sort(a+1,a+n+1);
    i=1;
    while(k > 0)
    {
        if(i <= n  &&  ans+k >= a[i].first)k-=a[i].first-ans,ans=a[i].first,k+=a[i++].second;
        else ans+=k,k=0;
    }
    cout << ans;
    return 0;
}
