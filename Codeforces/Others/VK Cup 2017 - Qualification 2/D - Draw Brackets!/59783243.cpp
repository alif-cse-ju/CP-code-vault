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
     //int dx[]= {-1,1,0,0};
//int dy[]= {0,0,-1,1};
//int dx[]= {-1,0,1,-1,1,-1,0,1};
//int dy[]= {1,1,1,0,0,-1,-1,-1};
     int n,mx,cnt,level[103];
char s[103],grid[105][255];
 void find_depth(int l)
{
    if(l > n)
    {
        return ;
    }
    if(s[l] == '[')
    {
        level[l]=++cnt;
        mx=max(mx,cnt);
    }
    else
    {
        level[l]=cnt--;
    }
    find_depth(l+1);
}
 int main()
{
//    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("input.txt","w",stdout);
     S("%d",&n);
    S("%s",s+1);
    find_depth(1);
    int i,j,row=2*mx+1,col=0,check;
    for(int l=1;l<=n;l++)
    {
        ++col;
        if(s[l] == '[')
        {
            grid[level[l]][col]='+';
            grid[level[l]][col+1]='-';
            check=2*(mx-level[l])+2+level[l];
            grid[check][col]='+';
            grid[check][col+1]='-';
            for(i=level[l]+1;i<check;i++)
            {
                grid[i][col]='|';
            }
        }
        else
        {
            if(s[l-1] == '[')
            {
                col+=3;
            }
            grid[level[l]][col]='+';
            grid[level[l]][col-1]='-';
            check=2*(mx-level[l])+2+level[l];
            grid[check][col]='+';
            grid[check][col-1]='-';
            for(i=level[l]+1;i<check;i++)
            {
                grid[i][col]='|';
            }
        }
    }
    for(i=1;i<=row;i++)
    {
        for(j=1;j<=col;j++)
        {
            if(grid[i][j] == '+'  ||  grid[i][j] == '-'  ||  grid[i][j] == '|')
            {
                P("%c",grid[i][j]);
            }
            else
            {
                P(" ");
            }
        }
        P("\n");
    }
    return 0;
}