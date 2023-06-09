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
     map<PII,bool>valid_grid;
map<PII,LL>step_needed;
Q<PII>q;
 int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={1,0,-1,1,-1,1,0,-1};
 void run_bfs()
{
    int i,x,y,x1,y1;
    PII temp;
    while(!q.EM)
    {
        x=q.F.FI;
        y=q.F.SE;
        q.PP;
        for(i=0;i<8;i++)
        {
            x1=x+dx[i];
            y1=y+dy[i];
            temp=MP(x1,y1);
            if(valid_grid[temp] == 1  &&  step_needed[temp] > step_needed[MP(x,y)]+1)
            {
                step_needed[temp]=step_needed[MP(x,y)]+1;
                q.PS(temp);
            }
        }
    }
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int x0,y0,x1,y1;
    PII temp;
    cin >> x0 >> y0 >> x1 >> y1;
    int n;
    cin >> n;
    int i,j,r,a,b;
    for(i=0;i<n;i++)
    {
        cin >> r >> a >> b;
        for(j=a;j<=b;j++)
        {
            temp=MP(r,j);
            valid_grid[temp]=1;
            step_needed[temp]=LONG_LONG_MAX;
        }
    }
    temp=MP(x0,y0);
    step_needed[temp]=0;
    q.PS(temp);
    temp=MP(x1,y1);
    step_needed[temp]=LONG_LONG_MAX;
    run_bfs();
    if(step_needed[temp] == LONG_LONG_MAX)
    {
        cout << "-1";
        return 0;
    }
    cout << step_needed[temp];
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