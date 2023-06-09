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
    MSI name1,name2;
V<string>name_1,name_2;
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,q,mark=0;
    string s1,s2;
    cin >> q;
    name_1.PSB("   ");
    name_2.PSB("   ");
    while(q--)
    {
        cin >> s1 >> s2;
        if(name2.find(s1) != name2.E)
        {
            name_2[name1[name_1[name2[s1]]]]=s2;
            name2[s2]=name2[s1];
        }
        else
        {
            name_1.PSB(s1);
            name_2.PSB(s2);
            name1[s1]=name2[s2]=++mark;
        }
    }
    cout << mark << '\n';
    for(i=1;i<=mark;i++)cout << name_1[i] << ' ' << name_2[i] << '\n';
    return 0;
}