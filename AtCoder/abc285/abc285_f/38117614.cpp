#pragma GCC optimize("Ofast")

#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <chrono>
#include <random>
#include <vector>
#include <climits>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=1e5+5;
const int N=2e6+5;
const int mod=1e9+7;

char s[M];
bool isNonDec[M];
int cntS[26][M],cntT[26],ln,nonDec[M];

void UpdateB(int i,int j,int v)
{
    while(j <= ln)cntS[i][j]+=v, j+=(j & -j);
}

int QueryB(int i,int j)
{
    int ans=0;
    while(j)ans+=cntS[i][j], j-=(j & -j);
    return ans;
}

void UpdateS(int i,int v)
{
    while(i <= ln)nonDec[i]+=v, i+=(i & -i);
}

int QueryS(int i)
{
    int ans=0;
    while(i)ans+=nonDec[i], i-=(i & -i);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> ln >> s+1;
    for(int i=1;i<=ln;i++)
    {
        ++cntT[s[i]-'a'], UpdateB(s[i]-'a',i,1);
        if(i > 1  &&  s[i] >= s[i-1])isNonDec[i]=1, UpdateS(i,1);
    }
    int q;cin >> q;
    while(q--)
    {
        int t;cin >> t;
        if(t == 1)
        {
            int i; string ss; cin >> i >> ss;
            --cntT[s[i]-'a'], UpdateB(s[i]-'a',i,-1);
            s[i]=ss[0];
            ++cntT[s[i]-'a'], UpdateB(s[i]-'a',i,1);
            if(i > 1  &&  (s[i] >= s[i-1]) != isNonDec[i])
            {
                if(isNonDec[i])UpdateS(i,-1);
                else UpdateS(i,1);
                isNonDec[i] ^= 1;
            }
            if(i < ln  &&  (s[i+1] >= s[i]) != isNonDec[i+1])
            {
                if(isNonDec[i+1])UpdateS(i+1,-1);
                else UpdateS(i+1,1);
                isNonDec[i+1] ^= 1;
            }
        }
        else
        {
            int l,r;cin >> l >> r;
            if(l == r)cout << "Yes\n";
            else
            {
                int check=QueryS(r) - QueryS(l);
                if(check != r-l)cout << "No\n";
                else
                {
                    int mn=-1,mx=-1;
                    for(int i=0;i<26  &&  mn==-1;i++)
                    {
                        if(QueryB(i,r)-QueryB(i,l-1))mn=i;
                    }
                    for(int i=25;i>=0  &&  mx==-1;i--)
                    {
                        if(QueryB(i,r)-QueryB(i,l-1))mx=i;
                    }
                    bool ok=1;
                    for(int i=mn+1;i<mx  &&  ok;i++)
                    {
                        if(QueryB(i,r)-QueryB(i,l-1) != cntT[i])ok=0;
                    }
                    if(ok)cout << "Yes\n";
                    else cout << "No\n";
                }
            }
        }
    }
    return 0;
}
