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
int main()
{
    FAST();
    LL x,ans;
    int i,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<LL>v;
        while(n--)cin >> x,v.emplace_back(x);
        sort(v.B,v.E);
        ans=0;
        while(v.SZ > 2)
        {
            v.PPB;
            v.PPB;
            ans+=v.back();
            v.PPB;
        }
        cout << ans << '\n';
    }
    return 0;
}