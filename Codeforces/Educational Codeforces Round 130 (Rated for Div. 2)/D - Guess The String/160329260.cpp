#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int last[26];
char ans[1005];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    cout << "? 1 1" << endl;
    string s;cin >> s;
    ans[1]=s[0];
    ordered_set<int>pos;
    pos.insert(1), last[s[0]-'a']=1;
    for(int i=2; i<=n; i++)
    {
        int sz=(int)pos.size();
        int l=0,r=sz-1;
        while(l <= r)
        {
            int m=(l+r) >> 1;
            cout << "? 2 " << *(pos.find_by_order(m)) << ' ' << i << endl;
            int x;cin >> x;
            if(x > sz-m)r=m-1;
            else l=m+1;
        }
        if(!l)
        {
            cout << "? 1 " << i << endl;
            string s;cin >> s;
            ans[i]=s[0], pos.insert(i), last[s[0]-'a']=i;
        }
        else
        {
            ans[i]=ans[*(pos.find_by_order(l-1))];
            pos.erase(last[ans[i]-'a']), last[ans[i]-'a']=i, pos.insert(i);
        }
    }
    cout << "! ";
    for(int i=1; i<=n; i++)cout << ans[i];
    cout << endl;
    return 0;
}