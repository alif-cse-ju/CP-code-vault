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
     map<string,bool>mp;
    string s[200002],temp;
    int i,n,t,cnt00,cnt01,cnt10,cnt11;
    cin >> t;
    while(t--)
    {
        mp.C;
        cin >> n;
        V<int>s00,s01,s10,s11;
        for(i=1;i<=n;i++)
        {
            cin >> s[i];
            mp[s[i]]=true;
            if(s[i][0] == '0'  &&  s[i].back() == '0')s00.PSB(i);
            else if(s[i][0] == '0'  &&  s[i].back() == '1')s01.PSB(i);
            else if(s[i][0] == '1'  &&  s[i].back() == '0')s10.PSB(i);
            else s11.PSB(i);
        }
        cnt00=(int)s00.SZ,cnt01=(int)s01.SZ,cnt10=(int)s10.SZ,cnt11=(int)s11.SZ;
        if(cnt01 == 0  &&  cnt10 == 0)
        {
            if(cnt00 > 0  &&  cnt11 > 0)cout << "-1\n";
            else cout << "0\n\n";
        }
        else
        {
            if(abs(cnt01-cnt10) < 2)cout << "0\n\n";
            else
            {
                V<int>ans;
                if(cnt01 > cnt10)
                {
                    for(int x : s01)
                    {
                        if(cnt10 >= cnt01-1)break;
                        temp=s[x];
                        reverse(temp.B,temp.E);
                        if(mp.find(temp) == mp.E)
                        {
                            ans.PSB(x);
                            mp[temp]=true;
                            mp[s[x]]=false;
                            ++cnt10,--cnt01;
                        }
                    }
                }
                else
                {
                    for(int x : s10)
                    {
                        if(cnt01 >= cnt10-1)break;
                        temp=s[x];
                        reverse(temp.B,temp.E);
                        if(mp.find(temp) == mp.E)
                        {
                            ans.PSB(x);
                            mp[temp]=true;
                            mp[s[x]]=false;
                            --cnt10,++cnt01;
                        }
                    }
                }
                if(abs(cnt01-cnt10) > 1)cout << "-1\n";
                else
                {
                    cout << (int)ans.SZ << '\n';
                    for(int x : ans)cout << x << ' ';
                    cout << '\n';
                }
            }
        }
    }
    return 0;
}