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
        int l;cin >> l;
        string s;cin >> s;
        int _1=0;
        for(char &c : s)_1 += (c == '1');
        if(!_1  ||  (_1 & 1))cout << "NO\n";
        else
        {
            cout << "YES\n";
            for(int i=0;i<l;i++)
            {
                if(s[i] == '1')
                {
                    i=(i+1)%l;
                    int last=i;
                    for(int j=i+1;j<i+l;j++)
                    {
                        cout << (last%l)+1 << ' ' << (j%l)+1 << '\n';
                        if(s[j%l] == '1')last=i;
                        else last=j;
                    }
                    break;
                }
            }
        }
    }
    return 0;
}