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
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int ans,i,j,l,t;
    cin >> t;
    while(t--)
    {
        cin >> s;
        ans=100;
        l=(int)s.size();
        for(i=l-1;i>=0;i--)
        {
            if(s[i] == '0')
            {
                for(j=i-1;j>=0;j--)
                {
                    if(s[j] == '5'  ||  s[j] == '0')
                    {
                        ans=min(ans,l-j-1);
                        break;
                    }
                }
                break;
            }
        }
        for(i=l-1;i>=0;i--)
        {
            if(s[i] == '5')
            {
                for(j=i-1;j>=0;j--)
                {
                    if(s[j] == '2'  ||  s[j] == '7')
                    {
                        ans=min(ans,l-j-1);
                        break;
                    }
                }
                break;
            }
        }
        cout << ans-1 << '\n';
    }
    return 0;
}