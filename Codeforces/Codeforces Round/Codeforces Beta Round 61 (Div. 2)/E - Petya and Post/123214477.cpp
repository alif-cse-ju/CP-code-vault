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
const int N=2e5+5;
const int mod=1e9+7;
int n,a[N],b[N];
ll dif[N],sorted[N],_tree[20][N],link[20][N];
void Build(int l,int r,int lvl)
    if(l == r)return;
    int i,equalCnt=0,lessCnt=0,mid=(l+r) >> 1,lChild=l,rChild=mid+1;
    for(i=l;i<=r;i++)
    {
        if(_tree[lvl][i] < sorted[mid])++lessCnt;
    }
    for(i=l;i<=r;i++)
    {
        if((_tree[lvl][i] < sorted[mid])  ||  (_tree[lvl][i] == sorted[mid]  &&  equalCnt < (mid-l-lessCnt+1)))
        {
            _tree[lvl+1][lChild++]=_tree[lvl][i];
            if(_tree[lvl][i] == sorted[mid])++equalCnt;
        }
        else _tree[lvl+1][rChild++]=_tree[lvl][i];
        link[lvl][i]=link[lvl][l-1]+lChild-l;
    }
    Build(l,mid,lvl+1);
    Build(mid+1,r,lvl+1);
}
 void BuildWaveletTree()
{
    for(int i=1;i<=n;i++)_tree[0][i]=sorted[i]=dif[i];
    sort(sorted+1,sorted+n+1);
    Build(1,n,0);
}
 int kth(int start,int end,int curLvl,int l,int r,int k)
{
    if(start == end)return _tree[curLvl][start];
    int cnt=link[curLvl][r]-link[curLvl][l-1],mid=(start+end) >> 1;
    if(cnt >= k)
    {
        int newL=link[curLvl][l-1]-link[curLvl][start-1];
        int newR=link[curLvl][r]-link[curLvl][start-1];
        return kth(start,mid,curLvl+1,start+newL,start+newR-1,k);
    }
    else
    {
        int newL=l-start-(link[curLvl][l-1]-link[curLvl][start-1]);
        int newR=r-start+1-(link[curLvl][r]-link[curLvl][start-1]);
        return kth(mid+1,end,curLvl+1,mid+1+newL,mid+newR,k-cnt);
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x;
    int i;
    set<int>ans;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)cin >> b[i];
    for(i=1;i<=n;i++)dif[i]=a[i]-b[i];
    for(i=1;i<=n;i++)dif[n+i]=dif[i];
    n*=2;
    for(i=2;i<=n;i++)dif[i]+=dif[i-1];
    BuildWaveletTree();
    n/=2;
    for(i=1;i<=n;i++)
    {
        if(a[i] < b[i])continue;
        x=kth(1,2*n,0,i,n+i-1,1);
        if(x >= dif[i-1])ans.insert(i);
    }
    b[0]=b[n];
    for(i=n;i;i--)dif[i]=a[i]-b[i-1];
    reverse(dif+1,dif+n+1);
    for(i=1;i<=n;i++)dif[n+i]=dif[i];
    n*=2;
    for(i=2;i<=n;i++)dif[i]+=dif[i-1];
    BuildWaveletTree();
    n/=2;
    for(i=1;i<=n;i++)
    {
        if(a[n-i+1] < b[n-i])continue;
        x=kth(1,2*n,0,i,n+i-1,1);
        if(x >= dif[i-1])ans.insert(n-i+1);
    }
    cout << (int)ans.size() << '\n';
    for(int it : ans)cout << it << ' ';
    return 0;
}