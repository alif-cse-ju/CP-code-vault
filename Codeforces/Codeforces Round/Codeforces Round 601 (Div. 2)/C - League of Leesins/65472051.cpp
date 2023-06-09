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
     //int dx[]={-1,0,0,1};
//int dy[]={0,1,-1,0};
//int dx[]= {-1,0,1,-1,1,-1,0,1};
//int dy[]= {1,1,1,0,0,-1,-1,-1};
    int cnt[100002];
V<PII>v[100002];
map<PII,V<int> >mp;
bool visited[100002];
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,n,x,y,z;
    cin >> n;
    for(i=2;i<n;i++)
    {
        cin >> x >> y >> z;
         ++cnt[x];
        ++cnt[y];
        ++cnt[z];
         v[x].PSB({y,z});
        v[y].PSB({x,z});
        v[z].PSB({x,y});
         mp[{x,y}].PSB(z);
        mp[{y,x}].PSB(z);
         mp[{x,z}].PSB(y);
        mp[{z,x}].PSB(y);
         mp[{y,z}].PSB(x);
        mp[{z,y}].PSB(x);
    }
    for(i=1;i<=n;i++)
    {
        if(cnt[i] == 1){x=i;break;}
    }
    for(auto p : v[x])
    {
        if(cnt[p.FI] == 2){y=p.FI;break;}
        if(cnt[p.SE] == 2){y=p.SE;break;}
    }
    cout << x << ' ' << y;
    visited[x]=visited[y]=true;
    z=2;
    while(z < n)
    {
        for(auto m : mp[{x,y}])
        {
            if(!visited[m])
            {
                cout << ' ' << m;
                visited[m]=true;
                x=y,y=m;
                ++z;
                break;
            }
        }
    }
    return 0;
}