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
     int i,n,ans=0;
    cin >> n;
    int l[n],r[n],prel[n+2],prer[n+2],sufl[n+2],sufr[n+2];
    prel[0]=sufl[n]=0;
    prer[0]=sufr[n]=INT_MAX;
    for(i=0;i<n;i++)cin >> l[i] >> r[i];
    for(i=0;i<n;i++)
    {
        prel[i+1]=max(prel[i],l[i]);
        prer[i+1]=min(prer[i],r[i]);
    }
    for(i=n-1;i>=0;i--)
    {
        sufl[i]=max(sufl[i+1],l[i]);
        sufr[i]=min(sufr[i+1],r[i]);
    }
    for(i=0;i<n;i++)
    {
        ans=max(ans,min(prer[i],sufr[i+1])-max(prel[i],sufl[i+1]));
    }
    cout << ans;
    return 0;
}