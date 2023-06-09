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
    V<int>adj[200002];
int n,a[200002],odd[200002],even[200002];
 void find_ans(int par,int dist[])
{
    Q<int>q;
    int i,x;
    for(i=1;i<=n;i++)
    {
        if(a[i]%2 == par)dist[i]=0,q.PS(i);
        else dist[i]=INT_MAX;
    }
    while(!q.EM)
    {
        x=q.F,q.PP;
        for(int y : adj[x])
        {
            if(dist[x]+1 < dist[y])
            {
                dist[y]=dist[x]+1;
                q.PS(y);
            }
        }
    }
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        if(i-a[i] > 0)adj[i-a[i]].PSB(i);
        if(i+a[i] <= n)adj[i+a[i]].PSB(i);
    }
    find_ans(0,even);
    find_ans(1,odd);
    for(i=1;i<=n;i++)
    {
        if(a[i] & 1)
        {
            if(even[i] == INT_MAX)cout << "-1 ";
            else cout << even[i] << ' ';
        }
        else
        {
            if(odd[i] == INT_MAX)cout << "-1 ";
            else cout << odd[i] << ' ';
        }
    }
    return 0;
}