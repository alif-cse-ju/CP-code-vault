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
    int n;
string s;
 int getmax()
{
    int i,mn=0,cnt=0;
    V<int>a(n);
    for(i=0;i<n;i++)
    {
        a[i]=-1;
        if(s[i] == '(')a[i]=1;
        if(i > 0)a[i]+=a[i-1];
        mn=min(mn,a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(a[i] == mn)++cnt;
    }
    return cnt;
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     cin >> n >> s;
    int i,j,x=1,y=1,ans=0,check;
    if(count(s.B,s.E,'(')*2 != n)
    {
        cout << ans << '\n' << x << ' ' << y;
        return 0;
    }
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            swap(s[i],s[j]);
            check=getmax();
            if(check > ans)
            {
                ans=check;
                x=i+1,y=j+1;
            }
            swap(s[i],s[j]);
        }
    }
    cout << ans << '\n' << x << ' ' << y;
    return 0;
}