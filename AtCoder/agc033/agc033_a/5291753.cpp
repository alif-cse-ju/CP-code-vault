#include<bits/stdc++.h>

using namespace std;

#define S scanf
#define P printf
#define G getline
#define C clear()
#define B begin()
#define E end()
#define V vector
#define Fi first
#define Se second
#define PI acos(-1)
#define PS push
#define PP pop
#define PSB push_back
#define PPB pop_back
#define MP make_pair
#define LL long long int
#define PII pair<int,int>
#define PSI pair<string,int>
#define PLI pair<long long int,int>
#define PLL pair<long long int,long long int>
#define MII map<int,int>
#define MSI map<string,int>
#define MLI map<long long int,int>

void FAST();
LL big_mod(LL val,LL pow,LL mod);


int dx[]= {-1,1,0,0};
int dy[]= {0,0,-1,1};

int row,col,ans;
int mark[1005][1005];
string grid[1002];
queue<pair<PII,int> >q;

void run_bfs()
{
    int i,x,y,cost,x1,y1,cost1;
    pair<PII,int>temp;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        x=temp.Fi.Fi;
        y=temp.Fi.Se;
        cost=temp.Se;
        for(i=0; i<4; i++)
        {
            x1=x+dx[i];
            y1=y+dy[i];
            cost1=cost+1;
            if(x1>=0 && x1<row && y1>=0 && y1<col && grid[x1][y1]=='.')
            {
                mark[x1][y1]=cost1;
                grid[x1][y1]='#';
                q.push(MP(MP(x1,y1),cost1));
                ans=max(ans,cost1);
            }
        }
    }
}

int main()
{
    FAST();

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j;
    cin >> row >> col;
    for(i=0; i<row; i++)
    {
        cin >> grid[i];
        for(j=0; j<col; j++)
        {
            if(grid[i][j] == '#')
            {
                q.push(MP(MP(i,j),0));
            }
        }
    }

    run_bfs();
    cout << ans;

//    for(i=0; i<row; i++)
//    {
//        for(j=0; j<col; j++)
//        {
//            cout << mark[i][j] << ' ';
//        }
//        cout << endl;
//    }
    return 0;
}






void FAST()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

LL big_mod(LL val,LL pow,LL mod)
{
    LL res=1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)
        {
            res = (res*val) % mod;
        }
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
}
