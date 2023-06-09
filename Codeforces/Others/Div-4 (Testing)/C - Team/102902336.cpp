#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,k,n,x,y,ans=0;
    multiset<int>mst;
    cin >> n >> k;
    for(i=0;i<n;i++)
    {
        cin >> x;
        mst.insert(x);
    }
    while(!mst.empty())
    {
        x=*(--mst.end());
        if(x < k)break;
        ++ans;
        auto it=mst.find(x);
        mst.erase(it);
    }
    while((int)mst.size() > 1)
    {
        x=*(--mst.end());
        auto it=mst.find(x);
        mst.erase(it);
        it=mst.lower_bound(k-x);
        if(it == mst.end())break;
        ++ans;
        mst.erase(it);
    }
    cout << ans;
    return 0;
}