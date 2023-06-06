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

const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;

char s[M];
vector<int>pos[26];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,n,r;
    cin >> n >> s+1;
    for(i=1;i<=n;i++)pos[s[i]-'a'].emplace_back(i);
    l=1,r=n;
    for(i=0;i<26  &&  l < r;i++)
    {
        while(!pos[i].empty()  &&  pos[i].back() > r)pos[i].pop_back();
        while(!pos[i].empty())
        {
            while(l < pos[i].back()  &&  s[l] <= (char)('a'+i))++l;
            if(l < pos[i].back())r=pos[i].back(), swap(s[l++],s[r]), pos[i].pop_back();
            else break;
        }
    }
    for(i=1;i<=n;i++)cout << s[i];
    return 0;
}