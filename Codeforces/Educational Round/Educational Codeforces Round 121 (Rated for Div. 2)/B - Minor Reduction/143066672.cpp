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
const int N=1e6+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool ok;
    string s;
    int i,j,l,t,x;
    cin >> t;
    while(t--)
    {
        cin >> s;
        ok=0, l=(int)s.size();
        for(i=1;i<l  &&  !ok;i++)
        {
            if(s[i]+s[i-1]-96 > 9)ok=1;
        }
        if(ok)
        {
            for(i=l-1;i;i--)
            {
                if(s[i]+s[i-1]-96 > 9)
                {
                    x=(s[i]+s[i-1]-96);
                    s[i-1]=(char)('0'+x/10);
                    s[i]=(char)('0'+x%10);
                    break;
                }
            }
            cout << s << '\n';
        }
        else
        {
            s[1] += (s[0]-'0');
            for(i=1;i<l;i++)cout << s[i];
            cout << '\n';
        }
    }
    return 0;
}