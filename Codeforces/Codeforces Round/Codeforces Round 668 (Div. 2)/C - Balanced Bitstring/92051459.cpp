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
    const int N=3e5+5;
bool mark0[N],mark1[N];
int i,j,k,n,cnt,cnt1[N],cnt0[N];
char s[N];
 bool Solve()
{
    cnt=0;
    cin >> n >> k >> s+1;
    vector<int>v0,v1;
    for(i=1;i<=n;i++)
    {
        if(s[i] == '?')++cnt;
        else if(s[i] == '0')v0.emplace_back(i);
        else v1.emplace_back(i);
    }
    if(cnt == n)return 1;
    if(v0.size() > (n+1)/2  &&  v1.size() > (n+1)/2)return 0;
    for(i=1;i<=n;i++)
    {
        cnt0[i]=cnt1[i]=0;
        mark0[i]=mark1[i]=0;
    }
    for(int x : v0)
    {
        if(mark0[x])continue;
        for(i=x;i<=n;i+=k)
        {
            if(s[i] == '1')return 0;
            s[i]='0';
            mark0[i]=1;
        }
        for(i=x;i>0;i-=k)
        {
            if(s[i] == '1')return 0;
            s[i]='0';
            mark0[i]=1;
        }
    }
    for(int x : v1)
    {
        if(mark1[x])continue;
        for(i=x;i<=n;i+=k)
        {
            if(s[i] == '0')return 0;
            s[i]='1';
            mark1[i]=1;
        }
        for(i=x;i>0;i-=k)
        {
            if(s[i] == '0')return 0;
            s[i]='1';
            mark1[i]=1;
        }
    }
    for(i=1;i<=n;i++)cnt0[i]+=cnt0[i-1]+(s[i] == '0'),cnt1[i]+=cnt1[i-1]+(s[i] == '1');
    for(i=k;i<=n;i++)
    {
        if(cnt0[i]-cnt0[i-k] > k/2)return 0;
        if(cnt1[i]-cnt1[i-k] > k/2)return 0;
    }
    return 1;
}
 int main()
{
    FAST();
    int t;
    cin >> t;
    while(t--)
    {
        if(Solve())cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}