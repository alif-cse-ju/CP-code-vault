#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200000 + 10;
int n,r[N],s[N],x,y,mv=-1,m;
pair<ll,ll>a[N],b[N];
int main() 
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>x>>y,r[i]=y,s[i]=x,a[i]={y,x};
    sort(a,a+n);
    for(int i=n-1;i>=0;i--) if(a[i].second>mv) mv=a[i].second,b[m++]=a[i];
    reverse(b,b+m);
    vector<pair<ll,ll>>st;
    for(int i=0;i<m;i++)
    {
        pair<ll,ll> u,v,w;
        w=b[i];
        for(;st.size()>1;)
        {
            v=st.back(),u=st[st.size()-2];
            if((v.first-u.first)*u.second*w.first*(v.second-w.second)<(w.first-v.first)*w.second*u.first*(u.second
                st.pop_back();
            else
               break;
        }
        st.push_back(w);
            }
    set<pair<ll,ll> >ss;
    for(auto i:st) ss.insert(i);
    for(int i=0;i<n;i++) if(ss.count({r[i],s[i]})) cout<<i+1<<" ";
    return 0;
}