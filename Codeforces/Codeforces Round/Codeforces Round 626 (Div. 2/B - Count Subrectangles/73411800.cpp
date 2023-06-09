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
    LL cnt[2][40005];
 void makeCnt(V<int>v,int row,int n)
{
    int i=0,j,k;
    while(i < n)
    {
        if(v[i] == 0)i++;
        else
        {
            j=i;
            while(j < n  &&  v[j] == 1)++j;
            for(k=1;k<=j-i;k++)cnt[row][k]+=j-i-k+1;
            i=j;
        }
    }
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,m,n;
    LL k,ans=0;
    cin >> n >> m >> k;
    V<int>a(n),b(m);
    for(i=0;i<n;i++)cin >> a[i];
    for(i=0;i<m;i++)cin >> b[i];
    makeCnt(a,0,n);
    makeCnt(b,1,m);
    for(i=1;i<40001;i++)
    {
        if(k%i == 0  &&  k/i <= m)ans+=cnt[0][i]*cnt[1][k/i];
    }
    cout << ans;
    return 0;
}