#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=4e5+5;
const int N=1e6+5;
const int mod=1e9+7;
char s[N];
int even[N],odd[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,q,r,t;
    cin >> t;
    while(t--)
    {
        cin >> s+1;
        l=strlen(s+1);
        for(i=1;i<=l;i++)
        {
            odd[i] = odd[i-1], even[i] = even[i-1];
            if(s[i] == '['  ||  s[i] == ']')continue;
            odd[i] += (i & 1), even[i] += !(i & 1);
        }
        cin >> q;
        while(q--)
        {
            cin >> l >> r, --l;
            cout << abs((even[r]-even[l])-(odd[r]-odd[l])) << '\n';
        }
    }
    return 0;
}