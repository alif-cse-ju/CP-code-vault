#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int mod=1e9+7;
struct point {
    int x,y;
    point() {}
    point(int a,int b)
    {
        x=a,y=b;
    }
};
long long operator *(point a,point b)
{
    return 1ll*a.x*b.y-1ll*a.y*b.x;
}
point operator -(point a,point b)
{
    return point(a.x-b.x,a.y-b.y);
}
int a[N];
void Solve()
{
    point now;
    int i,n,ans=1;
    cin >> n;
    for(i=0;i<n;i++)cin >> a[i];
    vector<point>v;
    v.emplace_back(point(a[0],0));
    v.emplace_back(point(a[1],1));
    for(i=2;i<n;i++)
    {
        now=point(a[i],i);
        while((int)v.size() > 1  &&  (now-v[(int)v.size()-2])*(v[(int)v.size()-1]-v[(int)v.size()-2]) >= 0)v.pop_back
        ans=max(ans,i-v.back().y);
        v.emplace_back(now);
    }
    cout << ans << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)Solve();
    return 0;
}
//