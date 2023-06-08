#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;
void Type1(int n,int x,int y,int z,int xy,int xz)
    cout << "YES\n";
    int cnt=3,last=x;
    for(int i=1;i<xy;i++)cout << last << ' ' << ++cnt << '\n', last=cnt;
    cout << y << ' ' << last << '\n', last=x;
    for(int i=1;i<xz;i++)cout << last << ' ' << ++cnt << '\n', last=cnt;
    cout << z << ' ' << last << '\n';
    while(cnt < n)cout << x << ' ' << ++cnt << '\n';
void Type2(int n,int d12,int d23,int d31)
    vector<pair<int,int>>edges;
    int cnt=3;
    for(int i=1;i<d31;i++)edges.emplace_back(cnt,cnt+1), ++cnt;
    if(cnt > n)
    {
        cout << "NO\n";
        return;
    }
    edges.emplace_back(1,cnt);
    for(int i=4;i<=cnt;i++)
    {
        if(d23-(i-3) > 0  &&  d23-(i-3) == d12-(cnt-i+1)  &&  cnt+d23-(i-3)-1 <= n)
        {
            int last=i;
            for(int j=1;j<d23-(i-3);j++)edges.emplace_back(last,++cnt), last=cnt;
            edges.emplace_back(2,last);
            while(cnt < n)edges.emplace_back(1,++cnt);
            cout << "YES\n";
            for(auto [x,y] : edges)cout << x << ' ' << y << '\n';
            return;
        }
    }
    cout << "NO\n";
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int d12,d23,d31,n;cin >> n >> d12 >> d23 >> d31;
        if(d12+d31 == d23)
        {
            if(d23+1 <= n)Type1(n,1,2,3,d12,d31);
            else cout << "NO\n";
        }
        else if(d12+d23 == d31)
        {
            if(d31+1 <= n)Type1(n,2,1,3,d12,d23);
            else cout << "NO\n";
        }
        else if(d23+d31 == d12)
        {
            if(d12+1 <= n)Type1(n,3,1,2,d31,d23);
            else cout << "NO\n";
        }
        else Type2(n,d12,d23,d31);
    }
    return 0;
}