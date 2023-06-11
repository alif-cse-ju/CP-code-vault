#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int _0,_1,i,l,t;
    cin >> t;
    while(t--)
    {
        cin >> l >> s;
        set<char>st;
        for(char c : s)st.insert(c);
        if((int)st.size() == 1)cout << "BOB\n";
        else
        {
            if(l & 1)cout << "ALICE\n";
            else
            {
                _0=_1=0;
                for(char c : s)
                {
                    if(c == '0')++_0;
                    else ++_1;
                }
                if(_0 == 1  ||  _1 == 1)cout << "ALICE\n";
                else cout << "BOB\n";
            }
        }
    }
    return 0;
}