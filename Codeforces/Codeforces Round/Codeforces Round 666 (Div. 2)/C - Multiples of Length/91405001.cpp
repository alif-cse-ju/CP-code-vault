#include<bits/stdc++.h>
using namespace std;
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
#define LL long long
#define ULL unsigned long long
#define PII pair<int,int>
#define PSI pair<string,int>
#define PIS pair<int,string>
#define PLI pair<LL,int>
#define PLL pair<LL,LL>
#define MII map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define MLI map<LL,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
    //int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
    LL a[100002];
 int main()
{
    FAST();
    LL i,n;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    if(n == 1)
    {
        cout << "1 1\n";
        if(a[1] > 0)cout << -a[1] << '\n';
        else cout << abs(a[1]) << '\n';
        cout << "1 1\n" << 0 << "\n";
        cout << "1 1\n" << 0 << "\n";
    }
    else if(n == 2)
    {
        cout << "1 1\n";
        if(a[1] > 0)cout << -a[1] << '\n';
        else cout << abs(a[1]) << '\n';
        cout << "2 2\n";
        if(a[2] > 0)cout << -a[2] << '\n';
        else cout << abs(a[2]) << '\n';
        cout << "1 2\n" << "0 0\n";
    }
    else
    {
        cout << "1 " << n-1 << '\n';
        for(i=1;i<n;i++)
        {
            cout << a[i]*(n-1) << ' ';
            a[i]+=a[i]*(n-1);
        }
        cout << "\n";
        cout << "1 " << n << '\n';
        for(i=1;i<n;i++)
        {
            if(a[i] > 0)cout << -a[i] << ' ';
            else cout << abs(a[i]) << ' ';
        }
        cout << "0\n";
        cout << n << ' ' << n << '\n';
        if(a[n] > 0)cout << -a[n];
        else cout << abs(a[n]);
    }
    return 0;
}