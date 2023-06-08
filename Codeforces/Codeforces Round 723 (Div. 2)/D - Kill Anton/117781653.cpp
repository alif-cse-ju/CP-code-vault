#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
char s[M];
vector<int>pos[4];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,t;
    long long cnt;
    cin >> t;
    while(t--)
    {
        cin >> s+1;
        l=strlen(s+1);
        for(i=0;i<4;i++)pos[i].clear();
        for(i=1;i<=l;i++)
        {
            if(s[i] == 'A')pos[0].emplace_back(i);
            else if(s[i] == 'N')pos[1].emplace_back(i);
            else if(s[i] == 'O')pos[2].emplace_back(i);
            else pos[3].emplace_back(i);
        }
        vector<int>v={0,1,2,3};
        vector<pair<long long,string>>ans;
        do
        {
            cnt=0;
            string temp="";
            ordered_set<int>ost;
            for(int x : v)
            {
                for(int y : pos[x])
                {
                    temp+=s[y];
                    cnt+=(int)ost.size()-ost.order_of_key(y);
                    ost.insert(y);
                }
            }
            ans.emplace_back(cnt,temp);
        }
        while(next_permutation(v.begin(),v.end()));
        sort(ans.begin(),ans.end());
        cout << ans.back().second << '\n';
    }
    return 0;
}