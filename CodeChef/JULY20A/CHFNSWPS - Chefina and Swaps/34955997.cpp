#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    LL ans;
    bool flag;
    int i,n,t,x,y,z;
    cin >> t;
    while(t--)
    {
        set<int>st;
        vector<int>vA,vB;
        map<int,int>cntA,cntB;
        cin >> n;
        for(i=0;i<n;i++)cin >> x,st.insert(x),++cntA[x];
        for(i=0;i<n;i++)cin >> x,st.insert(x),++cntB[x];
        flag=true;
        for(int x : st)
        {
            y=cntA[x];
            z=cntB[x];
            if((y+z)%2)
            {
                flag=false;
                break;
            }
            if(y > z)
            {
                y=(y-z)/2;
                while(y--)vA.emplace_back(x);
            }
            else if(z > y)
            {
                z=(z-y)/2;
                while(z--)vB.emplace_back(x);
            }
        }
        if(!flag)
        {
            cout << "-1\n";
            continue;
        }
        sort(vA.begin(),vA.end());
        sort(vB.rbegin(),vB.rend());
        x=*(st.begin()),x*=2,ans=0;
        while(!vA.empty())
        {
            ans+=min(min(vA.back(),vB.back()),x);
            vA.pop_back(),vB.pop_back();
        }
        cout << ans << '\n';
    }
    return 0;
}