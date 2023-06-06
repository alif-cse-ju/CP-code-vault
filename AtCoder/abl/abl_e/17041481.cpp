#include<bits/stdc++.h>

using namespace std;

#define G getline
#define SZ size()
#define C clear()
#define B begin()
#define F front()
#define T top()
#define E end()
#define EM empty()
#define V vector
#define Q queue
#define DQ deque
#define PQ priority_queue
#define ST stack
#define FI first
#define SE second
#define PI acos(-1)
#define PS push
#define PP pop()
#define PSF push_front
#define PSB push_back
#define PPF pop_front()
#define PPB pop_back()
#define LL long long
#define ULL unsigned long long
#define PII pair<int,int>
#define PSI pair<string,int>
#define PIS pair<int,string>
#define PLI pair<LL,int>
#define PLL pair<LL,LL>
#define MII map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define MLI map<LL,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)





//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};




const int N=2e5+2;
const LL mod=998244353;
LL tree[4*N+5],lazy[4*N+5],Base[N];

void PreCal(const int& n)
{
    Base[n]=1;
    for(LL i=n-1;i>0;i--)Base[i]=(Base[i+1]*10)%mod;
}

void Build(int treeNum,int l,int r)
{
    if(l == r)
    {
        tree[treeNum]=Base[l]%mod;
        return;
    }
    int mid=(l+r) >> 1;
    Build(2*treeNum,l,mid);
    Build(2*treeNum+1,mid+1,r);
    tree[treeNum]=(tree[2*treeNum] + tree[2*treeNum+1]) % mod;
}

void Update(int tree_num,int start,int end,int l,int r,long long int value)
{
    if(lazy[tree_num] != 0)
    {
        tree[tree_num]=(Base[start]-Base[end+1])%mod;
        if(tree[tree_num] < 0)tree[tree_num]+=mod;
        tree[tree_num]*=lazy[tree_num];
        tree[tree_num]%=mod;
        if(start != end)
        {
            lazy[tree_num*2]=lazy[tree_num];
            lazy[tree_num*2 + 1]=lazy[tree_num];
        }
        lazy[tree_num]=0;
    }
    if(start > end  ||  start > r  ||  end < l)return ;
    if(start >= l  &&  end <= r)
    {
        tree[tree_num]=(Base[start]-Base[end+1])%mod;
        if(tree[tree_num] < 0)tree[tree_num]+=mod;
        tree[tree_num]*=value;
        tree[tree_num]%=mod;
        if(start != end)
        {
            lazy[tree_num*2]=value;
            lazy[tree_num*2 + 1]=value;
        }
        return ;
    }

    int mid=(start+end)/2;
    Update(tree_num*2,start,mid,l,r,value);
    Update(tree_num*2 + 1,mid+1,end,l,r,value);

    tree[tree_num]=(tree[tree_num*2] + tree[tree_num*2 + 1])%mod;
}

int main()
{
    FAST();
    int i,l,n,q,r,x;
    cin >> n >> q;
    PreCal(n);
    Build(1,1,n);
    for(i=n;i > 0;i--)Base[i]=(Base[i]+Base[i+1])%mod;
    while(q--)
    {
        cin >> l >> r >> x;
        Update(1,1,n,l,r,x);
        cout << tree[1] << '\n';
    }
    return 0;
}
