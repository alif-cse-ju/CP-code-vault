#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
long long p[M];
int main()
{
    FAST();
    int i,n,q;
    long long k,x,y,z,ans;
    cin >> n;
    set<int>st;
    for(i=1;i<=n;i++)
    {
        cin >> p[i];
        st.insert(i);
    }
    cin >> q;
    while(q--)
    {
        ans=0;
        cin >> x >> k;
        while(k)
        {
            auto it=st.lower_bound(x);
            if(it == st.end())break;
            y=*(it),z=min(k,p[y]);
            ans+=z*(y-x),p[y]-=z,k-=z;
            if(!p[y])st.erase(y);
        }
        cout << ans << '\n';
    }
    return 0;
}