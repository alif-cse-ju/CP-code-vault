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




int n;
bool visited[10];
pair<double,double>a[10];
double sum,ans,cnt,dis[10][10];

double find_dis(int x,int y)
{
    return sqrt(((a[x].FI-a[y].FI)*(a[x].FI-a[y].FI)) + ((a[x].SE-a[y].SE)*(a[x].SE-a[y].SE)));
}

void find_ans(int cur)
{
    if(cur > n)
    {
        ans+=sum;
        ++cnt;
        return;
    }
    int i;
    for(i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            visited[i]=true;
            sum+=dis[cur][i];
            find_ans(cur+1);
            sum-=dis[cur][i];
            visited[i]=false;
        }
    }
}

int main()
{
    FAST();

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i].FI >> a[i].SE;
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            dis[i][j]=dis[j][i]=find_dis(i,j);
        }
    }
    find_ans(1);
    cout << fixed << setprecision(10) << ans/(double)cnt;
    return 0;
}
