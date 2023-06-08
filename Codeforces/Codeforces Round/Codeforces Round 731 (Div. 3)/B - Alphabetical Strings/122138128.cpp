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
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    bool val;
    int i,l,r,t;
    cin >> t;
    while(t--)
    {
        cin >> s;
        val=0;
        for(i=0;i<(int)s.size();i++)
        {
            if(s[i] == 'a')l=r=i,val=1;
        }
        if(val)
        {
            for(i=1;i<(int)s.size()  &&  val;i++)
            {
                if(l-1 >= 0  &&  i == (s[l-1]-'a'))--l;
                else if(r+1 < (int)s.size()  &&  i == (s[r+1]-'a'))++r;
                else val=0;
            }
        }
        if(val)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}