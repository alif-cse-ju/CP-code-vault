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
      int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,j,t,r,c,x,cnt1,cnt2,cnt3,cnt4;
    char grid[65][65];
    cin >> t;
    while(t--)
    {
        cin >> r >> c;
        for(i=1;i<=r;i++)cin >> grid[i]+1;
        cnt1=cnt2=0;
        for(i=1;i<=r  &&  (cnt1 == 0  ||  cnt2 == 0);i++)
        {
            for(j=1;j<=c  &&  (cnt1 == 0  ||  cnt2 == 0);j++)
            {
                if(grid[i][j] == 'A')++cnt1;
                else ++cnt2;
            }
        }
        if(cnt1 == 0)cout << "MORTAL\n";
        else if(cnt2 == 0)cout << "0\n";
        else
        {
             cnt1=cnt2=cnt3=cnt4=0;
            for(i=1;i<=c;i++)
            {
                if(grid[1][i] == 'A')++cnt1;
                if(grid[r][i] == 'A')++cnt2;
            }
            for(i=1;i<=r;i++)
            {
                if(grid[i][1] == 'A')++cnt3;
                if(grid[i][c] == 'A')++cnt4;
            }
            if(cnt1 == c  ||  cnt2 == c  ||  cnt3 == r  ||  cnt4 == r){cout << "1\n";continue;}
            if(grid[1][1] == 'A'  ||  grid[1][c] == 'A'  ||  grid[r][1] == 'A'  ||  grid[r][c] == 'A'){cout << "2\n";continue;}
            x=0;
            for(i=2;i<c;i++)
            {
                x=0;
                for(j=1;j<=r;j++)
                {
                    if(grid[j][i] == 'A')++x;
                }
                if(x == r)
                {
                    cout << "2\n";
                    break;
                }
            }
            if(x == r)continue;
            x=0;
            for(i=2;i<r;i++)
            {
                x=0;
                for(j=1;j<=c;j++)
                {
                    if(grid[i][j] == 'A')++x;
                }
                if(x == c)
                {
                    cout << "2\n";
                    break;
                }
            }
            if(x == c)continue;
            if(cnt1 > 0  ||  cnt2 > 0  ||  cnt3 > 0  ||  cnt4 > 0){cout << "3\n";continue;}
            cout << "4\n";
        }
    }
    return 0;
}