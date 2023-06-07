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
bool mark[26];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int i,j,l,t;
    cin >> t;
    while(t--)
    {
        cin >> s;
        l=(int)s.size();
        memset(mark,0,sizeof(mark));
        for(i=l-1;i>=0;i--)
        {
            if(!mark[s[i]-'a'])j=i, mark[s[i]-'a']=1;
        }
        for(i=j;i<l;i++)cout << s[i];
        cout << '\n';
    }
    return 0;
}