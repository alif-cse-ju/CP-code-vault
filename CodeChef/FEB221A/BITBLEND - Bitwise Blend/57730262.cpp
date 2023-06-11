#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int a[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int>eE,eO,oE,oO;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            if(i & 1)
            {
                if(a[i] & 1)oO.emplace_back(i);
                else oE.emplace_back(i);
            }
            else
            {
                if(a[i] & 1)eO.emplace_back(i);
                else eE.emplace_back(i);
            }
        }
        if(oO.empty()  &&  eO.empty())cout << "-1\n";
        else
        {
            if(!oO.empty()  &&  (int)oE.size()+(int)eO.size() <= (int)eE.size()+(int)oO.size())
            {
                cout << (int)oE.size()+(int)eO.size() << '\n';
                for(int it : oE)cout << it << ' ' << oO[0] << '\n';
                for(int it : eO)cout << it << ' ' << oO[0] << '\n';
            }
            else
            {
                cout << (int)eE.size()+(int)oO.size() << '\n';
                for(int it : eE)cout << it << ' ' << eO[0] << '\n';
                for(int it : oO)cout << it << ' ' << eO[0] << '\n';
            }
        }
    }
    return 0;
}