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
    int a[200005],c[200005],cnt[200005];
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,k,n,ans=0,sum=0;
    cin >> n >> k;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
        ++cnt[a[i]];
    }
    for(i=1;i<=k;i++)cin >> c[i];
    for(i=k;i>0;i--)
    {
        sum+=cnt[i];
        ans=max(ans,(sum+c[i]-1)/c[i]);
    }
    cout << ans << "\n";
    V<int>v[ans];
    sort(a,a+n);
    for(i=0;i<n;i++)v[i%ans].emplace_back(a[i]);
    for(i=0;i<ans;i++)
    {
        cout << v[i].SZ;
        for(int x : v[i])cout << ' ' << x;
        cout << '\n';
    }
    return 0;
}