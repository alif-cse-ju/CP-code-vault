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
int row[100002],col[100002];
int main()
{
    FAST();
//    freopen("input.txt","r",stdin);
//    freopen("input.txt","w",stdout);
    int i,l,m,n,t,q,x,y;
    LL row_cnt,col_cnt;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> q;
        row_cnt=col_cnt=0;
        l=min(m,n);
        for(i=1;i<=l;i++)row[i]=col[i]=0;
        for(i=l+1;i<=n;i++)row[i]=0;
        for(i=l+1;i<=m;i++)col[i]=0;
        while(q--)
        {
            cin >> x >> y;
            ++row[x],++col[y];
            if(row[x] & 1)++row_cnt;
            else --row_cnt;
            if(col[y] & 1)++col_cnt;
            else --col_cnt;
        }
        cout << row_cnt*((LL)m-col_cnt)+col_cnt*((LL)n-row_cnt) << '\n';
    }
    return 0;
}