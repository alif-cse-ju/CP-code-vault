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
const int N=1e6+5;
const int mod=1e9+7;
string pw[65];
void PreCal()
    int i;
    for(i=0;i<61;i++)pw[i]=to_string(1ll << i);
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int ans,i,j,k,ls,lp,t;
    PreCal();
    cin >> t;
    while(t--)
    {
        cin >> s;
        ans=INT_MAX;
        ls=(int)s.size();
        for(i=0;i<61;i++)
        {
            lp=(int)pw[i].size();
            for(j=k=0;j < ls  &&  k < lp;j++)
            {
                if(s[j] == pw[i][k])++k;
            }
            ans=min(ans,lp+ls-2*k);
        }
        cout << ans << '\n';
    }
    return 0;
}