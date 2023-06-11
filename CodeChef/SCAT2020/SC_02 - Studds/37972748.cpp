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
int main()
{
    FAST();
    int i,l,n,t,a[102],b[102];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=0;i<n;i++)cin >> a[i];
        for(i=0;i<n;i++)cin >> b[i];
        sort(a,a+n);
        sort(b,b+n);
        vector<int>v1,v2;
        for(i=0;i<n;i++)
        {
            v1.emplace_back(a[i]);
            v1.emplace_back(b[i]);
            v2.emplace_back(b[i]);
            v2.emplace_back(a[i]);
        }
        l=v1.size();
        for(i=1;i<l;i++)
        {
            if(v1[i] < v1[i-1])break;
        }
        if(i == l)cout << "YES\n";
        else
        {
            for(i=1;i<l;i++)
            {
                if(v2[i] < v2[i-1])break;
            }
            if(i == l)cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}