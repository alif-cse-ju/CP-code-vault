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
   MSI name_map;
string names[22];
set<string>numbers[22];
map<string,bool>mark;
V<string>distinct_numbers[22];
V<PIS>store;
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,j,k,l,m,n,x,cnt=0;
    string s,temp;
    cin >> n;
    while(n--)
    {
        cin >> s;
        if(name_map.find(s) == name_map.end())
        {
            x=name_map[s]=++cnt;
            names[cnt]=s;
        }
        else
        {
            x=name_map[s];
        }
        cin >> m;
        while(m--)
        {
            cin >> s;
            numbers[x].insert(s);
        }
    }
    cout << cnt << '\n';
    for(i=1; i<=cnt; i++)
    {
        mark.C;
        store.C;
        for(auto it=numbers[i].B; it!=numbers[i].E; it++)
        {
            s=(*it);
            store.PSB(MP(s.SZ,s));
        }
        sort(store.B,store.E);
        reverse(store.B,store.E);
        for(k=0; k<store.SZ; k++)
        {
            s=store[k].SE;
            if(!mark[s])
            {
                temp.C;
                distinct_numbers[i].PSB(s);
                l=s.SZ;
                for(j=l-1; j>=0; j--)
                {
                    temp=s[j]+temp;
                    mark[temp]=1;
                }
            }
        }
        l=distinct_numbers[i].SZ;
        cout << names[i] << ' ' << l;
        for(j=0; j<l; j++)
        {
            cout << ' ' << distinct_numbers[i][j];
        }
        cout << '\n';
    }
    return 0;
}