#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int k,n,x,y,z,ans=0;
    priority_queue<int,vector<int>,greater<int> >a,b,cmn;
    cin >> n >> k;
    while(n--)
    {
        cin >> x >> y >> z;
        if(y  &&  z)cmn.emplace(x);
        else if(y)a.emplace(x);
        else if(z)b.emplace(x);
    }
    while(k  &&  !a.empty()  &&  !b.empty()  &&  !cmn.empty())
    {
        k--;
        if(a.top()+b.top() >= cmn.top())ans+=cmn.top(),cmn.pop();
        else ans+=a.top()+b.top(),a.pop(),b.pop();
    }
    if(k)
    {
        if(a.empty()  ||  b.empty())
        {
            while(k  &&  !cmn.empty())ans+=cmn.top(),cmn.pop(),k--;
        }
        else
        {
            while(k  &&  !a.empty()  &&  !b.empty())ans+=a.top()+b.top(),a.pop(),b.pop(),k--;
        }
    }
    if(k)cout << "-1";
    else cout << ans;
    return 0;
}