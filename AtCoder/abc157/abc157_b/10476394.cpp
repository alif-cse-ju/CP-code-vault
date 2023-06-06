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
#define PSB emplace_back
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




int a[4][4];
bool mark[4][4];

int main()
{
    FAST();

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,n,x;
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)cin >> a[i][j];
    }
    cin >> n;
    while(n--)
    {
        cin >> x;
        for(i=1;i<=3;i++)
        {
            for(j=1;j<=3;j++)
            {
                if(a[i][j] == x)mark[i][j]=true;
            }
        }
    }
    if(mark[1][1]  &&  mark[1][2]  &&  mark[1][3])cout << "Yes";
    else if(mark[2][1]  &&  mark[2][2]  &&  mark[2][3])cout << "Yes";
    else if(mark[3][1]  &&  mark[3][2]  &&  mark[3][3])cout << "Yes";
    else if(mark[1][1]  &&  mark[2][1]  &&  mark[3][1])cout << "Yes";
    else if(mark[1][2]  &&  mark[2][2]  &&  mark[3][2])cout << "Yes";
    else if(mark[1][3]  &&  mark[2][3]  &&  mark[3][3])cout << "Yes";
    else if(mark[1][1]  &&  mark[2][2]  &&  mark[3][3])cout << "Yes";
    else if(mark[3][1]  &&  mark[2][2]  &&  mark[1][3])cout << "Yes";
    else cout << "No";
    return 0;
}
