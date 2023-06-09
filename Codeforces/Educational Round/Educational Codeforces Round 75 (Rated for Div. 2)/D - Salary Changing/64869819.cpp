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
    LL s;
int n;
PII salaries[200002];
 bool check(int mid)
{
    V<int>v;
    LL sum=0;
    int i,cnt=0;
    for(i=0;i<n;i++)
    {
        if(salaries[i].SE < mid)sum+=salaries[i].FI;
        else if(salaries[i].FI >= mid)sum+=salaries[i].FI,++cnt;
        else v.PSB(salaries[i].FI);
    }
    int need=max(0,(n+1)/2-cnt);
    if(need > v.SZ)return false;
    for(i=0;i<v.SZ;i++)
    {
        if(i < v.SZ-need)sum+=v[i];
        else sum+=mid;
    }
    return sum <= s;
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        for(i=0;i<n;i++)cin >> salaries[i].FI >> salaries[i].SE;
        sort(salaries,salaries+n);
        int low=1,mid,high=int(1e9)+100;
        while(high-low > 1)
        {
            mid=(low+high) >> 1;
            if(check(mid))low=mid;
            else high=mid;
        }
        cout << low << '\n';
    }
    return 0;
}