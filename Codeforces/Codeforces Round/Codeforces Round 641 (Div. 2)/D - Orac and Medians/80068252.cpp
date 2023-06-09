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
    int n,a[100005];
 bool Check()
{
    int i,j;
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<=n  &&  j <= i+2;j++)
        {
            if(a[i]  &&  a[j])return 1;
        }
    }
    return 0;
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,k,t;
    bool flag;
    cin >> t;
    while(t--)
    {
        flag=0;
        cin >> n >> k;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            if(a[i] < k)a[i]=0;
            else if(a[i] == k)a[i]=1,flag=1;
            else a[i]=2;
        }
        if(!flag)cout << "NO\n";
        else
        {
            if(n == 1  ||  Check())cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}