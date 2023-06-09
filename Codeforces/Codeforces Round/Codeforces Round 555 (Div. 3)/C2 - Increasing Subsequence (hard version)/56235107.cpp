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
#define FAST() ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 LL big_mod(LL val,LL pow,LL mod);
LL mod_inverse(LL val,LL mod);
string sum_of_two_strings(string a,string b);
      DQ<int>dq;
ST<int>st1,st2;
string ans;
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,n,x;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> x;
        dq.PSB(x);
    }
    x=-1;
    while(dq.F != dq.back())
    {
        if(dq.F < dq.back()  &&  x < dq.F)
        {
            ans+='L';
            x=dq.F;
            dq.PPF;
        }
        else if(x < dq.back())
        {
            ans+='R';
            x=dq.back();
            dq.PPB;
        }
        else if(x < dq.F)
        {
            ans+='L';
            x=dq.F;
            dq.PPF;
        }
        else
        {
            break;
        }
    }
    if(dq.SZ > 1  &&  x < dq.F  &&  x < dq.back())
    {
        st1.PS(dq.back());
        dq.PPB;
        while(!dq.EM  &&  dq.back() > st1.T)
        {
            st1.PS(dq.back());
            dq.PPB;
        }
        //cout << "st1 " << st1.SZ << '\n';
        st2.PS(dq.F);
        dq.PPF;
        while(!dq.EM  &&  dq.F > st2.T)
        {
            st2.PS(dq.F);
            dq.PPF;
        }
        //cout << "st1 " << st1.SZ << '\n';
        if(dq.EM  &&  st1.T > st2.T)
        {
            st2.PS(st1.T);
        }
        int l1=st1.SZ;
        int l2=st2.SZ;
        if(l1 > l2)
        {
            l2=ans.SZ;
            cout << l2+l1 << '\n';
            for(i=0; i<l2; i++)
            {
                cout << ans[i];
            }
            for(i=0; i<l1; i++)
            {
                cout << 'R';
            }
        }
        else
        {
            l1=ans.SZ;
            cout << l1+l2 << '\n';
            for(i=0; i<l1; i++)
            {
                cout << ans[i];
            }
            for(i=0; i<l2; i++)
            {
                cout << 'L';
            }
        }
        return 0;
    }
    if(x < dq.F)
    {
        ans+='L';
    }
    x=ans.SZ;
    cout << x << '\n';
    for(i=0;i<x;i++)
    {
        cout << ans[i];
    }
    return 0;
}
 /*
10
1 2 1 5 6 1 1 2 7 1
*/
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