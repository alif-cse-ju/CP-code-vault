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
int cnt[26];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,t;
    string a,b;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        memset(cnt,0,sizeof(cnt));
        for(char c : a)++cnt[c-'a'];
        sort(a.begin(),a.end());
        if(cnt[0]  &&  cnt[1]  &&  cnt[2]  &&  b == "abc")
        {
            while(cnt[0]--)cout << 'a';
            while(cnt[2]--)cout << 'c';
            while(cnt[1]--)cout << 'b';
            for(i=3;i<26;i++)
            {
                while(cnt[i]--)cout << (char)('a'+i);
            }
            cout << '\n';
        }
        else cout << a << '\n';
    }
    return 0;
}