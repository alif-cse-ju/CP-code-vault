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
    int forCnt[1005];
int backCnt[1005];
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,l,pos,mx=-1,x;
    char s[1005];
    cin >> s+1;
    l=strlen(s+1);
    for(i=1;i<=l;i++)forCnt[i]=forCnt[i-1]+(s[i] == '(');
    for(i=l;i>0;i--)backCnt[i]=backCnt[i+1]+(s[i] == ')');
    for(i=1;i<=l;i++)
    {
        if(min(forCnt[i],backCnt[i])*2 > mx)
        {
            pos=i;
            mx=min(forCnt[i],backCnt[i])*2;
        }
    }
    x=mx/2;
    V<int>ans;
    for(i=1;i<=pos  &&  x;i++)
    {
        if(s[i] == '(')ans.PSB(i),--x;
    }
    x=mx/2;
    for(i=l;i>=pos  &&  x;i--)
    {
        if(s[i] == ')')ans.PSB(i),--x;
    }
    if(mx == 0)
    {
        cout << "0";
        return 0;
    }
    cout << "1\n" << mx << '\n';
    mx/=2;
    for(i=0;i<mx;i++)cout << ans[i] << ' ';
    while(mx > 0)
    {
        cout << ans.back() << ' ';
        ans.PPB;
        --mx;
    }
    return 0;
}