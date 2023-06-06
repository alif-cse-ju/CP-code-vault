#pragma GCC optimize("Ofast")

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

const int M=3e5+5;
const int N=2e6+5;
const int mod=998244353;

int n;
bool nichi[10];
string ans,s[10];
map<string,bool>mark;

void Try(int cur)
{
    if(cur == n)
    {
        if((int)ans.size() >= 3  &&  mark.find(ans) == mark.end())
        {
            cout << ans;
            exit(0);
        }
        return;
    }
    int tmp=(int)ans.size();
    for(int i=0;i<n;i++)
    {
        if(nichi[i])continue;
        nichi[i]=1;
        if(!tmp)
        {
            ans=s[i], Try(cur+1), nichi[i]=0;
            continue;
        }
        int l=(int)s[i].size();
        for(int j=1;tmp+j+l<17;j++)
        {
            ans += "_" + s[i];
            Try(cur+1);
            for(int k=0;k<l;k++)ans.pop_back();
        }
        nichi[i]=0;
        while((int)ans.size() > tmp)ans.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;cin >> n >> m;
    for(int i=0;i<n;i++)cin >> s[i];
    while(m--)
    {
        string ss;cin >> ss;
        mark[ss]=1;
    }
    Try(0);
    cout << "-1";
    return 0;
}
