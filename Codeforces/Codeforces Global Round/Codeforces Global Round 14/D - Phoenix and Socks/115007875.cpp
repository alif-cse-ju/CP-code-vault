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
int lCnt[N],rCnt[N];
int main()
    FAST();
    int i,il,ir,l,n,r,t,x,ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> l >> r;
        for(i=1;i<=n;i++)lCnt[i]=rCnt[i]=0;
        for(i=1;i<=n;i++)
        {
            cin >> x;
            if(i <= l)++lCnt[x];
            else ++rCnt[x];
        }
        ans=0;
        priority_queue<pair<int,pair<int,int>>>L,R;
        for(i=1;i<=n;i++)
        {
            x=min(lCnt[i],rCnt[i]);
            lCnt[i]-=x,rCnt[i]-=x;
            L.push({(lCnt[i] & 1),{-lCnt[i],i}});
            R.push({(rCnt[i] & 1),{-rCnt[i],i}});
        }
        while(!L.empty()  &&  !R.empty())
        {
            l=-L.top().second.first,il=L.top().second.second,L.pop();
            r=-R.top().second.first,ir=R.top().second.second,R.pop();
            if(l  &&  r  &&  ((l & 1)  ||  (r & 1)))x=1;
            else x=min(l,r);
            l-=x,r-=x,lCnt[il]-=x,rCnt[ir]-=x,ans+=x;
            if(l)L.push({(l & 1),{-l,il}});
            if(r)R.push({(r & 1),{-r,ir}});
        }
        l=r=0;
        for(i=1;i<=n;i++)
        {
            ans+=lCnt[i]/2+rCnt[i]/2;
            l+=(lCnt[i] & 1),r+=(rCnt[i] & 1);
        }
        cout << ans+l+r << '\n';
    }
    return 0;
}