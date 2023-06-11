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
const int N=1e5+1;
multiset<int>st[2*N+5];
int main()
{
    FAST();
    int i,h,l,n,q,r,x,ans;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> x >> h;
        h+=N;
        st[h].insert(x);
    }
    cin >> q;
    while(q--)
    {
        cin >> l >> r >> h;
        h+=N,ans=0;
        while(true)
        {
            auto it=st[h].lower_bound(l);
            if(it == st[h].end()  ||  *(it) > r)break;
            ++ans,st[h].erase(it);
        }
        cout << ans << '\n';
    }
    return 0;
}