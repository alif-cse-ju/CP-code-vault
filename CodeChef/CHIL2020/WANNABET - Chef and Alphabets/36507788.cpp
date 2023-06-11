#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update
int main()
{
    FAST();
    char c[2],s[10002];
    int i,k,l,q,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> l >> q >> s+1;
        ordered_set<int>ost[26];
        for(i=1;i<=l;i++)ost[s[i]-'a'].insert(i);
        while(q--)
        {
            cin >> x;
            if(x == 1)
            {
                cin >> x >> c;
                ost[s[x]-'a'].erase(x);
                s[x]=c[0];
                ost[s[x]-'a'].insert(x);
            }
            else
            {
                cin >> x >> y >> k;
                vector<int>v;
                l=ost[0].order_of_key(y+1)-ost[0].order_of_key(x);
                v.emplace_back(l);
                for(i=1;i<26;i++)
                {
                    l=ost[i].order_of_key(y+1)-ost[i].order_of_key(x);
                    v.emplace_back(l);
                    v[i]+=v[i-1];
                }
                l=lower_bound(v.begin(),v.end(),k)-v.begin();
                cout << (char)('a'+l) << '\n';
            }
        }
    }
    return 0;
}