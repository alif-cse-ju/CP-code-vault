#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int up,down,lft,rigt;
vector<int>upv,downv,leftv,rightv;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    int i,l,x1,x2,y1,y2;
    cin >> s >> x1 >> y1 >> x2 >> y2;
    l=(int)s.size();
    upv.emplace_back(0);
    downv.emplace_back(0);
    leftv.emplace_back(0);
    rightv.emplace_back(0);
    for(i=0;i<l;i++)
    {
        if(s[i] == '@')
        {
            ++up;
            upv.emplace_back(i+1);
        }
        else if(s[i] == '#')
        {
            ++down;
            downv.emplace_back(i+1);
        }
        else if(s[i] == '$')
        {
            ++rigt;
            rightv.emplace_back(i+1);
        }
        else
        {
            ++lft;
            leftv.emplace_back(i+1);
        }
    }
    if(x2 >= x1)
    {
        if(x2-x1 > rigt)cout << "-1";
        else
        {
            if(y2>= y1)
            {
                if(y2-y1 > up)cout << "-1";
                else cout << max(rightv[x2-x1],upv[y2-y1]);
            }
            else
            {
                if(y1-y2 > down)cout << "-1";
                else cout << max(rightv[x2-x1],downv[y1-y2]);
            }
        }
    }
    else
    {
        if(x1-x2 > lft)cout << "-1";
        else
        {
            if(y2>= y1)
            {
                if(y2-y1 > up)cout << "-1";
                else cout << max(leftv[x1-x2],upv[y2-y1]);
            }
            else
            {
                if(y1-y2 > down)cout << "-1";
                else cout << max(leftv[x1-x2],downv[y1-y2]);
            }
        }
    }
    return 0;
}