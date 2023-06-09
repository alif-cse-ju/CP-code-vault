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
    int cnt[200005][30];
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     string s;
    int i,j,k,n,t,ans,bal;
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> s;
        for(i=0;i<k/2+(k & 1);i++)
        {
            for(j=0;j<26;j++)cnt[i][j]=0;
        }
        for(i=0;i<n;i+=k)
        {
            for(j=0;j<k/2;j++)++cnt[j][s[i+j]-'a'],++cnt[j][s[i+k-j-1]-'a'];
            if(k & 1)++cnt[j][s[i+j]-'a'];
        }
        ans=0;
        for(i=0;i<k/2;i++)
        {
            bal=0;
            for(j=0;j<26;j++)bal=max(bal,cnt[i][j]);
            ans+=2*n/k-bal;
        }
        if(k & 1)
        {
            bal=0;
            for(j=0;j<26;j++)bal=max(bal,cnt[i][j]);
            ans+=n/k-bal;
        }
        cout << ans << '\n';
    }
    return 0;
}