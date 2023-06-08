#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
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
const int N=2e5+5;
const int mod=1e9+7;
int cnt[26];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int i,l,t;
    cin >> t;
    while(t--)
    {
        cin >> s;
        memset(cnt,0,sizeof(cnt));
        for(char &c : s)++cnt[c-'a'];
        for(i=0; i<26  &&  cnt[i] != 1; i++);
        if(i < 26)
        {
            --cnt[i];
            cout << (char)(i+'a');
            for(i=0; i<26; i++)
            {
                while(cnt[i]--)cout << (char)(i+'a');
            }
        }
        else
        {
            vector<pair<int,int>>v;
            for(i=0; i<26; i++)
            {
                if(cnt[i])v.emplace_back(cnt[i],i);
            }
            l=(int)s.size()-v[0].first;
            if(v[0].first <= l+2)
            {
                l=(int)v.size();
                deque<int>dq;
                for(i=1; i<l; i++)
                {
                    while(v[i].first--)dq.emplace_back(v[i].second);
                }
                cout << (char)(v[0].second+'a');
                while(--v[0].first)
                {
                    cout << (char)(v[0].second+'a');
                    if(!dq.empty())cout << (char)(dq.front()+'a'),dq.pop_front();
                }
                while(!dq.empty())cout << (char)(dq.front()+'a'),dq.pop_front();
            }
            else
            {
                if((int)v.size() == 1)
                {
                    while(v[0].first--)cout << (char)(v[0].second+'a');
                }
                else if((int)v.size() == 2)
                {
                    cout << (char)(v[0].second+'a');
                    --v[0].first;
                    while(v[1].first--)cout << (char)(v[1].second+'a');
                    while(v[0].first--)cout << (char)(v[0].second+'a');
                }
                else
                {
                    cout << (char)(v[0].second+'a');
                    cout << (char)(v[1].second+'a');
                    --v[0].first,--v[1].first;
                    while(v[0].first--)cout << (char)(v[0].second+'a');
                    cout << (char)(v[2].second+'a');
                    --v[2].first;
                    l=(int)v.size();
                    for(i=1;i<l;i++)
                    {
                        while(v[i].first--)cout << (char)(v[i].second+'a');
                    }
                }
            }
        }
        cout << '\n';
    }
    return 0;
}