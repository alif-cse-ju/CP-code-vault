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
char s[2002];
V<PII>ans;
 void make_reverse(int l,int r)
{
    while(l < r)
    {
        swap(s[l],s[r]);
        ++l,--r;
    }
}
 void find_start(int strt)
{
    for(int i=strt+1;i<=n;i++)
    {
        if(s[i] == '(')
        {
            make_reverse(strt,i);
            ans.PSB({strt,i});
            return;
        }
    }
}
 void find_close(int strt)
{
    for(int i=strt+1;i<=n;i++)
    {
        if(s[i] == ')')
        {
            make_reverse(strt,i);
            ans.PSB({strt,i});
            return;
        }
    }
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,t,k,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> s+1;
        ans.C,x=0,y=n/2;
        for(i=1;i<=n;i++)
        {
            if(k > 1)
            {
                if(i & 1)
                {
                    if(s[i] == ')')find_start(i);
                }
                else
                {
                    if(s[i] == '(')find_close(i);
                    --k,x=i,y=(n-x)/2;
                }
            }
            else
            {
                if(i <= (x+y)  &&  s[i] == ')')find_start(i);
                else if(i > (x+y)  &&  s[i] == '(')find_close(i);
            }
        }
        cout << ans.SZ << '\n';
        for(auto x : ans)cout << x.FI << ' ' << x.SE << '\n';
    }
    return 0;
}