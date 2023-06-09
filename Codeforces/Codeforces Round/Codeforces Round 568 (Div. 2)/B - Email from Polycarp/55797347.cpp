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
     V<pair<char,int> >v1,v2;
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,l,n,cnt;
    string s1,s2;
    char c;
    bool flag;
    cin >> n;
    while(n--)
    {
        cin >> s1 >> s2;
        if(s2.SZ < s1.SZ)
        {
            cout << "NO\n";
        }
        else
        {
            v1.C;
            v2.C;
            l=s1.SZ;
            cnt=1;
            c=s1[0];
            for(i=1; i<l; i++)
            {
                if(s1[i] == c)
                {
                    cnt++;
                }
                else
                {
                    v1.PSB(MP(c,cnt));
                    cnt=1;
                    c=s1[i];
                }
            }
            v1.PSB(MP(c,cnt));
             l=s2.SZ;
            cnt=1;
            c=s2[0];
            for(i=1; i<l; i++)
            {
                if(s2[i] == c)
                {
                    cnt++;
                }
                else
                {
                    v2.PSB(MP(c,cnt));
                    cnt=1;
                    c=s2[i];
                }
            }
            v2.PSB(MP(c,cnt));
            if(v1.SZ != v2.SZ)
            {
                cout << "NO\n";
            }
            else
            {
                flag=true;
                l=v1.SZ;
                for(i=0; i<l; i++)
                {
                    if(v1[i].FI == v2[i].FI)
                    {
                        if(v1[i].SE > v2[i].SE)
                        {
                            flag=false;
                            break;
                        }
                    }
                    else
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag)
                {
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO\n";
                }
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