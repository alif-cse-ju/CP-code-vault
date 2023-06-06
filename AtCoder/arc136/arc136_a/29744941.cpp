#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=3e5+5;
const int N=2e6+5;
const int mod=998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int i,j,l;
    deque<char>ans;
    cin >> l >> s;
    s="C"+s+"C";
    for(i=0;i<=l;i=j)
    {
        deque<char>dq;
        for(j=i+1;j<=l;j++)
        {
            if(s[j] == 'C')break;
            dq.emplace_back(s[j]);
        }
        if(!dq.empty())
        {
            sort(dq.begin(),dq.end());
            while(!dq.empty())
            {
                if(dq.front() == 'A')ans.emplace_back('A');
                else
                {
                    if(!ans.empty()  &&  ans.back() == 'B')ans.pop_back(), ans.emplace_back('A');
                    else ans.emplace_back('B');
                }
                dq.pop_front();
            }
        }
        if(j <= l)ans.emplace_back('C');
    }
    while(!ans.empty())cout << ans.front(), ans.pop_front();
    return 0;
}