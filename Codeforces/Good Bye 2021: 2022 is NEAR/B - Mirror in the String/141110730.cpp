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
char s[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,l,t;
    cin >> t;
    while(t--)
    {
        cin >> l >> s+1;
        if(l == 1)
        {
            cout << s[1] << s[1] << '\n';
            continue;
        }
        if(s[1] <= s[2])
        {
            cout << s[1] << s[1] << '\n';
            continue;
        }
        for(i=2;i<=l;i++)
        {
            if(s[i] > s[i-1])break;
        }
        if(i > l)
        {
            for(i=1;i<=l;i++)cout << s[i];
            for(i=l;i;i--)cout << s[i];
            cout << '\n';
        }
        else
        {
            for(j=1;j<i;j++)cout << s[j];
            for(j=i-1;j;j--)cout << s[j];
            cout << '\n';
        }
    }
    return 0;
}