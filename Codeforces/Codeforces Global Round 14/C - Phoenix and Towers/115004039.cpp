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
int a[M],ans[M];
long long sum[M];
int main()
    FAST();
    int i,m,n,t,x,xA,yA,yS;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> x;
        priority_queue<pair<int,int>>pqA;
        priority_queue<pair<long long,int>>pqS;
        for(i=1;i<=m;i++)
        {
            sum[i]=0;
            pqS.emplace(0,i);
        }
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            pqA.emplace(a[i],i);
        }
        while(!pqA.empty())
        {
            xA=pqA.top().first;
            yA=pqA.top().second;
            pqA.pop();
            yS=pqS.top().second;
            pqS.pop();
            ans[yA]=yS;
            sum[yS]+=xA;
            pqS.emplace(-sum[yS],yS);
        }
        sort(sum+1,sum+m+1);
        if(sum[m]-sum[1] > x)cout << "NO\n";
        else
        {
            cout << "YES\n";
            for(i=1;i<=n;i++)cout << ans[i] << ' ';
            cout << '\n';
        }
    }
    return 0;
}