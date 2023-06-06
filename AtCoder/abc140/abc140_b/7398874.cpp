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




int i,n,a[23],b[23],c[23],ans;

int main()
{
    FAST();

    //    freopen("input.txt","r",stdin);
    //    freopen("input.txt","w",stdout);

    cin >> n;
    for(i=1; i<=n; i++)cin >> a[i];
    for(i=1; i<=n; i++)cin >> b[i];
    for(i=1; i<n; i++)cin >> c[i];
    ans=b[a[1]];
    for(i=2; i<=n; i++)
    {
        ans+=b[a[i]];
        if(a[i]-a[i-1] == 1)
        {
            ans+=c[a[i]-1];
        }
    }
    cout << ans;
    return 0;
}
