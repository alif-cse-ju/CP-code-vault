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
const int mod=1e9+7;

const int sz=505;

int a[sz];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        for(int i=1;i<=n;i++)cin >> a[i];
        if(n & 1)cout << "-1\n";
        else
        {
            map<int,int>cnt;
            for(int i=1;i<=n;i++)++cnt[a[i]];
            bool ok=1;
            for(auto [x,y] : cnt)ok &= (1 ^ (y & 1));
            if(!ok)cout << "-1\n";
            else
            {
                int curLen=0;
                vector<int>lens;
                vector<pair<int,int>>updates;
                for(int i=1;i<=n;i++)
                {
                    if(!a[i])continue;
                    for(int j=i+1;j<=n;j++)
                    {
                        if(a[i] == a[j])
                        {
                            a[i]=a[j]=0;
                            lens.emplace_back((j-i) << 1);
                            for(int k=i+1;k<j;k++)updates.emplace_back(curLen+j-i+k-i, a[k]);
                            curLen += ((j-i) << 1);
                            reverse(a+i+1,a+j+1);
                            break;
                        }
                    }
                }
                cout << (int)updates.size() << '\n';
                for(auto [x,y] : updates)cout << x << ' ' << y << '\n';
                cout << (int)lens.size() << '\n';
                for(int it : lens)cout << it << ' ';
                cout << '\n';
            }
        }
    }
    return 0;
}