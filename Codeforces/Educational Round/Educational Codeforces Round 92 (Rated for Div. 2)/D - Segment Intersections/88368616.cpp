#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int t;
    LL i,k,n,ans,cur,cmn,dif,l,l1,l2,r1,r2,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        cin >> l1 >> r1 >> l2 >> r2;
        x=max(l1,l2),y=min(r1,r2);
        cmn=max(0LL,(y-x));
        cur=cmn*n;
        if(cur >= k)
        {
            cout << "0\n";
            continue;
        }
        if(r1 < l2)dif=l2-r1;
        else if(r2 < l1)dif=l1-r2;
        else dif=0LL;
        ans=0LL;
        x=min(l1,l2),y=max(r1,r2),l=y-x-cmn;
        for(i=1;i<=n;i++)
        {
            if(i > 1 &&  2LL*(k-cur) <= dif+min(l,k-cur))
            {
                ans+=2LL*(k-cur);
                cur=k;
                break;
            }
            ans+=dif+min(l,k-cur);
            cur+=min(l,k-cur);
            if(cur >= k)break;
        }
        if(cur < k)ans+=(k-cur)*2LL;
        cout << ans << '\n';
    }
    return 0;
}