#include<bits/stdc++.h>
using namespace std;
#define S scanf
#define P printf
#define G getline
#define SZ size()
#define C clear()
#define B begin()
#define F front()
//#define T top()
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
   #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 int a[1005][1005];
ordered_set col[1005],row[1005];
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,j,m,n,x,y,ans;
    cin >> n >> m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin >> a[i][j];
            row[i].insert(a[i][j]);
            col[j].insert(a[i][j]);
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            x=row[i].order_of_key(a[i][j]);
            y=col[j].order_of_key(a[i][j]);
            ans=max(x,y);
            ans+=max((int)row[i].SZ-x-1,(int)col[j].SZ-y-1);
            cout << ans+1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}