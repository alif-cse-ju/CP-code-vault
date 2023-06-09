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
#define PSB emplace_back
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
    int p[1000002],dist[102][102];
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,j,k,m,n;
    char s[102];
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> s+1;
        for(j=1;j<=n;j++)
        {
            if(s[j] == '1')dist[i][j]=1;
            else if(i != j)dist[i][j]=10000000;
        }
    }
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        }
    }
    cin >> m;
    for(i=1;i<=m;i++)cin >> p[i];
    V<int>ans;
    ans.PSB(1);
    for(i=2;i<=m;i++)
    {
        if(dist[p[ans.back()]][p[i]] != i-ans.back())ans.PSB(i-1);
    }
    ans.PSB(m);
    cout << ans.SZ << '\n';
    for(int x : ans)cout << p[x] << ' ';
    return 0;
}