#include<bits/stdc++.h>

using namespace std;

#define G getline
#define C clear()
#define B begin()
#define F front()
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
#define PLI pair<LL,int>
#define PLL pair<LL,LL>
#define MII map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define MLI map<LL,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)





//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};




const int N=2e5+5;
const int mod=1e9+7;

priority_queue<pair<LL,LL>>pq;

int main()
{
    FAST();
    int i,n,ans;
    long long x,y,Aoki=0,Takeshi=0;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> x >> y;
        Takeshi+=x+y;
        pq.emplace(-x-x-y,x);
    }
    ans=n;
    while(true)
    {
        x=pq.top().second;
        y=-pq.top().first-x;
        if(Takeshi-y > Aoki+x)
        {
            Takeshi-=y;
            Aoki+=x;
            --ans;
            pq.pop();
        }
        else break;
    }
    cout << ans;
    return 0;
}
