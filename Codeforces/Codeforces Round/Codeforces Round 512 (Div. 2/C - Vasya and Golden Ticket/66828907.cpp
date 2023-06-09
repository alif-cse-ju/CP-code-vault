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
     int i,j,n,cnt1;
    string s,temp;
    cin >> n >> s;
    temp=s;
    sort(temp.B,temp.E);
    if(temp[0] == temp[n-1])
    {
        cout << "YES";
        return 0;
    }
    int cnt[105]={0};
    bool mark[905]={0};
    for(i=1;i<=n;i++)cnt[i]=cnt[i-1]+s[i-1]-'0',mark[cnt[i]]=1;
    if(cnt[n] == 1)
    {
        cout << "NO";
        return 0;
    }
    for(i=1;i<=sqrt(cnt[n]);i++)
    {
        if(cnt[n]%i == 0)
        {
            cnt1=0;
            for(j=i;j<=cnt[n];j+=i)
            {
                if(mark[j])++cnt1;
            }
            if(cnt1 == cnt[n]/i)
            {
                cout << "YES";
                return 0;
            }
            cnt1=0;
            for(j=cnt[n]/i;j<=cnt[n]  &&  i > 1;j+=(cnt[n]/i))
            {
                if(mark[j])++cnt1;
            }
            if(cnt1 == i)
            {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}