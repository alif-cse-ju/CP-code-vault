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
int main()
{
    FAST();
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,l1,l2,t,x,ans,cnt;
    bool check;
    string a,b;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        if(b[0] == '0')cout << "0\n";
        else if(a[0] == '0')cout << "1\n";
        else
        {
            ans=cnt=0,l1=a.SZ,l2=b.SZ;
            if(l1 > l2)swap(a,b),swap(l1,l2);
            x=l2-l1;
            reverse(a.B,a.E);
            reverse(b.B,b.E);
            while(x--)a+='0';
            check=false;
            for(i=0;i<l2;i++)
            {
                if(a[i] == b[i])
                {
                    ans=max(ans,cnt);
                    if(a[i] == '1')
                    {
                        cnt=1;
                        check=true;
                    }
                    else
                    {
                        cnt=0;
                        check=false;
                    }
                }
                else if(check)++cnt;
            }
            ans=max(ans,cnt);
            cout << ans+1 << '\n';
        }
    }
    return 0;
}