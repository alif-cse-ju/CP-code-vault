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
    V<string>digits={
    "1110111",
    "0010010",
    "1011101",
    "1011011",
    "0111010",
    "1101011",
    "1101111",
    "1010010",
    "1111111",
    "1111011"
};
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     char x,y;
    int d,i,j,k,n,ans;
    cin >> n >> k;
    V<string>s(n);
    V<V<int> >dist(n,V<int>(10));
    for(i=0;i<n;i++)
    {
        cin >> s[i];
        for(d=0;d<10;d++)
        {
            for(j=0;j<7;j++)
            {
                x=s[i][j];
                y=digits[d][j];
                if(x == '1'  &&  y == '0')
                {
                    dist[i][d]=-1;
                    break;
                }
                if(x == '0'  &&  y == '1')++dist[i][d];
            }
        }
    }
    V<V<int> >dp(n+1,V<int>(k+1));
    dp[n][0]=1;
    for(i=n;i>0;i--)
    {
        for(j=0;j<=k;j++)
        {
            if(dp[i][j])
            {
                for(d=0;d<10;d++)
                {
                    if(dist[i-1][d] != -1  &&  j+dist[i-1][d] <= k)dp[i-1][j+dist[i-1][d]]=1;
                }
            }
        }
    }
    if(dp[0][k] == 0)
    {
        cout << "-1";
        return 0;
    }
    for(i=0;i<n;i++)
    {
        ans=-1;
        for(d=9;d>-1;d--)
        {
            if(dist[i][d] != -1  &&  k >= dist[i][d]  &&  dp[i+1][k-dist[i][d]])
            {
                ans=d;
                k-=dist[i][d];
                break;
            }
        }
        cout << ans;
    }
    return 0;
}