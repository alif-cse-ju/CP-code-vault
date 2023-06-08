#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
const int M=1e5+5;
int a[M];
char s[M];
deque<int>pal;
bool CheckPal()
    while((int)pal.size() > 1)
    {
        if(s[pal.front()] != s[pal.back()])return 0;
        pal.pop_front(), pal.pop_back();
    }
    return 1;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,cnt,i,j,l,ostL,small,t;
    cin >> t;
    while(t--)
    {
        cin >> l >> s+1;
        for(i=1;i<=l;i++)a[i]=(s[i]-'a');
        ans=INT_MAX;
        for(i=0;i<26;i++)
        {
            pal.clear();
            for(j=1;j<=l;j++)
            {
                if(a[j] == i)continue;
                pal.emplace_back(j);
            }
            if(CheckPal())
            {
                ordered_set<int>ostPal;
                map<int,deque<int>>ChosenCharL, ChosenCharR;
                for(j=1;j<=l;j++)
                {
                    if(a[j] == i)continue;
                    ostPal.insert(j);
                }
                ostL=(int)ostPal.size(), cnt=0;
                for(j=1;j<=l;j++)
                {
                    if(a[j] == i)
                    {
                        ++cnt;
                        small=ostPal.order_of_key(j);
                        ChosenCharL[small].emplace_back(j);
                        ChosenCharR[ostL-small].emplace_back(j);
                    }
                }
                for(auto [x,dq] : ChosenCharL)
                {
                    while(!dq.empty()  &&  !ChosenCharR[x].empty()  &&  dq.front() <= ChosenCharR[x].back())
                    {
                        if(dq.front() == ChosenCharR[x].back())--cnt;
                        else cnt -= 2;
                        dq.pop_front();
                        ChosenCharR[x].pop_back();
                    }
                }
                ans=min(ans,cnt);
            }
        }
        if(ans == INT_MAX)ans=-1;
        cout << ans << '\n';
    }
    return 0;
}