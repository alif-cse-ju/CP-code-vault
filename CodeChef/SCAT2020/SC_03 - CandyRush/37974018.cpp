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
    int i,n,x,y,mx,ans=0;
    map<int,int>row,col;
    map<PII,int>points;
    cin >> x >> y >> n;
    while(n--)
    {
        cin >> x >> y;
        ++x,++y;
        ++row[x],++col[y],++points[{x,y}];
    }
    vector<int>r,c;
    mx=-1;
    for(auto it : row)
    {
        if(it.second > mx)
        {
            r.clear();
            mx=it.second;
            r.emplace_back(it.first);
        }
        else if(it.second == mx)r.emplace_back(it.first);
    }
    mx=-1;
    for(auto it : col)
    {
        if(it.second > mx)
        {
            c.clear();
            mx=it.second;
            c.emplace_back(it.first);
        }
        else if(it.second == mx)c.emplace_back(it.first);
    }
    ans=row[r.back()]+col[c.back()];
    for(int R : r)
    {
        for(int _C : c)
        {
            if(points.find({R,_C}) == points.end())
            {
                cout << ans;
                return 0;
            }
        }
    }
    cout << ans-1;
    return 0;
}