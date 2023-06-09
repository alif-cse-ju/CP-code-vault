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
   string s[3];
 bool check(char c)
{
    if(s[0][0] == c  &&  s[0][1] == c  &&  s[0][2] == c)return true;
    if(s[1][0] == c  &&  s[1][1] == c  &&  s[1][2] == c)return true;
    if(s[2][0] == c  &&  s[2][1] == c  &&  s[2][2] == c)return true;
     if(s[0][0] == c  &&  s[1][0] == c  &&  s[2][0] == c)return true;
    if(s[0][1] == c  &&  s[1][1] == c  &&  s[2][1] == c)return true;
    if(s[0][2] == c  &&  s[1][2] == c  &&  s[2][2] == c)return true;
     if(s[0][0] == c  &&  s[1][1] == c  &&  s[2][2] == c)return true;
    if(s[0][2] == c  &&  s[1][1] == c  &&  s[2][0] == c)return true;
    return false;
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,j,cnt_x=0,cnt_0=0;
    for(i=0;i<3;i++)
    {
        cin >> s[i];
        for(j=0;j<3;j++)
        {
            if(s[i][j] == 'X')++cnt_x;
            else if(s[i][j] == '0')++cnt_0;
        }
    }
    bool win_x=check('X'),win_0=check('0'),legal=true;
    if(cnt_0 > cnt_x  ||  cnt_x-cnt_0 > 1)legal=false;
    else if(win_0  &&  win_x)legal=false;
    else if(win_x  &&  cnt_x-cnt_0 != 1)legal=false;
    else if(win_0  &&  cnt_x-cnt_0 != 0)legal=false;
    if(legal)
    {
        if(win_x)cout << "the first player won";
        else if(win_0)cout << "the second player won";
        else if(cnt_x+cnt_0 == 9)cout << "draw";
        else
        {
            if(cnt_x == cnt_0)cout << "first";
            else cout << "second";
        }
    }
    else cout << "illegal";
    return 0;
}