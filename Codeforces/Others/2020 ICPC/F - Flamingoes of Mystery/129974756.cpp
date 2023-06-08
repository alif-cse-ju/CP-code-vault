#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e3+5;
const int N=4e6+5;
const int mod=1e9+7;
int a[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,sum12,sum23,sum13,sumi;
    cin >> n;
    cout << "? 1 2" << endl;
    cin >> sum12;
    cout << "? 2 3" << endl;
    cin >> sum23;
    cout << "? 1 3" << endl;
    cin >> sum13;
    a[3]=sum13-sum12;
    a[2]=sum23-a[3];
    a[1]=sum12-a[2];
    for(i=4;i<=n;i++)
    {
        cout << "? " << i-2 << ' ' << i << endl;
        cin >> sumi;
        a[i]=sumi-a[i-1]-a[i-2];
    }
    cout << '!';
    for(i=1;i<=n;i++)cout << ' ' << a[i];
    return 0;
}