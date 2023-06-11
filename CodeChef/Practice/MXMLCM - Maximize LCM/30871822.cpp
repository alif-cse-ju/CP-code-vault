#include<bits/stdc++.h>
using namespace std;
#define S scanf
#define P printf
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
#define MP make_pair
#define LL long long int
#define ULL unsigned long long int
#define PII pair<int,int>
#define PSI pair<string,int>
#define PIS pair<int,string>
#define PLI pair<long long int,int>
#define PLL pair<long long int,long long int>
#define MII map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define MLI map<long long int,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]= {-1,0,1,-1,1,-1,0,1};
//int dy[]= {1,1,1,0,0,-1,-1,-1};
const int MAX = 2e4 + 7;
int power(int a,int b)
{
    int res = 1;
    while(b>0)
    {
        if(b&1)
            res = (res*a);
        b = b/2;
        a = (a*a);
    }
    return res;
}
int isprime[MAX+5];
vector<int> v;
void sieve()
{
    int i;
    for(i=1;i<=MAX;i++)isprime[i]=i;
    for(i=2;i<=MAX;i++)
    {
        if(i==isprime[i])
        {
            for(int j=2*i; j<=MAX; j+=i)
            {
                if(isprime[j]==j)isprime[j]=i;
            }
        }
    }
}
int val,x,cnt,ans,pos,m,res=1,maxi;
int mp[MAX];
void solve()
{
    int i,n;
    res=ans=1;
    maxi=0;
    memset(mp,0,sizeof(mp));
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>x;
        while(x>1)
        {
            val=isprime[x];
            cnt=0;
            while(isprime[x]==val)
            {
                x/=isprime[x];
                cnt++;
            }
            mp[val]=max(mp[val],cnt);
        }
    }
    for(i=1;i<=m;i++)
    {
        x=i;
        ans=1;
        while(x>1)
        {
            val=isprime[x];
            cnt=0;
            while(isprime[x]==val)
            {
                x/=isprime[x];
                cnt++;
            }
            if(cnt>mp[val])ans*=power(val,cnt-mp[val]);
        }
        if(ans>maxi)
        {
            maxi=ans;
            res=i;
        }
    }
    cout << res << '\n';
}
int main()
{
    FAST();
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    sieve();
    while(t--)solve();
    return 0;
}