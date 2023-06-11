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
    int i,j,l;
    string s,x;
    vector<string>v;
    getline(cin,s);
    stringstream ss(s);
    while(ss >> x)v.emplace_back(x);
    l=v.size();
    for(i=1;i<=l;i++)
    {
        s=v[i-1];
        if(i > 1)cout << ' ';
        if(s[0]=='a' || s[0]=='e' || s[0]=='i' || s[0]=='o' || s[0]=='u')cout << s;
        else
        {
            for(j=1;j<s.size();j++)cout << s[j];
            cout << s[0];
        }
        cout << 'd';
        for(j=0;j<i;j++)cout << 'u';
    }
    return 0;
}