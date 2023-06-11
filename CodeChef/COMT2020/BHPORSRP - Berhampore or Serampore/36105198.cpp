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
//int dx[]= {-1,0,1,-1,1,-1,0,1};
//int dy[]= {1,1,1,0,0,-1,-1,-1};
int main()
{
    FAST();
    int i,l,t;
    bool flagA,flagB;
    string s,temp,a="berhampore",b="serampore";
    cin >> t;
    cin.ignore();
    while(t--)
    {
        getline(cin,s);
        flagA=flagB=0;
        stringstream ss(s);
        while(ss >> temp)
        {
            l=temp.size();
            for(i=0;i<l;i++)
            {
                if(temp[i] <= 'Z')temp[i]=(char)('a'+temp[i]-'A');
            }
            if(temp == a)flagA=1;
            else if(temp == b)flagB=1;
        }
        if(flagA  &&  flagB)cout << "Both ";
        else if(flagA)cout << "GCETTB ";
        else if(flagB)cout << "GCETTS ";
        else cout << "Others ";
    }
    return 0;
}