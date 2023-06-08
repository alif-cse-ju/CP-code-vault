#include<bits/stdc++.h>
 using namespace std;
 const int N=5e5+5;
 /********************Treap********************/
 mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
 struct Node
{
    int leftTree,rightTree,val,size,prior;
    void NewNode(int _val)
    {
        val=_val;
        size=1,prior=rnd();
        leftTree=rightTree=0;
    }
}treap[N];
 int L,R,mid,root,availNode;
 inline void Update(int node)
{
    if(node)
    {
        Node &cur=treap[node];
        Node &lt=treap[cur.leftTree];
        Node &rt=treap[cur.rightTree];
         cur.size=1+lt.size+rt.size;
    }
}
 void SplitBySize(int node,int _size,int &l,int &r)
{
    if(!node)
    {
        l=r=0;
        return;
    }
    if(!_size)
    {
        l=0,r=node;
        return;
    }
    if(_size >= treap[node].size)
    {
        l=node,r=0;
        return;
    }
    int &lt=treap[node].leftTree;
    int &rt=treap[node].rightTree;
    if(treap[lt].size >= _size)
    {
        r=node;
        SplitBySize(lt,_size,l,lt);
    }
    else
    {
        l=node;
        SplitBySize(rt,_size-treap[lt].size-1,rt,r);
    }
    Update(node);
}
 void SplitByValue(int node,int _val,int &l,int &r)
{
    if(!node)
    {
        l=r=0;
        return;
    }
    int &lt=treap[node].leftTree;
    int &rt=treap[node].rightTree;
    if(treap[node].val <= _val)
    {
        l=node;
        SplitByValue(rt,_val,rt,r);
    }
    else
    {
        r=node;
        SplitByValue(lt,_val,l,lt);
    }
    Update(node);
}
 int Join(int &l,int &r)
{
    if(!l  ||  !r)return l ? l : r;
    Node &lt=treap[l];
    Node &rt=treap[r];
    if(lt.prior > rt.prior)
    {
        lt.rightTree=Join(lt.rightTree,r);
        Update(l);
        return l;
    }
    else
    {
        rt.leftTree=Join(l,rt.leftTree);
        Update(r);
        return r;
    }
}
 void Inorder(int node)
{
    if(!node)return;
    Inorder(treap[node].leftTree);
    printf("%d ",treap[node].val);
    Inorder(treap[node].rightTree);
}
 void Insert(int val)
{
    SplitByValue(root,val,L,R);
    treap[++availNode].NewNode(val);
    root=Join(L,availNode);
    root=Join(root,R);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,l1,l2,l3,l4,n,r,r1,r2,r3,r4,sz;
    cin >> n;
    for(i=1;i<=n;i++)Insert(i);
    for(i=0;i<n;i++)
    {
        cin >> l >> r;
        if(l >= r)continue;
        sz=min(n-r+1,r-l);
        SplitBySize(root,l-1,l1,r1);
        SplitBySize(r1,r-l,l2,r2);
        SplitBySize(l2,sz,l3,r3);
        SplitBySize(r2,sz,l4,r4);
        root=Join(l1,l4);
        root=Join(root,r3);
        root=Join(root,l3);
        root=Join(root,r4);
    }
    Inorder(root);
    return 0;
}