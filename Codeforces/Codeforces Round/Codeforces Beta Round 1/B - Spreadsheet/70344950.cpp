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
#define PSB emplace_back
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
    string toStr(int x)
{
    string s="";
    if(x == 0)return "0";
    while(x > 0)s=(char)('0'+(x%10))+s,x/=10;
    return s;
}
 int toNum(string s)
{
    int x=0,l=s.SZ;
    for(int i=0;i<l;i++)x=x*10+(s[i]-'0');
    return x;
}
 int getId(string s)
{
    int ans=1,x=1,l=s.SZ;
    for(int i=l-1;i>=0;i--)
    {
        ans+=(s[i]-'A')*x;
        x*=26;
        if(i != 0)ans+=x;
    }
    return ans;
}
 string getStr(int cur)
{
    --cur;
    int i,l=1,z=26;
    while(cur >= z)cur-=z,z*=26,++l;
    string s="";
    for(i=0;i<l;i++)s+='A';
    for(i=0;i<l;i++)
    {
        z/=26;
        while(cur >= z)cur-=z,++s[i];
    }
    return s;
}
 bool checkType(string s)
{
    int cur=0,l=s.SZ;
    while('A' <= s[cur]  &&  s[cur] <= 'Z')++cur;
    for(int i=cur;i<l;i++)
    {
        if('A' <= s[i]  &&  s[i] <= 'Z')return false;
    }
    return true;
}
 string solve1(string s)
{
    int cur=0,l=s.SZ;
    while('A' <= s[cur]  &&  s[cur] <= 'Z')++cur;
    return "R"+s.substr(cur,l-cur)+"C"+toStr(getId(s.substr(0,cur)));
}
 string solve2(string s)
{
    int cur=1,l=s.SZ;
    while('0' <= s[cur]  &&  s[cur] <= '9')++cur;
    return getStr(toNum(s.substr(cur+1,l-cur-1)))+s.substr(1,cur-1);
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int t;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        if(checkType(s))cout << solve1(s) << '\n';
        else cout << solve2(s) << '\n';
    }
    return 0;
}
//1B