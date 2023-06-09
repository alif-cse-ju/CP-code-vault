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
    int a[200005],ans[200005];
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,n,t,cnt;
    bool flag;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cnt=0;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            if(a[i] != a[i-1])++cnt;
        }
        if(cnt == 1)
        {
            cout << "1\n1";
            for(i=1;i<n;i++)cout << " " << 1;
            cout << "\n";
        }
        else
        {
            cnt=2;
            flag=true;
            ans[1]=1;
            for(i=2;i<=n;i++)
            {
                if(a[i] == a[i-1])ans[i]=ans[i-1];
                else
                {
                    if(flag)
                    {
                        flag=false;
                        ans[i]=2;
                    }
                    else
                    {
                        flag=true;
                        ans[i]=1;
                    }
                }
            }
            if(ans[n] == 1)
            {
                if(a[n] != a[1]  &&  a[n] != a[n-1])
                {
                    for(i=n;i>1;i--)
                    {
                        if(a[i] == a[i-1])break;
                    }
                    if(i == 1)cnt=ans[n]=3;
                    else
                    {
                        for( ;i<=n;i++)
                        {
                            if(ans[i] == 1)ans[i]=2;
                            else ans[i]=1;
                        }
                    }
                }
                else if(a[n] != a[1])ans[n]=2;
            }
            cout << cnt << "\n" << ans[1];
            for(i=2;i<=n;i++)cout << " " << ans[i];
            cout << "\n";
        }
    }
    return 0;
}