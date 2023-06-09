#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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
 template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
 //int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]= {-1,0,1,-1,1,-1,0,1};
//int dy[]= {1,1,1,0,0,-1,-1,-1};
      int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,m,n,x,y;
    cin >> n;
    PII a[n+1];
    for(i=1;i<=n;i++)
    {
        cin >> x;
        a[i].FI=-x,a[i].SE=i;
    }
    sort(a+1,a+n+1);
    cin >> m;
    int ans[m+1];
    V<PII>queries[m+1];
    for(i=1;i<=m;i++)
    {
        cin >> x >> y;
        queries[x].PSB({i,y});
    }
    ordered_set<PII>ost;
    for(i=1;i<=n;i++)
    {
        x=-a[i].FI,y=a[i].SE;
        ost.insert({y,x});
        for(auto p : queries[i])ans[p.FI]=(*ost.find_by_order(p.SE-1)).SE;
    }
    for(i=1;i<=m;i++)cout << ans[i] << '\n';
    return 0;
}