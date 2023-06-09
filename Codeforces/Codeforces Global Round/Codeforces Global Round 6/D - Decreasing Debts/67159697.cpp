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
    LL diche[100002];
LL niche[100002];
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     LL val;
    int i,m,n,x,y;
    pair<int,LL>x1,y1;
    cin >> n >> m;
    while(m--)
    {
        cin >> x >> y >> val;
        diche[x]+=val,niche[y]+=val;
    }
    Q<pair<int,LL> >pabe,debe;
    for(i=1;i<=n;i++)
    {
        if(diche[i]-niche[i] > 0LL)pabe.PS({i,diche[i]-niche[i]});
        else if(diche[i]-niche[i] < 0LL)debe.PS({i,niche[i]-diche[i]});
    }
    V<pair<PII,LL> >ans;
    while(!pabe.EM)
    {
        x1=pabe.F,pabe.PP;
        y1=debe.F,debe.PP;
        ans.PSB({{x1.FI,y1.FI},min(x1.SE,y1.SE)});
        x1.SE-=ans.back().SE;
        y1.SE-=ans.back().SE;
        if(x1.SE > 0LL)pabe.PS(x1);
        else if(y1.SE > 0LL)debe.PS(y1);
    }
    cout << ans.SZ << '\n';
    for(auto node : ans)cout << node.FI.FI << ' ' << node.FI.SE << ' ' << node.SE << '\n';
    return 0;
}