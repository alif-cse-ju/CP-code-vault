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
    int n,m,d,c[1002],ans[1005];
bool dp[1002][1002];
bool ache;
 void run_DP(int idx,int cur)
{
    if(ache)return;
    if(cur > n  ||  dp[idx][cur])return;
    dp[idx][cur]=true;
    if(idx == m)
    {
        if(cur+c[idx]-1 <= n  &&  cur+d+c[idx]-2+d > n)
        {
            ache=true;
            int x=cur+d+c[idx]-2;
            while(x > n)--x;
            while(c[m]--)ans[x--]=idx;
        }
        return;
    }
    for(int i=cur; i<cur+d  &&  !ache; i++)
    {
        run_DP(idx+1,i+c[idx]);
        if(ache)
        {
            for(int j=i; j<i+c[idx]; j++)ans[j]=idx;
            return;
        }
    }
}
 int main()
{
    FAST();
     //    freopen("input.txt","r",stdin);
    //    freopen("output.txt","w",stdout);
     int i;
    cin >> n >> m >> d;
    for(i=1; i<=m; i++)cin >> c[i];
    if(m == 1)
    {
        if(d+c[1]+d-1 > n)
        {
            cout << "YES\n";
            if(d+c[1]-1 <= n)
            {
                for(i=d; i<d+c[1]; i++)ans[i]=1;
            }
            else
            {
                i=n;
                while(c[1]--)ans[i--]=1;
            }
            for(i=1; i<=n; i++)cout << ans[i] << ' ';
        }
        else cout << "NO";
        return 0;
    }
    run_DP(1,1);
    if(ache)
    {
        cout << "YES\n";
        for(i=1; i<=n; i++)cout << ans[i] << ' ';
    }
    else cout << "NO";
    return 0;
}