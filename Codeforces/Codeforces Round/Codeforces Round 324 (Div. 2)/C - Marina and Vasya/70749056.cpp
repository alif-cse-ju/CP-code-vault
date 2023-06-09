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
    bool used[100002];
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,n,t,cnt=0,x,y;
    V<int>bal1,bal2;
    cin >> n >> t;
    char a[n+2],b[n+2],c,ans[n+2];
    cin >> a+1 >> b+1;
    for(i=1;i<=n;i++)
    {
        if(a[i] != b[i])++cnt;
    }
    if(((cnt & 1)  &&  t <= cnt/2)  ||  t < cnt/2)
    {
        cout << "-1";
        return 0;
    }
    x=y=cnt/2,t-=x;
    for(i=1;i<=n;i++)
    {
        if(a[i] != b[i])
        {
            if(x > 0  ||  y > 0)
            {
                if(x >= y)ans[i]=a[i],--x,bal1.PSB(i);
                else ans[i]=b[i],--y,bal2.PSB(i);
            }
            else if(cnt & 1)
            {
                --t;
                cnt=0;
                while(cnt++ >= 0)
                {
                    c=(char)('a'+cnt);
                    if(a[i] != c  &&  b[i] != c)
                    {
                        ans[i]=c;
                        break;
                    }
                }
                break;
            }
        }
    }
    for(i=1;i<=n  &&  t > 0;i++)
    {
        if(a[i] == b[i])
        {
            --t;
            used[i]=true;
            cnt=0;
            while(cnt++ >= 0)
            {
                c=(char)('a'+cnt);
                if(a[i] != c  &&  b[i] != c)
                {
                    ans[i]=c;
                    break;
                }
            }
        }
    }
    while(t > 0)
    {
        if(!used[i])
        {
            --t;
            cnt=0;
            while(cnt++ >= 0)
            {
                c=(char)('a'+cnt);
                if(a[bal1.back()] != c  &&  b[bal1.back()] != c)
                {
                    ans[bal1.back()]=c;
                    bal1.PPB;
                    break;
                }
            }
            cnt=0;
            while(cnt++ >= 0)
            {
                c=(char)('a'+cnt);
                if(a[bal2.back()] != c  &&  b[bal2.back()] != c)
                {
                    ans[bal2.back()]=c;
                    bal2.PPB;
                    break;
                }
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        if(!used[i] &&  a[i] == b[i])ans[i]=a[i];
        cout << ans[i];
    }
    return 0;
}