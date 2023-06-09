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
     int i,n,t;
    string a,b,s;
    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        a.C,b.C;
        for(i=0;i<n;i++)
        {
            if(s[i] == '2')
            {
                a+='1';
                b+='1';
            }
            else if(s[i] == '0')
            {
                a+='0';
                b+='0';
            }
            else
            {
                break;
            }
        }
        if(i < n)
        {
            a+=s[i];
            b+='0';
            for(i=i+1;i<n;i++)a+='0',b+=s[i];
        }
        cout << a << '\n' << b << '\n';
    }
    return 0;
}