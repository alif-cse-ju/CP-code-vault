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
#define PSB emplace_back
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
     int i,l,n;
    string s;
    cin >> n >> s;
    l=n;
    for(char c='z';c>'a';c--)
    {
        for(i=0;i<l;i++)
        {
            if(s[i] == c)
            {
                if(i == 0  &&  l > 1  && s[0]-s[1] == 1)s.erase(i,1),--l,i=-1;
                else if(i == l-1  &&  l > 1  && s[l-1]-s[l-2] == 1)s.erase(i,1),--l,i=-1;
                else if(s[i]-s[i-1] == 1  ||   s[i]-s[i+1] == 1)s.erase(i,1),--l,i=-1;
            }
        }
    }
    cout << n-l;
    return 0;
}