#include<bits/stdc++.h>

using namespace std;

#define G getline
#define SZ size()
#define C clear()
#define B begin()
#define F front()
#define T top()
#define E end()
#define EM empty()
#define V vector
#define Q queue
#define DQ deque
#define PQ priority_queue
#define ST stack
#define FI first
#define SE second
#define PI acos(-1)
#define PS push
#define PP pop()
#define PSF push_front
#define PSB push_back
#define PPF pop_front()
#define PPB pop_back()
#define LL long long
#define ULL unsigned long long
#define PII pair<int,int>
#define PSI pair<string,int>
#define PIS pair<int,string>
#define PLI pair<LL,int>
#define PLL pair<LL,LL>
#define MII map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define MLI map<LL,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)





//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};




const int N=2e5+5;
const LL mod=998244353;

LL cnt[N];
int n,lb[12],rb[12];

void Update(int idx,LL val)
{
    while(idx <= n)
    {
        cnt[idx]=(cnt[idx]+val)%mod;
        idx+=idx & (-idx);
    }
}

LL Query(int idx)
{
    LL ans=0;
    while(idx > 0)
    {
        ans=(ans+cnt[idx])%mod;
        idx-=idx & (-idx);
    }
    return ans;
}

int main()
{
    FAST();
    cnt[1]=1;
    LL i,j,k,l,r,ans,check;
    cin >> n >> k;
    for(i=1;i<=k;i++)cin >> lb[i] >> rb[i];
    for(i=2;i<=n;i++)
    {
        ans=0;
        for(j=1;j<=k;j++)
        {
            r=i-lb[j];
            if(r < 1)continue;
            l=max(1LL,i-rb[j]);
            check=Query(r)-Query(l-1);
            check%=mod;
            if(check < 0)check+=mod;
            ans=(ans+check)%mod;
        }
        Update(i,ans);
    }
    cout << Query(n);
    return 0;
}
