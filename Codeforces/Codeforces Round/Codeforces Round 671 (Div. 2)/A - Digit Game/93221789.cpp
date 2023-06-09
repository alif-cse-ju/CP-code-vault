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
    int i,l,t,odd,even;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> l >> s;
        odd=even=0;
        if(l == 1)
        {
            if(s[0] & 1)cout << "1\n";
            else cout << "2\n";
        }
        else if(l & 1)
        {
            for(i=0;i<l;i+=2)
            {
                if(s[i] & 1)
                {
                    odd=1;
                    break;
                }
            }
            if(odd)cout << "1\n";
            else cout << "2\n";
        }
        else
        {
            for(i=1;i<l;i+=2)
            {
                if(!(s[i] & 1))
                {
                    even=1;
                    break;
                }
            }
            if(even)cout << "2\n";
            else cout << "1\n";
        }
    }
    return 0;
}