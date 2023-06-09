#include<bits/stdc++.h>
using namespace std;
#define S scanf
#define P prLLf
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
#define MLI map<long long LL,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
     //LL dx[]= {-1,1,0,0};
//LL dy[]= {0,0,-1,1};
//LL dx[]= {-1,0,1,-1,1,-1,0,1};
//LL dy[]= {1,1,1,0,0,-1,-1,-1};
    LL ans[200005];
LL boss[200005];
LL adj_cnt[200005];
PII queries[200005];
pair<LL,PII>edges[200005];
 LL find_boss(LL node)
{
    if(boss[node] == node)
    {
        return node;
    }
    return boss[node]=find_boss(boss[node]);
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("input.txt","w",stdout);
     LL i,j=1,n,q,x,y,z,parent_x,parent_y;
    cin >> n >> q;
    for(i=1; i<n; i++)
    {
        cin >> x >> y >> z;
        edges[i].FI=z;
        edges[i].SE.FI=min(x,y);
        edges[i].SE.SE=max(x,y);
        boss[i]=i;
        adj_cnt[i]=1;
    }
    boss[n]=n;
    adj_cnt[i]=1;
    for(i=1; i<=q; i++)
    {
        cin >> queries[i].FI;
        queries[i].SE=i;
    }
    sort(edges+1,edges+n);
    sort(queries+1,queries+q+1);
    LL cnt=0,cost;
    for(i=1; i<=q; i++)
    {
        cost=queries[i].FI;
        while(j<n  &&  edges[j].FI <= cost)
        {
            x=edges[j].SE.FI;
            y=edges[j].SE.SE;
            parent_x=find_boss(x);
            parent_y=find_boss(y);
            boss[parent_y]=parent_x;
            cnt+=(adj_cnt[parent_x]*adj_cnt[parent_y]);
            adj_cnt[parent_x]+=adj_cnt[parent_y];
            j++;
        }
        ans[queries[i].SE]=cnt;
    }
    cout << ans[1];
    for(i=2; i<=q; i++)
    {
        cout << ' ' << ans[i];
    }
    return 0;
}