#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
struct node{
    int cnt[3];
}segTree[N];
int lazy[N];
void Propagate(int n)
{
    int i,l=2*n,r=l+1;
    lazy[l]+=lazy[n],lazy[r]+=lazy[n];
    lazy[l]%=3,lazy[r]%=3;
    for(i=0;i<lazy[n];i++)
    {
        swap(segTree[l].cnt[0],segTree[l].cnt[2]);
        swap(segTree[l].cnt[1],segTree[l].cnt[2]);
        swap(segTree[r].cnt[0],segTree[r].cnt[2]);
        swap(segTree[r].cnt[1],segTree[r].cnt[2]);
    }
    lazy[n]=0;
}
void Build(int n,int s,int e)
{
    lazy[n]=0;
    if(s == e)
    {
        segTree[n].cnt[0]=1;
        segTree[n].cnt[1]=segTree[n].cnt[2]=0;
        return;
    }
    int l=2*n,r=l+1,mid=(s+e) >> 1;
    Build(l,s,mid);
    Build(r,mid+1,e);
    segTree[n].cnt[0]=segTree[l].cnt[0]+segTree[r].cnt[0];
    segTree[n].cnt[1]=segTree[l].cnt[1]+segTree[r].cnt[1];
    segTree[n].cnt[2]=segTree[l].cnt[2]+segTree[r].cnt[2];
}
void Update(int n,int s,int e,int l,int r)
{
    if(s >= l  &&  e <= r)
    {
        swap(segTree[n].cnt[0],segTree[n].cnt[2]);
        swap(segTree[n].cnt[1],segTree[n].cnt[2]);
        ++lazy[n],lazy[n]%=3;
        return;
    }
    if(s > r  ||  e < l)return;
    if(lazy[n])Propagate(n);
    int lc=2*n,rc=lc+1,mid=(s+e) >> 1;
    Update(lc,s,mid,l,r);
    Update(rc,mid+1,e,l,r);
    segTree[n].cnt[0]=segTree[lc].cnt[0]+segTree[rc].cnt[0];
    segTree[n].cnt[1]=segTree[lc].cnt[1]+segTree[rc].cnt[1];
    segTree[n].cnt[2]=segTree[lc].cnt[2]+segTree[rc].cnt[2];
}
int Query(int n,int s,int e,int l,int r)
{
    if(s >= l  &&  e <= r)return segTree[n].cnt[0];
    if(s > r  ||  e < l)return 0;
    if(lazy[n])Propagate(n);
    int lc=2*n,rc=lc+1,mid=(s+e) >> 1;
    return Query(lc,s,mid,l,r)+Query(rc,mid+1,e,l,r);
}
int main()
{
    int i,l,m,n,r,x;
    scanf("%d %d",&n,&m);
    Build(1,1,n);
    while(m--)
    {
        scanf("%d %d %d",&x,&l,&r);
        ++l,++r;
        if(x)printf("%d\n",Query(1,1,n,l,r));
        else Update(1,1,n,l,r);
    }
    return 0;
}