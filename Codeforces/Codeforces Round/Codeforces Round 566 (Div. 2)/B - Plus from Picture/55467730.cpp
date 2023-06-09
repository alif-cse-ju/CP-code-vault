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
 LL big_mod(LL val,LL pow,LL mod);
LL mod_inverse(LL val,LL mod);
    MII row_mp;
MII col_mp;
int row,col,ans;
char grid[500][500];
bool visited[500][500];
 void run_bfs(int x,int y)
{
    if(x<0 || x==row || y<0 || y==col || grid[x][y]=='.' || visited[x][y])
    {
        return;
    }
    if(x>0 && x<row-1 && y>0 && y<col-1 && grid[x-1][y] == '*' && grid[x+1][y] == '*' && grid[x][y-1] == '*' && grid[x][y+1] == '*')
    {
        ans++;
    }
    visited[x][y]=true;
    run_bfs(x-1,y);
    run_bfs(x+1,y);
    run_bfs(x,y-1);
    run_bfs(x,y+1);
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,j,cnt,row_mark=0,col_mark=0;
    S("%d %d",&row,&col);
    for(i=0; i<row; i++)
    {
        S("%s",grid[i]);
        cnt=0;
        for(j=0; j<col; j++)
        {
            visited[i][j]=false;
            if(grid[i][j] == '*')
            {
                cnt++;
            }
        }
        if(cnt > 1)
        {
            row_mp[row]=++row_mark;
        }
    }
    if(row_mark == 1)
    {
        for(i=0; i<col; i++)
        {
            cnt=0;
            for(j=0; j<row; j++)
            {
                if(grid[j][i] == '*')
                {
                    cnt++;
                }
            }
            if(cnt > 1)
            {
                col_mp[col]=++col_mark;
            }
        }
        if(col_mark == 1)
        {
            cnt=0;
            for(i=0; i<row; i++)
            {
                for(j=0; j<col; j++)
                {
                    if(grid[i][j] == '*'   &&   visited[i][j] == false)
                    {
                        if(cnt == 0)
                        {
                            cnt++;
                            run_bfs(i,j);
                        }
                        else
                        {
                            P("NO");
                            return 0;
                        }
                    }
                }
            }
            if(ans == 1)
            {
                P("YES");
            }
            else
            {
                P("NO");
            }
        }
        else
        {
            P("NO");
        }
    }
    else
    {
        P("NO");
    }
    return 0;
}
       LL big_mod(LL val,LL pow,LL mod)
{
    LL res = 1;
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
 LL mod_inverse(LL val,LL mod)
{
    LL mod1 = mod;
    if(mod == 1)
    {
        return 0;
    }
    LL y = 0;
    LL x = 1;
    LL quotient,temp;
    while(val > 1)
    {
        quotient = val / mod;
        temp = mod;
        mod = val % mod;
        val = temp;
        temp = y;
        y = x - quotient * y;
        x = temp;
    }
    if(x < 0)
    {
        x += mod1;
    }
    return x;
}