#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    set<int>st;
    int i,j=0,n,it,sz,a[1002];
    vector<int>dis,pos[1002];
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i],st.insert(a[i]);
    for(int x : st)dis.emplace_back(x);
    for(i=1;i<=n;i++)
    {
        it=lower_bound(dis.begin(),dis.end(),a[i])-dis.begin()+1;
        pos[it].emplace_back(i);
    }
    sz=st.size();
    for(i=1;i<=sz;i++)
    {
        for(int x : pos[i])a[++j]=x;
    }
    vector<pair<int,int>>ans;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<n;j++)
        {
            if(a[j] > a[j+1])ans.emplace_back(a[j+1],a[j]),swap(a[j],a[j+1]);
        }
    }
    cout << ans.size() << '\n';
    for(auto it : ans)cout << it.first << ' ' << it.second << '\n';
    return 0;