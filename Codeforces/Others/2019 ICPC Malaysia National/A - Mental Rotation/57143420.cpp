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
string sum_of_two_strings(string a,string b);
     int n;
char grid[1002][1002],temp[1002][1002],op[102];
 void make_right_rotations(int num)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(grid[i][j] == '>')
            {
                temp[j][n-i-1]='v';
            }
            else if(grid[i][j] == '^')
            {
                temp[j][n-i-1]='>';
            }
            else if(grid[i][j] == '<')
            {
                temp[j][n-i-1]='^';
            }
            else if(grid[i][j] == 'v')
            {
                temp[j][n-i-1]='<';
            }
            else
            {
                temp[j][n-i-1]='.';
            }
        }
    }
    if(--num)
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(temp[i][j] == '>')
                {
                    grid[j][n-i-1]='v';
                }
                else if(temp[i][j] == '^')
                {
                    grid[j][n-i-1]='>';
                }
                else if(temp[i][j] == '<')
                {
                    grid[j][n-i-1]='^';
                }
                else if(temp[i][j] == 'v')
                {
                    grid[j][n-i-1]='<';
                }
                else
                {
                    grid[j][n-i-1]='.';
                }
            }
        }
        if(--num)
        {
            for(i=0; i<n; i++)
            {
                for(j=0; j<n; j++)
                {
                    if(grid[i][j] == '>')
                    {
                        temp[j][n-i-1]='v';
                    }
                    else if(grid[i][j] == '^')
                    {
                        temp[j][n-i-1]='>';
                    }
                    else if(grid[i][j] == '<')
                    {
                        temp[j][n-i-1]='^';
                    }
                    else if(grid[i][j] == 'v')
                    {
                        temp[j][n-i-1]='<';
                    }
                    else
                    {
                        temp[j][n-i-1]='.';
                    }
                }
            }
        }
    }
}
 void make_left_rotations(int num)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(grid[i][j] == '>')
            {
                temp[n-j-1][i]='^';
            }
            else if(grid[i][j] == '^')
            {
                temp[n-j-1][i]='<';
            }
            else if(grid[i][j] == '<')
            {
                temp[n-j-1][i]='v';
            }
            else if(grid[i][j] == 'v')
            {
                temp[n-j-1][i]='>';
            }
            else
            {
                temp[n-j-1][i]='.';
            }
        }
    }
    if(--num)
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(temp[i][j] == '>')
                {
                    grid[n-j-1][i]='^';
                }
                else if(temp[i][j] == '^')
                {
                    grid[n-j-1][i]='<';
                }
                else if(temp[i][j] == '<')
                {
                    grid[n-j-1][i]='v';
                }
                else if(temp[i][j] == 'v')
                {
                    grid[n-j-1][i]='>';
                }
                else
                {
                    grid[n-j-1][i]='.';
                }
            }
        }
        if(--num)
        {
            for(i=0; i<n; i++)
            {
                for(j=0; j<n; j++)
                {
                    if(grid[i][j] == '>')
                    {
                        temp[n-j-1][i]='^';
                    }
                    else if(grid[i][j] == '^')
                    {
                        temp[n-j-1][i]='<';
                    }
                    else if(grid[i][j] == '<')
                    {
                        temp[n-j-1][i]='v';
                    }
                    else if(grid[i][j] == 'v')
                    {
                        temp[n-j-1][i]='>';
                    }
                    else
                    {
                        temp[n-j-1][i]='.';
                    }
                }
            }
        }
    }
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     S("%d %s",&n,op);
    int i,l=strlen(op);
    for(i=0; i<n; i++)
    {
        S("%s",grid[i]);
    }
    int l_cnt=0,r_cnt=0;
    for(i=0; i<l; i++)
    {
        if(op[i] == 'L')
        {
            l_cnt++;
        }
        else
        {
            r_cnt++;
        }
    }
    if(l_cnt >= r_cnt)
    {
        l_cnt=(l_cnt-r_cnt)%4;
        if(l_cnt == 0)
        {
            for(i=0; i<n; i++)
            {
                P("%s\n",grid[i]);
            }
            return 0;
        }
        make_left_rotations(l_cnt);
        if(l_cnt & 1)
        {
            for(i=0; i<n; i++)
            {
                P("%s\n",temp[i]);
            }
        }
        else
        {
            for(i=0; i<n; i++)
            {
                P("%s\n",grid[i]);
            }
        }
    }
    else
    {
        r_cnt=(r_cnt-l_cnt)%4;
        if(r_cnt == 0)
        {
            for(i=0; i<n; i++)
            {
                P("%s\n",grid[i]);
            }
            return 0;
        }
        make_right_rotations(r_cnt);
        if(r_cnt & 1)
        {
            for(i=0; i<n; i++)
            {
                P("%s\n",temp[i]);
            }
        }
        else
        {
            for(i=0; i<n; i++)
            {
                P("%s\n",grid[i]);
            }
        }
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
 string sum_of_two_strings(string a,string b)
{
    reverse(a.B,a.E);
    reverse(b.B,b.E);
    char c;
    string ans="";
    int length_of_a=a.SZ,length_of_b=b.SZ;
    int i,carry=0,sum,length=max(length_of_a,length_of_b);
    for(i=0; i<length; i++)
    {
        if(i >= length_of_a)
        {
            sum=(b[i]-48)+carry;
        }
        else if(i >= length_of_b)
        {
            sum=(a[i]-48)+carry;
        }
        else
        {
            sum=(a[i]-48)+(b[i]-48)+carry;
        }
        carry=sum/10;
        sum%=10;
        c=sum+48;
        ans+=c;
    }
    if(carry > 0)
    {
        ans+=(carry+48);
    }
    reverse(ans.B,ans.E);
    return ans;
}