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
    Q<PII>q1,q2;
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,j,l,t;
    string s,s1,s2;
    cin >> t;
    while(t--)
    {
        cin >> s;
        l=s.SZ;
        s1=s2="";
        for(i=0; i<l; i++)
        {
            if((s[i]-'0') & 1)
                q1.PS({s[i]-'0',i});
            else
                q2.PS({s[i]-'0',i});
        }
        while(!q1.EM  &&  !q2.EM)
        {
            while(!q1.EM  &&  q1.F.FI < q2.F.FI)
            {
                cout << q1.F.FI;
                q1.PP;
            }
            while(!q2.EM  &&  q2.F.FI < q1.F.FI)
            {
                cout << q2.F.FI;
                q2.PP;
            }
        }
        while(!q1.EM)
        {
            cout << q1.F.FI;
            q1.PP;
        }
        while(!q2.EM)
        {
            cout << q2.F.FI;
            q2.PP;
        }
        cout << '\n';
    }
    return 0;
}