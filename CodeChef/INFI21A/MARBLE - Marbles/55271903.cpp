#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
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
char p[M],pp[M],s[M],ss[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,cnt,j,l,t;
    map<char,bool>vowelMark;
    vowelMark['a']=vowelMark['e']=vowelMark['i']=vowelMark['o']=vowelMark['u']=1;
    cin >> t;
    while(t--)
    {
        cin >> l >> s+1 >> p+1;
        ans=INT_MAX;
        for(char c='a';c<='z';c++)
        {
            for(j=1;j<=l;j++)
            {
                if(p[j] == '?')pp[j]=c;
                else pp[j]=p[j];
                if(s[j] == '?')ss[j]=c;
                else ss[j]=s[j];
            }
            cnt=0;
            for(j=1;j<=l;j++)
            {
                if(pp[j] == ss[j])continue;
                ++cnt;
                if(vowelMark.find(pp[j]) != vowelMark.end()  &&  vowelMark.find(ss[j]) != vowelMark.end())++cnt
                else if(vowelMark.find(pp[j]) == vowelMark.end()  &&  vowelMark.find(ss[j]) == vowelMark.end())
            }
            ans=min(ans,cnt);
        }
        cout << ans << '\n';
    }
    return 0;
}