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





int ans[100002];
int degree[100002];
pair<PII,int>edges[100002];

int main()
{
    FAST();

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,n,x,y,mx=0;
    cin >> n;
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        ++degree[x],mx=max(mx,degree[x]);
        ++degree[y],mx=max(mx,degree[y]);
        edges[i].FI.FI=min(x,y),edges[i].FI.SE=max(x,y);
        edges[i].SE=i;
    }
    cout << mx << '\n';
    for(i=1;i<=n;i++)degree[i]=1;
    sort(edges+1,edges+n);
    map<int,bool>mp[n+1];
    for(i=1;i<n;i++)
    {
        x=edges[i].FI.FI;
        mp[x-1].C;
        y=edges[i].FI.SE;
        while(mp[x][degree[x]])++degree[x];
        ans[edges[i].SE]=degree[x];
        mp[x][degree[x]]=mp[y][degree[x]]=true;
        ++degree[x];
    }
    for(i=1;i<n;i++)cout << ans[i] << '\n';
    return 0;
}
