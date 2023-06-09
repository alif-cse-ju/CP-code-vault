#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PI acos(-1)
#define PB push_back
#define MP make_pair
#define LL long long int
#define PII pair<int,int>
#define PLL pair<long long int,long long int>
#define MII map<int,int>
#define MSI map<string,int>
#define MLI map<long long int,int>
vector<PII>v;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,n,m,x;
    cin >> n >> m;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        v.PB(MP(x,i));
    }
    for(i=0; ;i++)
    {
        if(i == v.size()-1)
        {
            cout << v[i].S;
            return 0;
        }
        v[i].F-=m;
        if(v[i].F > 0)
        {
            v.PB(v[i]);
        }
    }
    return 0;
}