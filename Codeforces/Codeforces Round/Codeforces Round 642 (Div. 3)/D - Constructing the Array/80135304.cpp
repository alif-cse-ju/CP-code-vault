#include<bits/stdc++.h>
using namespace std;
#define S scanf
#define P printf
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
#define MP make_pair
#define LL long long int
#define ULL unsigned long long int
#define PII pair<int,int>
#define PSI pair<string,int>
#define PIS pair<int,string>
#define PLI pair<long long int,int>
#define PLL pair<long long int,long long int>
#define MII map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define MLI map<long long int,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
     //int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]= {-1,0,1,-1,1,-1,0,1};
//int dy[]= {1,1,1,0,0,-1,-1,-1};
    struct Node
{
     int l,r,sz;
    Node(int sz,int l,int r) : sz(sz), l(l) ,r(r)
    { }
};
 struct Compare
{
    bool operator()(Node const& n1, Node const& n2)
    {
        if(n1.sz == n2.sz)return n1.l > n2.l;
        return n1.sz < n2.sz;
    }
};
 int cnt,ans[200005];
PQ<Node,V<Node>,Compare>pq;
 void FindAns()
{
    int lc,rc,szc;
    while(!pq.EM)
    {
        lc=pq.T.l;
        rc=pq.T.r;
        szc=rc-lc+1;
        pq.PP;
        if(szc & 1)
        {
            ans[(lc+rc)/2]=++cnt;
            if(lc != rc)
            {
                pq.push(Node(szc/2,lc,(lc+rc)/2-1));
                pq.push(Node(szc/2,(lc+rc)/2+1,rc));
            }
        }
        else
        {
            ans[(lc+rc-1)/2]=++cnt;
            if((lc+rc-1)/2-1 >= lc)pq.push(Node(szc/2-1,lc,(lc+rc-1)/2-1));
            if((lc+rc-1)/2+1 <= rc)pq.push(Node(szc/2,(lc+rc-1)/2+1,rc));
        }
    }
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cnt=0;
        pq.push(Node(n,1,n));
        FindAns();
        for(i=1; i<=n; i++)cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}