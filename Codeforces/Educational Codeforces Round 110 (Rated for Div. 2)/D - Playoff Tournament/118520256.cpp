#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=3e5+5;
const int mod=1e9+7;
char s[N];
int pw[20],idxN[4*N],idxP[4*N],valTree[4*N];
void PreCal(const int& k)
    pw[1]=0;
    for(int i=2;i<=k;i++)pw[i]=1 << (k-i+1);
    for(int i=2;i<=k;i++)pw[i]+=pw[i-1];
void Build(int nodeNum,int l,int r)
    if(l == r)
    {
        valTree[nodeNum]=1;
        return;
    }
    int mid=(l+r) >> 1;
    Build(2*nodeNum,l,mid);
    Build(2*nodeNum+1,mid+1,r);
    int dhon=log2(r-l+1);
    int pos=pw[dhon]+l/(r-l+1)+1;
    idxN[nodeNum]=pos,idxP[pos]=nodeNum;
    if(s[pos] == '0')valTree[nodeNum]=valTree[2*nodeNum];
    else if(s[pos] == '1')valTree[nodeNum]=valTree[2*nodeNum+1];
    else valTree[nodeNum]=valTree[2*nodeNum]+valTree[2*nodeNum+1];
}
 void Update(int nodeNum)
{
    while(nodeNum)
    {
        if(s[idxN[nodeNum]] == '0')valTree[nodeNum]=valTree[2*nodeNum];
        else if(s[idxN[nodeNum]] == '1')valTree[nodeNum]=valTree[2*nodeNum+1];
        else valTree[nodeNum]=valTree[2*nodeNum]+valTree[2*nodeNum+1];
        nodeNum/=2;
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string temp;
    int i,k,l,q;
    cin >> k >> s+1;
    PreCal(k);
    l=1 << k;
    Build(1,1,l);
    cin >> q;
    while(q--)
    {
        cin >> i >> temp;
        s[i]=temp[0];
        Update(idxP[i]);
        cout << valTree[1] << '\n';
    }
    return 0;
}