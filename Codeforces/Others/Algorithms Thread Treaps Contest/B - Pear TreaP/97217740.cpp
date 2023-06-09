#include<bits/stdc++.h>
using namespace std;
const int N=6e5+5;
const long long mod = 1000001011, base = 307;
long long pw[N];
void PreCal()
    pw[0]=1;
    for(long long i=1;i<N;i++)pw[i]=(pw[i-1]*base)%mod;
///Treap
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct Node
    int leftTree,rightTree,size,prior;
    long long val,forHash,revHash;
    void NewNode(long long _val)
    {
        size=1,prior=rnd();
        leftTree=rightTree=0;
        val=forHash=revHash=_val;
    }
treap[N];
int L,R,root,availNode;
inline void Update(int node)
    if(node)
    {
        Node &cur=treap[node];
        Node &lt=treap[cur.leftTree];
        Node &rt=treap[cur.rightTree];
         cur.size=1+lt.size+rt.size;
        cur.forHash=(((lt.forHash*base + cur.val)%mod) * pw[rt.size] + rt.forHash)%mod;
        cur.revHash=(((rt.revHash*base + cur.val)%mod) * pw[lt.size] + lt.revHash)%mod;
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
 void Insert(int idx,int val)
{
    SplitBySize(root,idx,L,R);
    treap[++availNode].NewNode(val);
    root=Join(L,availNode);
    root=Join(root,R);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    int i,l,l1,l2,q,r,r1,r2,op;
    PreCal();
    cin >> l >> q >> s;
    for(i=0;i<l;i++)Insert(i,s[i]-'a'+1);
    while(q--)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> l >> r;
            SplitBySize(root,r,l1,r1);
            SplitBySize(l1,l-1,l2,r2);
            root=Join(l2,r1);
        }
        else if(op == 2)
        {
            cin >> s >> l;
            Insert(l-1,s[0]-'a'+1);
        }
        else
        {
            cin >> l >> r;
            SplitBySize(root,r,l1,r1);
            SplitBySize(l1,l-1,l2,r2);
            if(treap[r2].forHash == treap[r2].revHash)cout << "yes\n";
            else cout << "no\n";
            root=Join(l2,r2);
            root=Join(root,r1);
        }
    }
    return 0;
}