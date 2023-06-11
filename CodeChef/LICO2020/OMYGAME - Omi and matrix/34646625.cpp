#include<bits/stdc++.h>
using namespace std;
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
#define LL long long
#define ULL unsigned long long
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
LL x,ans,b[1002];
int main()
{
    FAST();
    int i,j,k,n;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin >> x;
            if(i == j)continue;
            for(k=0;k<31;k++)
            {
                if((x >> k) & 1)
                {
                    b[i] |= (1 << k);
                    b[j] |= (1 << k);
                }
            }
        }
    }
    for(i=1;i<=n;i++)ans+=b[i];
    cout << ans;
    return 0;
}