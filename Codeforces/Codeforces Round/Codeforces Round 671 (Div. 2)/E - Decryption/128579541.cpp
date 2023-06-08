#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l,t;
    ll i,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int>divs;
        for(i=2;i*i<=n;i++)
        {
            if(n%i == 0)
            {
                divs.emplace_back(i);
                if(n/i != i)divs.emplace_back(n/i);
            }
        }
        divs.emplace_back(n);
        sort(divs.begin(),divs.end());
        vector<int>primes;
        if(n%2 == 0)
        {
            primes.emplace_back(2);
            while(n%2 == 0)n/=2;
        }
        for(i=3;i*i<=n;i+=2)
        {
            if(n%i == 0)
            {
                primes.emplace_back(i);
                while(n%i == 0)n/=i;
            }
        }
        if(n > 1)primes.emplace_back(n);
        if((int)primes.size() == 1)
        {
            for(int it : divs)cout << it << ' ';
            cout << "\n0\n";
        }
        else if((int)primes.size() == 2)
        {
            if((int)divs.size() == 3)
            {
                for(int it : divs)cout << it << ' ';
                cout << "\n1\n";
            }
            else
            {
                deque<int>ans;
                ans.emplace_back(primes[0]);
                ans.emplace_back(primes[0]*primes[1]);
                ans.emplace_back(primes[1]);
                n=divs.back(),divs.pop_back();
                for(int it : divs)
                {
                    if(it == primes[0]  ||  it == primes[1]  ||  it == primes[0]*primes[1])continue;
                    if(it%primes[0] == 0)ans.emplace_front(it);
                    else ans.emplace_back(it);
                }
                ans.emplace_back(n);
                for(int it : ans)cout << it << ' ';
                cout << "\n0\n";
            }
        }
        else
        {
            vector<int>ans;
            map<int,bool>mark;
            deque<int>tmp,tmp1,tmp2;
            mark[primes[0]]=1;
            l=(int)primes.size();
            tmp.emplace_back(primes[0]);
            for(i=1;i<l;i++)
            {
                tmp.emplace_back(primes[i]*primes[i-1]);
                tmp.emplace_back(primes[i]);
                mark[primes[i]]=mark[primes[i]*primes[i-1]]=1;
            }
            mark[primes[0]*primes[l-1]]=1;
            tmp.emplace_back(primes[0]*primes[l-1]);
            for(int it : divs)
            {
                if(mark.find(it) == mark.end())tmp1.emplace_back(it);
            }
            while(!tmp.empty())
            {
                ans.emplace_back(tmp.front());
                tmp.pop_front();
                n=ans.back();
                while(!tmp1.empty())
                {
                    if(tmp1.front()%n == 0)ans.emplace_back(tmp1.front());
                    else tmp2.emplace_back(tmp1.front());
                    tmp1.pop_front();
                }
                ans.emplace_back(tmp.front());
                tmp.pop_front();
                while(!tmp2.empty())
                {
                    tmp1.emplace_back(tmp2.front());
                    tmp2.pop_front();
                }
            }
            for(int it : ans)cout << it << ' ';
            cout << "\n0\n";
        }
    }
    return 0;
}