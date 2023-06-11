#include<bits/stdc++.h>
using namespace std;
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
long long a[N],sum[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long i,n,t,ans,x;
    deque<long long>dq;
    cin >> n >> t;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        dq.emplace_back(a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    ans=(t/sum[n])*n;
    t%=sum[n];
    while(!dq.empty())
    {
        x=dq.front();
        dq.pop_front();
        if(t >= x)
        {
            ++ans;
            t-=x;
            dq.emplace_back(x);
        }
        if((int)dq.size() == 1)
        {
            ans+=t/dq.front();
            break;
        }
    }
    cout << ans;
    return 0;
}
//1316