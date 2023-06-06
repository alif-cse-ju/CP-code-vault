#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool rev=0;
    deque<char>dq;
    string s,ans="";
    cin >> s;
    for(char c : s)
    {
        if(c == 'R')rev=!rev;
        else
        {
            if(rev)dq.emplace_front(c);
            else dq.emplace_back(c);
        }
    }
    while(!dq.empty())
    {
        while(!ans.empty()  &&  !dq.empty()  &&  ans.back() == dq.front())ans.pop_back(),dq.pop_front();
        if(!dq.empty())ans+=dq.front(),dq.pop_front();
    }
    if(rev)reverse(ans.begin(),ans.end());
    cout << ans;
    return 0;
}