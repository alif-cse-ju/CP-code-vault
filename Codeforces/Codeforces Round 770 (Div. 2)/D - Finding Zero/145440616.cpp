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
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        set<int>st1,st2;
        priority_queue<pair<int,int>>pq;
        for(i=3;i<=n;i++)
        {
            cout << "? 1 2 " << i << endl;
            cin >> x, st1.insert(x), pq.emplace(x,i);
        }
        j=pq.top().second;
        while(!pq.empty())pq.pop();
        for(i=2;i<=n;i++)
        {
            if(i == j)continue;
            cout << "? 1 " << j << ' ' << i << endl;
            cin >> x, st2.insert(x), pq.emplace(x,i);
        }
        if((int)st2.size() == 1)cout << "! 1 " << j << endl;
        else if((int)st1.size() == 1  &&  *(st1.begin()) == *(--st2.end()))cout << "! 1 2" << endl;
        else cout << "! " << j << ' ' << pq.top().second << endl;
    }
    return 0;
}