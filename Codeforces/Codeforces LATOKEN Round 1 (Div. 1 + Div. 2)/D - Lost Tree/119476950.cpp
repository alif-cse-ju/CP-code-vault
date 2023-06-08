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
const int M=1e5+5;
const int N=2e3+5;
const int mod=1e9+7;
int d[N];
vector<int>adj[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n;
    set<int>st;
    deque<int>v;
    cin >> n;
    cout << "? 1" << endl;
    for(i=1;i<=n;i++)
    {
        cin >> d[i];
        st.insert(i);
        if(d[i]%2 == 0)v.emplace_back(i);
    }
    if((int)v.size() <= (n+1)/2)
    {
        for(i=1;i<=n;i++)
        {
            if(d[i] == 1)adj[1].emplace_back(i);
        }
        v.pop_front();
    }
    else
    {
        for(int it : v)st.erase(it);
        v.clear();
        for(int it : st)v.emplace_back(it);
    }
    for(int it : v)
    {
        cout << "? " << it << endl;
        for(i=1;i<=n;i++)
        {
            cin >> d[i];
            if(i == it)continue;
            if(d[i] == 1)adj[it].emplace_back(i);
        }
    }
    cout << "!" << endl;
    for(i=1;i<=n;i++)
    {
        if(!adj[i].empty())
        {
            for(int it : adj[i])cout << i << ' ' << it << endl;
        }
    }
    return 0;
}