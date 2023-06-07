#pragma GCC optimize("Ofast")
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
const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;
char a[M],b[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int l;cin >> l >> a+1 >> b+1;
        deque<int>pos[3];
        bool ok=1;
        for(int i=1,j=1;i<=l  &&  ok;i++)
        {
            if(a[i] == 'a')
            {
                if(pos[0].empty())
                {
                    while(j<=l  &&  b[j] != 'a')pos[b[j]-'a'].emplace_back(j++);
                    if(j > l)
                    {
                        ok=0;
                        break;
                    }
                    pos[b[j]-'a'].emplace_back(j++);
                }
                if(!pos[2].empty()  &&  pos[2].front() < pos[0].front())ok=0;
                else pos[0].pop_front();
            }
            else if(a[i] == 'b')
            {
                if(pos[1].empty())
                {
                    while(j<=l  &&  b[j] != 'b')pos[b[j]-'a'].emplace_back(j++);
                    if(j > l)
                    {
                        ok=0;
                        break;
                    }
                    pos[b[j]-'a'].emplace_back(j++);
                }
                if(!pos[0].empty()  &&  pos[0].front() < pos[1].front())ok=0;
                else pos[1].pop_front();
            }
            else
            {
                if(pos[2].empty())
                {
                    while(j<=l  &&  b[j] != 'c')pos[b[j]-'a'].emplace_back(j++);
                    if(j > l)
                    {
                        ok=0;
                        break;
                    }
                    pos[b[j]-'a'].emplace_back(j++);
                }
                if(!pos[0].empty()  ||  !pos[1].empty())ok=0;
                else pos[2].pop_front();
            }
        }
        if(ok)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}