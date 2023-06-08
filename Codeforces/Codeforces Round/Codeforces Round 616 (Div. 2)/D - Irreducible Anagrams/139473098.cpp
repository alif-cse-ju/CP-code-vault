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
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
char s[M];
int cnt[26][M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cntt,i,j,l,q,r;
    cin >> s+1;
    l=strlen(s+1);
    for(i=1;i<=l;i++)++cnt[s[i]-'a'][i];
    for(i=0;i<26;i++)
    {
        for(j=2;j<=l;j++)cnt[i][j] += cnt[i][j-1];
    }
    cin >> q;
    while(q--)
    {
        cin >> l >> r;
        if(l == r)cout << "Yes\n";
        else
        {
            cntt=0;
            for(i=0;i<26;i++)cntt += ((cnt[i][r]-cnt[i][l-1]) > 0);
            if(cntt > 2  ||  s[l] != s[r])cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}