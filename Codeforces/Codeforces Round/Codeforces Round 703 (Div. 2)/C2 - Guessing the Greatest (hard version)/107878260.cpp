#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int Ask(int l,int r)
    int x;
    cout << "? " << l << ' ' << r << endl;
    cin >> x;
    return x;
void Solve(int l,int r)
    int x=Ask(l,r),y=-1,ans,mid;
    if(x != l)y=Ask(l,x);
    if(x == y)
    {
        r=x-1;
        while(l <= r)
        {
            mid=(l+r) >> 1;
            if(Ask(mid,x) == x)
            {
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
    }
    else
    {
        l=x+1;
        while(l <= r)
        {
            mid=(l+r) >> 1;
            if(Ask(x,mid) == x)
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
    }
    cout << "! " << ans << endl;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    Solve(1,n);
    return 0;
}
//