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




LL ans[100002];
map<LL,int>mp;

int main()
{
    FAST();
    LL i,j,m,n,x,cnt=0,cnt2=0,finalAns;
    cin >> n >> x >> m;
    ans[1]=x;
    mp[x]=1;
    for(i=2; ;i++)
    {
        ans[i]=(ans[i-1]*ans[i-1])%m;
        if(mp[ans[i]])break;
        mp[ans[i]]=i;
    }
    finalAns=0;
    x=mp[ans[i]];
    for(j=1;j<x;j++)finalAns+=ans[j];
    n-=x-1;
    for(j=x;j<i;j++)++cnt,cnt2+=ans[j];
    finalAns+=(n/cnt)*cnt2;
    n%=cnt;
    i=mp[ans[i]];
    while(n--)finalAns+=ans[i++];
    cout << finalAns;
    return 0;
}
