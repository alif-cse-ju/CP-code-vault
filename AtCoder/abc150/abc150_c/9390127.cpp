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




int n,x,y,a[12],b[12],mark[10],temp[12];
bool paichi;

void find_a(int cur)
{
    int i;
    if(paichi)return;
    if(cur > n)
    {
        for(i=1;i<=n;i++)
        {
            if(a[i] != temp[i])
            {
                ++x;
                return;
            }
        }
        paichi=true;
        ++x;
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(mark[i] == 0)
        {
            temp[cur]=i;
            mark[i]=1;
            find_a(cur+1);
            mark[i]=0;
        }
    }
}

void find_b(int cur)
{
    int i;
    if(paichi)return;
    if(cur > n)
    {
        for(i=1;i<=n;i++)
        {
            if(b[i] != temp[i])
            {
                ++y;
                return;
            }
        }
        paichi=true;
        ++y;
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(mark[i] == 0)
        {
            temp[cur]=i;
            mark[i]=1;
            find_b(cur+1);
            mark[i]=0;
        }
    }
}

int main()
{
    FAST();

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)cin >> b[i];
    paichi=false;
    find_a(1);
    memset(mark,0,sizeof(mark));
    paichi=false;
    find_b(1);
    cout << abs(x-y);
    return 0;
}
