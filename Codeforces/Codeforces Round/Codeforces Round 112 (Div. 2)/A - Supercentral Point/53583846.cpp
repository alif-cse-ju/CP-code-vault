#include<bits/stdc++.h>
using namespace std;
#define S scanf
#define P printf
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
#define PLL pair<long long int,long long int>
#define MII map<int,int>
#define MSI map<string,int>
#define MLI map<long long int,int>
<int>x_axis[2010];
<int>y_axis[2010];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,j,n,x,y,check;
    S("%d",&n);
    int min_x=1010,max_x=-1010;
    int min_y=1010,max_y=-1010;
    for(i=1;i<=n;i++)
    {
        S("%d %d",&x,&y);
        x+=1000;
        y+=1000;
        min_x=min(min_x,x);
        max_x=max(max_x,x);
        min_y=min(min_y,y);
        max_y=max(max_y,y);
        x_axis[x].PSB(y);
        y_axis[y].PSB(x);
    }
    for(i=0;i<=2000;i++)
    {
        sort(x_axis[i].B,x_axis[i].E);
        sort(y_axis[i].B,y_axis[i].E);
    }
    int cnt=0;
    for(i=min_x+1;i<max_x;i++)
    {
        if(x_axis[i].size() > 2)
        {
            for(j=1;j<x_axis[i].size()-1;j++)
            {
                check=x_axis[i][j];
                if(y_axis[check].size()>2 && i>y_axis[check][0] && i<y_axis[check][y_axis[check].size()-1])
                {
                    cnt++;
                }
            }
        }
    }
    P("%d",cnt);
    return 0;
}