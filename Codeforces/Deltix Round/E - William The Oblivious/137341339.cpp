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
const int M=1e5+5;
const int N=2e6+5;
const int mod=1e9+7;
char s[M];
struct Node
    ll A,B,C,AB,BC,ABC;
_tree[4*M];
void Merge(const int& nodeNum)
    _tree[nodeNum].A=_tree[2*nodeNum].A+_tree[2*nodeNum+1].A;
    _tree[nodeNum].B=_tree[2*nodeNum].B+_tree[2*nodeNum+1].B;
    _tree[nodeNum].C=_tree[2*nodeNum].C+_tree[2*nodeNum+1].C;
    _tree[nodeNum].AB=min(_tree[2*nodeNum].A+_tree[2*nodeNum+1].AB, _tree[2*nodeNum].AB+_tree[2*nodeNum+1].B);
    _tree[nodeNum].BC=min(_tree[2*nodeNum].B+_tree[2*nodeNum+1].BC, _tree[2*nodeNum].BC+_tree[2*nodeNum+1].C);
    _tree[nodeNum].ABC=min({_tree[2*nodeNum].A+_tree[2*nodeNum+1].ABC, _tree[2*nodeNum].AB+_tree[2*nodeNum+1].BC, _tree[2*nodeNum].ABC+_tree[2*nodeNum+1].C});
void Update(int nodeNum,int l,int r,int i,char c)
{
    if(l == r)
    {
        if(c == 'a')_tree[nodeNum]={1,0,0,0,0,0};
        else if(c == 'b')_tree[nodeNum]={0,1,0,0,0,0};
        else _tree[nodeNum]={0,0,1,0,0,0};
        return;
    }
    int m=(l+r) >> 1;
    if(i <= m)Update(2*nodeNum,l,m,i,c);
    else Update(2*nodeNum+1,m+1,r,i,c);
    Merge(nodeNum);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string ss;
    int i,n,q;
    cin >> n >> q >> s+1;
    for(i=1;i<=n;i++)Update(1,1,n,i,s[i]);
    while(q--)
    {
        cin >> i >> ss;
        Update(1,1,n,i,ss[0]);
        cout << _tree[1].ABC << '\n';
    }
    return 0;
}