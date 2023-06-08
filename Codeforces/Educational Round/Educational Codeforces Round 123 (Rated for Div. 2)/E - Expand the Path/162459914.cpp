#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=998244353;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        ll n;cin >> n;
        string s;cin >> s;
        int D=0, R=0;
        for(char &c : s)
        {
            if(c == 'D')++D;
            else ++R;
        }
        if(!D  ||  !R)cout << n << '\n';
        else
        {
            int rID;
            for(int i=0;i<(int)s.size();i++)
            {
                if(s[i] == 'R')
                {
                    rID=i;
                    break;
                }
            }
            ll ans=n*n - 1ll*(n-1)*rID, tmp=0;
            for(int i=(int)s.size()-1;i>rID;i--)
            {
                if(s[i] == 'D')ans -= tmp;
                else ++tmp;
            }
             for(char &c : s)
            {
                if(c == 'D')c='R';
                else c='D';
            }
             for(int i=0;i<(int)s.size();i++)
            {
                if(s[i] == 'R')
                {
                    rID=i;
                    break;
                }
            }
            ans=ans - 1ll*(n-1)*rID, tmp=0;
            for(int i=(int)s.size()-1;i>rID;i--)
            {
                if(s[i] == 'D')ans -= tmp;
                else ++tmp;
            }
             cout << ans << '\n';
        }
    }
    return 0;
}