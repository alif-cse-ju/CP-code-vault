#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
const int N=2e5+5;
int n,sum[N],up[N];
void Update(int idx)
    while(idx <= n)
    {
        ++up[idx];
        idx+=idx & (-idx);
    }
int Query(int idx)
    int ans=0;
    while(idx > 0)
    {
        ans+=up[idx];
        idx-=idx & (-idx);
    }
    return ans;
int main()
    FAST();
    int ans,i,k,l,m,r,t,x;
    cin >> n >> t;
    for(i=1;i<=n;i++)sum[i]=INT_MIN;
    while(t--)
    {
        cin >> k;
        l=1,r=n;
        while(l <= r)
        {
            m=(l+r) >> 1;
            if(sum[m] > INT_MIN)x=sum[m]+Query(m);
            else
            {
                cout << "? 1 " << m << endl;
                cin >> x;
                sum[m]=x-Query(m);
            }
            if(m-k >= x)ans=m,r=m-1;
            else l=m+1;
        }
        cout << "! " << ans << endl;
        Update(ans);
    }
    return 0;
}