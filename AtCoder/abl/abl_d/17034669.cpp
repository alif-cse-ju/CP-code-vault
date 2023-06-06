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




const int N=3e5+1;
int node[4*N+5];

void Update(int nodeNum,int start,int end,int pos,int x)
{
    if(start == end)
    {
        node[nodeNum]=x;
        return;
    }
    int mid=(start+end) >> 1;
    if(pos <= mid)Update(2*nodeNum,start,mid,pos,x);
    else Update(2*nodeNum+1,mid+1,end,pos,x);
    node[nodeNum]=max(node[2*nodeNum],node[2*nodeNum+1]);
}

int Query(int nodeNum,int start,int end,int l,int r)
{
    if(l == start  &&  r == end)return node[nodeNum];
    int mid=(start+end) >> 1;
    if(r <= mid)return Query(nodeNum*2,start,mid,l,r);
    if(mid < l)return Query(nodeNum*2+1,mid+1,end,l,r);
    return max(Query(nodeNum*2,start,mid,l,mid),Query(nodeNum*2+1,mid+1,end,mid+1,r));
}


int main()
{
    FAST();
    int i,k,n,x,y;
    cin >> n >> k;
    for(i=0;i<n;i++)
    {
        cin >> x;
        ++x;
        y=Query(1,1,N,max(1,x-k),min(x+k,N));
        Update(1,1,N,x,y+1);
    }
    cout << Query(1,1,N,1,N);
    return 0;
}
