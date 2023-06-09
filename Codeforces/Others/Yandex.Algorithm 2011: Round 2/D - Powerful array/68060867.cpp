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
    struct query
{
    int l,r,id;
}q[200002];
int l,r,k;
LL sum,a[200002],ans[200002],cnt[1000002];
 bool compare(query &x,query &y)
{
    int a=(x.l-1)/k,b=(y.l-1)/k;
    if(a == b)return x.r < y.r;
    return a < b;
}
 void add(LL x)
{
    x=a[x];
    ++cnt[x];
    sum+=x*(cnt[x]*cnt[x]-(cnt[x]-1)*(cnt[x]-1));
}
 void reduce(LL x)
{
    x=a[x];
    --cnt[x];
    sum+=x*(cnt[x]*cnt[x]-(cnt[x]+1)*(cnt[x]+1));
}
 int main()
{
//    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,m,n,x;
    S("%d %d",&n,&m);
    for(i=1;i<=n;i++)S("%lld",&a[i]);
    k=sqrt(m);
    for(i=1;i<=m;i++)
    {
        S("%d",&x);
        q[i].l=x;
        S("%d",&x);
        q[i].r=x;
        q[i].id=i;
    }
    sort(q+1,q+m+1,compare);
    l=1,r=0,sum=0;
    for(i=1;i<=m;i++)
    {
        while(l > q[i].l)add(--l);
        while(r < q[i].r)add(++r);
        while(l < q[i].l)reduce(l++);
        while(r > q[i].r)reduce(r--);
        ans[q[i].id]=sum;
    }
    for(i=1;i<=m;i++)P("%lld\n",ans[i]);
    return 0;
}