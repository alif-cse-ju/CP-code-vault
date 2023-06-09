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
   LL ara[12][12];
  int main()
{
    ara[1][1]=1;
    ara[1][2]=2;
    ara[1][3]=3;
    ara[1][4]=4;
    ara[1][5]=5;
    ara[1][6]=6;
    ara[1][7]=7;
    ara[1][8]=8;
    ara[1][9]=9;
     ara[2][1]=2;
    ara[2][2]=4;
    ara[2][3]=6;
    ara[2][4]=8;
     ara[3][1]=3;
    ara[3][2]=6;
    ara[3][3]=9;
    ara[3][4]=2;
    ara[3][5]=5;
    ara[3][6]=8;
    ara[3][7]=1;
    ara[3][8]=4;
    ara[3][9]=7;
     ara[4][1]=4;
    ara[4][2]=8;
    ara[4][3]=2;
    ara[4][4]=6;
     ara[6][1]=6;
    ara[6][2]=2;
    ara[6][3]=8;
    ara[6][4]=4;
     ara[7][1]=7;
    ara[7][2]=4;
    ara[7][3]=1;
    ara[7][4]=8;
    ara[7][5]=5;
    ara[7][6]=2;
    ara[7][7]=9;
    ara[7][8]=6;
    ara[7][9]=3;
     ara[8][1]=8;
    ara[8][2]=6;
    ara[8][3]=4;
    ara[8][4]=2;
     ara[9][1]=9;
    ara[9][2]=8;
    ara[9][3]=7;
    ara[9][4]=6;
    ara[9][5]=5;
    ara[9][6]=4;
    ara[9][7]=3;
    ara[9][8]=2;
    ara[9][9]=1;
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int t;
    LL m,n,check,ans,rem;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        if(n < m  ||  (m%10 == 0))
        {
            cout << "0\n";
        }
        else if(n == m)
        {
            cout << (m%10) << '\n';
        }
        else if(m == 1)
        {
            cout << (n/10)*45+(((n%10)*((n%10)+1))/2) << '\n';
        }
        else
        {
            check=n/m;
            m%=10;
            if(m == 5)
            {
                cout << ((check+1)/2)*m << '\n';
            }
            else if(m & 1)
            {
                ans=(check/10)*45;
                rem=check%10;
                rem=check%10;
                for(int i=1; i<=rem; i++)
                {
                    ans+=ara[m][i];
                }
                cout << ans << '\n';
            }
            else
            {
                ans=(check/5)*20;
                rem=check%5;
                for(int i=1; i<=rem; i++)
                {
                    ans+=ara[m][i];
                }
                cout << ans << '\n';
            }
        }
    }
    return 0;
}