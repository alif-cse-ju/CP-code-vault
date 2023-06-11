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
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int cnt[26];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int i,l,t;
    cin >> t;
    while(t--)
    {
        cin >> l >> s;
        if(l & 1)cout << "NO\n";
        else
        {
            memset(cnt,0,sizeof(cnt));
            for(char c : s)++cnt[c-'a'];
            for(i=0;i<26  &&  cnt[i] <= l/2;i++);
            if(i < 26)cout << "NO\n";
            else
            {
                cout << "YES\n";
                sort(s.begin(),s.end());
                for(i=0;i<l/2;i++)cout << s[i];
                for(i=l-1;i>=l/2;i--)cout << s[i];
                cout << '\n';
            }
        }
    }
    return 0;
}