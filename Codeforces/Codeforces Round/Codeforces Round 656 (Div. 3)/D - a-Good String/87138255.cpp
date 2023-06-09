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
//int dx[]= {-1,0,1,-1,1,-1,0,1};
//int dy[]= {1,1,1,0,0,-1,-1,-1};
    char s[131075];
int cnt[30][131075];
 int DP(char c,int l,int r)
{
    if(l == r)
    {
        if(s[l] == c)return 0;
        return 1;
    }
    int x,y,mid=(l+r) >> 1;
    x=(mid-l+1)-(cnt[c-'a'+1][mid]-cnt[c-'a'+1][l-1])+DP(char(c+1),mid+1,r);
    y=(mid-l+1)-(cnt[c-'a'+1][r]-cnt[c-'a'+1][mid])+DP(char(c+1),l,mid);
    return min(x,y);
}
 int main()
{
    FAST();
    int i,j,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> s+1;
        for(i=1;i<27;i++)
        {
            for(j=1;j<=n;j++)cnt[i][j]=0;
        }
        for(i=1;i<=n;i++)cnt[s[i]-'a'+1][i]=1;
        for(i=1;i<27;i++)
        {
            for(j=1;j<=n;j++)cnt[i][j]+=cnt[i][j-1];
        }
        cout << DP('a',1,n) << '\n';
    }
    return 0;
}