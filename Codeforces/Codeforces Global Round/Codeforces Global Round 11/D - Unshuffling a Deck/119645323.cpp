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
const int M=1e2+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool ok=1;
    vector<pair<int,int>>tmp;
    vector<vector<pair<int,int>>>ans;
    int i,j,k,n,a[55],b[55];
    cin >> n;
    for(i=1; i<=n; i++)cin >> a[i];
    if(n > 1  &&  a[n] == 1)
    {
        tmp.emplace_back(1,n-1);
        tmp.emplace_back(n,n);
        ans.emplace_back(tmp);
        reverse(tmp.begin(),tmp.end());
        k=0;
        for(auto [x,y] : tmp)
        {
            for(j=x; j<=y; j++)b[++k]=a[j];
        }
        for(j=1; j<=n; j++)a[j]=b[j];
    }
    for(i=1; i<=n; i++)
    {
        if(ok)
        {
            if(a[i] != i)
            {
                tmp.clear();
                for(j=1; j<i; j++)tmp.emplace_back(j,j);
                for(j=i+1; a[j]!=i; j++);
                tmp.emplace_back(i,j);
                if(j < n)tmp.emplace_back(j+1,n);
                ans.emplace_back(tmp);
                reverse(tmp.begin(),tmp.end());
                ok=k=0;
                for(auto [x,y] : tmp)
                {
                    for(j=x; j<=y; j++)b[++k]=a[j];
                }
                for(j=1; j<=n; j++)a[j]=b[j];
            }
        }
        else
        {
            if(a[n-i+1] != i)
            {
                tmp.clear();
                for(j=n; j>n-i+1; j--)tmp.emplace_back(j,j);
                for(j=n-i; a[j]!=i; j--);
                tmp.emplace_back(j,n-i+1);
                if(j > 1)tmp.emplace_back(1,j-1);
                ok=1,k=0;
                for(auto [x,y] : tmp)
                {
                    for(j=x; j<=y; j++)b[++k]=a[j];
                }
                reverse(tmp.begin(),tmp.end());
                ans.emplace_back(tmp);
                for(j=1; j<=n; j++)a[j]=b[j];
            }
        }
    }
    if(!ok)
    {
        tmp.clear();
        for(i=1; i<=n; i++)tmp.emplace_back(1,1);
        ans.emplace_back(tmp);
    }
    cout << (int)ans.size() << '\n';
    for(auto v : ans)
    {
        cout << (int)v.size();
        for(auto [x,y] : v)cout << ' ' << y-x+1;
        cout << '\n';
    }
    return 0;
}