#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
char s[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,l,r,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> l >> k >> s+1;
        deque<pair<int,pair<int,int>>>v;
        for(i=1;i<=l;i++)
        {
            if(s[i] == 'L')
            {
                for(j=i;j<=l  &&  s[j] == 'L';j++);
                v.push_back({j-i,{i,j-1}});
                i=j;
            }
        }
        if(!v.empty()  &&  v.front().second.first == 1)v.pop_front();
        if(!v.empty()  &&  v.back().second.second == l)v.pop_back();
        sort(v.begin(),v.end());
        for(auto it : v)
        {
            j=min(k,it.first),k-=j,l=it.second.first,r=it.second.second;
            while(j--)s[l++]='W';
            if(!k)break;
        }
        ans=0,s[0]='L',l=strlen(s+1);
        if(k)
        {
            for(i=1;i<=l  &&  s[i] == 'L';i++);
            for(i=i-1;i  &&  k;i--)--k,s[i]='W';
            for(i=l;i  &&  s[i] == 'L';i--);
            for(i=i+1;i<=l  &&  k;i++)--k,s[i]='W';
        }
        for(i=1;i<=l;i++)
        {
            if(s[i] == 'W')
            {
                ++ans;
                if(s[i-1] == 'W')++ans;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}