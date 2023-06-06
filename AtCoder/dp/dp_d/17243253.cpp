#include<bits/stdc++.h>

using namespace std;

#define G getline
#define C clear()
#define B begin()
#define F front()
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



const int N=1e5+5;

LL capacity,numOfObjects,weight[105],value[105],ans[105][N];

void KnapSack()
{
    int i,j;
    for(i=0;i<=numOfObjects;i++)
    {
        for(j=0;j<=capacity;j++)
        {
            if(i == 0  ||  j == 0)ans[i][j]=0;
            else if(weight[i] <= j)ans[i][j]=max(value[i] + ans[i-1][j-weight[i]],ans[i-1][j]);
            else ans[i][j]=ans[i-1][j];
        }
    }
}

int main()
{
    FAST();
    int i;
    cin >> numOfObjects >> capacity;
    for(i=1;i<=numOfObjects;i++)cin >> weight[i] >> value[i];
    KnapSack();
    cout << ans[numOfObjects][capacity];
    return 0;
}
