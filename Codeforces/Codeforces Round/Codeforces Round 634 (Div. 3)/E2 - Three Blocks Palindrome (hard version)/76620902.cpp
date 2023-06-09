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
    V<int>pos[202];
int cnt[202][200005];
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,j,l,n,t,x,y,z,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=200;i++)
        {
            pos[i].C;
            for(j=1;j<=n;j++)cnt[i][j]=0;
        }
        V<int>v;
        map<int,bool>mp;
        for(i=1;i<=n;i++)
        {
            cin >> x;
            ++cnt[x][i];
            pos[x].emplace_back(i);
            for(j=1;j<201;j++)cnt[j][i]+=cnt[j][i-1];
            if(mp.find(x) == mp.E)v.emplace_back(x),mp[x]=1;
        }
        ans=1;
        for(int x : v)
        {
            l=pos[x].SZ;
            for(i=0;i<l/2;i++)
            {
                z=0;
                for(int bal : v)z=max(z,cnt[bal][pos[x][l-i-1]-1]-cnt[bal][pos[x][i]]);
                ans=max(ans,2*(i+1)+z);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}