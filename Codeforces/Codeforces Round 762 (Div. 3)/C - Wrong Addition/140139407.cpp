#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
string Solve()
    string a,b,s;
    int la,ls,x,y,z;
    cin >> a >> s;
    if(a == s)return "0";
    la=(int)a.size();
    ls=(int)s.size();
    if(la > ls)return "-1";
    while(la  &&  la <= ls)
    {
        x=a.back()-'0', a.pop_back(), --la;
        y=s.back()-'0', s.pop_back(), --ls;
        if(y < x)
        {
            if(!ls)return "-1";
            z=s.back()-'0', s.pop_back(), --ls;
            y=z*10+y;
        }
        if(y-x > 9  ||  y < x)return "-1";
        b += (char)('0'+y-x);
    }
    if(la)return "-1";
    while(ls--)b += s.back(), s.pop_back();
    while(!b.empty()  &&  b.back() == '0')b.pop_back();
    if(b.empty())b="0";
    reverse(b.begin(),b.end());
    return b;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)cout << Solve() << '\n';
    return 0;
}