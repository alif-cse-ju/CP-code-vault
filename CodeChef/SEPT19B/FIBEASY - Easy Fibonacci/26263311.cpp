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
int ans[62];
void pre_cal()
{
    int i;
    ans[0]=0,ans[1]=1;
    for(i=2; i<=60; i++)
    {
        ans[i]=(ans[i-1]+ans[i-2])%10;
    }
}
int main()
{
    FAST();
    //    freopen("input.txt","r",stdin);
    //    freopen("input.txt","w",stdout);
    pre_cal();
    int t,cnt;
    LL n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n == 1)
        {
            cout << "0\n";
        }
        else
        {
            cnt=0;
            while(n > 1)
            {
                n/=2;
                cnt++;
            }
            n=pow(2,cnt);
            cout << ans[n%60-1] << '\n';
        }
    }
    return 0;
}