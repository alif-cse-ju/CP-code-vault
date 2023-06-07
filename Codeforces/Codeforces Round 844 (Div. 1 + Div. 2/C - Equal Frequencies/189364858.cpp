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
 char s[M],ss[M];
vector<int>pos[26];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int l;cin >> l >> s+1;
        for(int i=0;i<26;i++)pos[i].clear();
        for(int i=1;i<=l;i++)pos[s[i]-'a'].emplace_back(i), ss[i]=s[i];
        int ans=INT_MAX,id;
        for(int i=1;i<l;i++)
        {
            if(l%i  ||  l/i > 26)continue;
            priority_queue<int>pq;
            for(int j=0;j<26;j++)
            {
                if(!pos[j].empty())pq.emplace((int)pos[j].size());
            }
            int cnt=0,k=l/i;
            while(!pq.empty()  &&  k)cnt+=min(i,pq.top()), pq.pop(), --k;
            if(l-cnt < ans)ans=l-cnt, id=i;
        }
        int allSame=INT_MAX;
        for(int i=0;i<26;i++)allSame=min(allSame, l-(int)pos[i].size());
        if(allSame <= ans)
        {
            cout << allSame << '\n';
            for(int i=0;i<26;i++)
            {
                if(l-(int)pos[i].size() == allSame)id=i;
            }
            for(int i=1;i<=l;i++)cout << (char)('a'+id);
            cout << '\n';
            continue;
        }
        vector<int>choto, boro;
        int lagbe=l/id;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<26;i++)
        {
            if(!pos[i].empty())pq.emplace((int)pos[i].size(),i);
        }
        while(!pq.empty())
        {
            if(pq.top().first >= id)--lagbe;
            if(lagbe > 0  &&  pq.top().first < id)--lagbe, choto.emplace_back(pq.top().second);
            else if(pq.top().first != id)boro.emplace_back(pq.top().second);
            pq.pop();
        }
        for(int i=0;i<26  &&  lagbe > 0;i++)
        {
            if(pos[i].empty())choto.emplace_back(i), --lagbe;
        }
        while(!boro.empty())
        {
            ss[pos[boro.back()].back()]=(char)('a'+choto.back());
            pos[choto.back()].emplace_back(pos[boro.back()].back());
            pos[boro.back()].pop_back();
            if((int)pos[choto.back()].size() == id)choto.pop_back();
            if((int)pos[boro.back()].size() == id  ||  pos[boro.back()].empty())boro.pop_back();
        }
        cout << ans << '\n';
        for(int i=1;i<=l;i++)cout << ss[i];
        cout << '\n';
    }
    return 0;
}