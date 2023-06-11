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
int main()
{
    FAST();
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    LL j,ans;
    bool flag;
    int i,l,n,t;
    string a,b;
    cin >> t;
    while(t--)
    {
        V<int>lens;
        cin >> a >> b;
        n=a.SZ,ans=0,l=0,flag=false;
        for(i=0;i<n;i++)
        {
            if(a[i] != b[i])
            {
                if(l > 0  &&  flag)lens.emplace_back(l),ans+=l;
                l=0,flag=true,++ans;
            }
            else ++l;
        }
        n=ans;
        sort(lens.B,lens.E,greater<int>());
        for(j=0;j<lens.SZ;j++)
        {
            n-=lens[j];
            ans=min(ans,(j+2)*n);
        }
        cout << ans << "\n";
    }
    return 0;
}