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
     bool mark[202];
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,m,n;
    cin >> n;
    int a[n+2];
    for(i=0; i<n; i++)
    {
        cin >> a[i];
        mark[a[i]]=1;
    }
    cin >> m;
    int b[m+2];
    for(i=0; i<m; i++)
    {
        cin >> b[i];
        mark[b[i]]=1;
    }
    for(i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(!mark[a[i]+b[j]])
            {
                cout << a[i] << ' ' << b[j];
                return 0;
            }
        }
    }
    return 0;
}