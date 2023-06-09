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
    LL pre[100005];
 void preCal()
{
    LL i;
    for(i=1;i<=100001;i++)pre[i]=pre[i-1]+i;
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     preCal();
    int t;
    LL i,n,k,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        x=lower_bound(pre+1,pre+n+2,k)-pre;
        string ans;
        for(i=1;i<n-x;i++)ans+='a';
        ans+='b';
        if(pre[x] == k)
        {
            ans+='b';
            for(i=n-x+1;i<n;i++)ans+='a';
        }
        else
        {
            x=k-pre[x-1];
            for(i=ans.SZ;i<n-x;i++)ans+='a';
            ans+='b';
            x=ans.SZ;
            for(i=x;i<n;i++)ans+='a';
        }
        cout << ans << '\n';
    }
    return 0;
}