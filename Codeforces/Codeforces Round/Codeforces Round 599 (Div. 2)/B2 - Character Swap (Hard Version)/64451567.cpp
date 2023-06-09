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
     int i,j,n,t;
    string a,b,s;
    cin >> t;
    while(t--)
    {
        cin >> n >> a >> b;
        s=a+b;
        sort(s.B,s.E);
        for(i=0;i<2*n;i+=2)
        {
            if(s[i] != s[i+1])
            {
                cout << "No\n";
                break;
            }
        }
        if(i == 2*n)
        {
            cout << "Yes\n";
            V<PII>v;
            for(i=0;i<n;i++)
            {
                if(a[i] != b[i])
                {
                    for(j=i+1;j<n;j++)
                    {
                        if(a[i] == a[j])
                        {
                            v.PSB({j,i});
                            swap(a[j],b[i]);
                            break;
                        }
                        else if(a[i] == b[j])
                        {
                            v.PSB({j,j});
                            v.PSB({j,i});
                            swap(a[j],b[j]);
                            swap(a[j],b[i]);
                            break;
                        }
                    }
                }
            }
            cout << v.SZ << '\n';
            for(auto x : v)cout << x.FI+1 << ' ' << x.SE+1 << '\n';
        }
    }
    return 0;
}