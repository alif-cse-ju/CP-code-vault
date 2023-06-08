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
const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int parA[M],parB[M];
int FindParentA(int x)
    if(parA[x] == x)return x;
    return parA[x]=FindParentA(parA[x]);
int FindParentB(int x)
    if(parB[x] == x)return x;
    return parB[x]=FindParentB(parB[x]);
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,mA,mB,n,x,y;
    cin >> n >> mA >> mB;
    for(i=1;i<=n;i++)parA[i]=parB[i]=i;
    for(i=1;i<=mA;i++)
    {
        cin >> x >> y;
        x=FindParentA(x);
        y=FindParentA(y);
        if(x != y)
        {
            if(x < y)parA[y]=x;
            else parA[x]=y;
        }
    }
    for(i=1;i<=mB;i++)
    {
        cin >> x >> y;
        x=FindParentB(x);
        y=FindParentB(y);
        if(x != y)
        {
            if(x < y)parB[y]=x;
            else parB[x]=y;
        }
    }
    vector<pair<int,int>>ans;
    for(i=2;i<=n;i++)
    {
        x=FindParentA(i);
        y=FindParentB(i);
        if(x != 1  &&  y != 1)
        {
            ans.emplace_back(1,i);
            parA[x]=parB[y]=1;
        }
    }
    vector<int>A,B;
    for(i=2;i<=n;i++)
    {
        x=FindParentA(i);
        y=FindParentB(i);
        if(x == i)A.emplace_back(i);
        if(y == i)B.emplace_back(i);
    }
    l=min((int)A.size(),(int)B.size());
    for(i=0;i<l;i++)ans.emplace_back(A[i],B[i]);
    cout << (int)ans.size() << '\n';
    for(auto [x,y] : ans)cout << x << ' ' << y << '\n';
    return 0;
}