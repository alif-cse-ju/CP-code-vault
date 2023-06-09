#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e5+5;
const int mod=1e9+7;
vector<long long>ans[40];
void PreCal()
    long long i,j,k;
    for(i=2;i<=35;i++)ans[i].emplace_back(1);
    for(i=2; ;i++)
    {
        j=i;
        if(j*j > mod)break;
        for(k=2; ;k++)
        {
            j*=i;
            ans[k].emplace_back(j);
            if(j > mod)break;
        }
    }
int main()
    FAST();
    PreCal();
    long long x,y,i,k,l,n,t,tc,cnt;
    cin >> t;
    for(tc=1;tc<=t;tc++)
    {
        cin >> n >> k;
        cout << "Case #" << tc << ": ";
        if(k == 1  ||  k > 30)cnt=n;
        else
        {
            cnt=0;
            l=(int)ans[k].size();
            for(i=0;i<l;i++)
            {
                x=ans[k][i]-1;
                if(x > n)break;
                if(i+1 < l)y=min(n,ans[k][i+1]-1ll);
                else y=n;
                cnt+=y/(i+1ll)-x/(i+1ll);
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}