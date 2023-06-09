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
string division_of_string(string a,LL divisor);
    PQ<PII>pq;
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int n,k,i,x;
    cin >> n >> k;
    int before[n+2],after[n+2],teams[n+2];
    for(i=1;i<=n;i++)
    {
        cin >> x;
        pq.PS(MP(x,i));
        before[i]=i-1;
        after[i]=i+1;
        teams[i]=0;
    }
    int l,r,y,turn=1;
    while(!pq.EM)
    {
        while(teams[pq.T.SE]  &&  !pq.EM)
        {
            pq.PP;
        }
        if(!pq.EM)
        {
            x=pq.T.SE;
            y=1;
            teams[x]=turn;
            for(i=before[x],y=1;y<=k  &&  i>=1;i=before[i],y++)
            {
                teams[i]=turn;
            }
            l=i;
            for(i=after[x],y=1;y<=k  &&  i<=n;i=after[i],y++)
            {
                teams[i]=turn;
            }
            r=i;
            before[r]=l;
            after[l]=r;
        }
        if(turn == 1)
        {
            turn=2;
        }
        else
        {
            turn=1;
        }
    }
    for(i=1;i<=n;i++)
    {
        cout << teams[i];
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
 string division_of_string(string a,LL divisor)
{
    string ans="";
    int i=0,l=a.SZ;
    LL temp=a[0]-'0';
    while(temp < divisor)
    {
        temp=temp*10+(a[++i]-'0');
    }
    while(i < l)
    {
        ans+=((temp/divisor)+'0');
        temp=(temp%divisor)*10+(a[++i]-'0');
    }
    if(ans.SZ == 0)
    {
        return "0";
    }
    return ans;
}