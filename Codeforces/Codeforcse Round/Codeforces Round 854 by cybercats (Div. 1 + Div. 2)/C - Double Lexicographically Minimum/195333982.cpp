#pragma GCC optimize("Ofast")
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <chrono>
#include <random>
#include <vector>
#include <climits>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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
const int N=1e6+5;
const int mod=1e9+7;
 char ans[M];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        string s;cin >> s;
        vector<int>cnt(26, 0);
        for(char &c : s)++cnt[c-'a'];
        int l=(int)s.size(), L=1, R=l;
        for(int i=0;i<26;i++)
        {
            while(cnt[i] > 1)cnt[i]-=2, ans[L++]=(char)('a'+i), ans[R--]=(char)('a'+i);
            if(cnt[i])
            {
                int extra=0, p=-1;
                for(int j=i+1;j<26;j++)
                {
                    if(cnt[j])++extra, p=j;
                }
                if(extra <= 1)
                {
                    if(p != -1)
                    {
                        while(cnt[p] > 1)cnt[p]-=2, ans[L++]=(char)('a'+p), ans[R--]=(char)('a'+p);
                        if(cnt[p])ans[L++]=(char)('a'+p);
                    }
                }
                else
                {
                    for(int j=i+1;j<26;j++)
                    {
                        while(cnt[j])cnt[j]--, ans[L++]=(char)('a'+j);
                    }
                }
                ans[L]=(char)('a'+i);
                break;
            }
        }
        for(int i=1;i<=l;i++)cout << ans[i];
        cout << '\n';
    }
    return 0;
}