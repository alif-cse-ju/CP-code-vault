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
int a[N],par[N];
pair<int,int>temp[N];
int FindParent(int n)
    if(par[n] == n)return n;
    return par[n]=FindParent(par[n]);
int main()
    FAST();
    long long p,ans;
    int i,j,m,n,px,py,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> p;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            par[i]=i;
            temp[i]={a[i],i};
        }
        sort(temp+1,temp+n+1);
        ans=0,m=n-1;
        for(i=1;i<=n;i++)
        {
            if(temp[i].first >= p)break;
            for(j=temp[i].second-1;j;j--)
            {
                if(a[j]%a[temp[i].second])break;
                px=FindParent(temp[i].second);
                py=FindParent(j);
                if(px != py)
                {
                    --m;
                    ans+=temp[i].first;
                    par[px]=py;
                }
                else break;
            }
            for(j=temp[i].second+1;j<=n;j++)
            {
                if(a[j]%a[temp[i].second])break;
                px=FindParent(temp[i].second);
                py=FindParent(j);
                if(px != py)
                {
                    --m;
                    ans+=temp[i].first;
                    par[px]=py;
                }
                else break;
            }
        }
        ans+=p*m;
        cout << ans << '\n';
    }
    return 0;
}