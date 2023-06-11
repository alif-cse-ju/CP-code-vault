#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
int32_t main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        {
            int n,k;
            cin>>n>>k;
            int tsum=0;
            cout<<"1 "<<1<<" "<<n<<"\n";
            int x;
            cin>>x;
            tsum=x;
            if(x==2*n)
                {
                    assert(k%2==0);
                    cout<<2<<" "<<1<<" "<<k/2<<"\n";
                    int p;
                    cin>>p;
                    if(p==1){continue;}
                    else{break;}
                }
            int l=1;
            int r=n;
            while(l<r)
                {
                    int m=(l+r)/2;
                    cout<<1<<" "<<l<<" "<<m<<"\n";
                    int a;
                    cin>>a;
                    if(a==2*(m-l+1))
                        {
                            l=m+1;
                        }
                    else
                        {
                            r=m;
                        }
                }
            int first_one=l;
            cout<<1<<" "<<first_one<<" "<<n<<"\n";
            int p;
            cin>>p;
            if(p>=k)
                {
                    int l=first_one;
                    int r=n;
                    int dones=0;
                    while(l<r)
                        {
                            int m=(l+r)/2;
                            cout<<1<<" "<<first_one<<" "<<m<<"\n";
                            int x;
                            cin>>x;
                            if(x<k)
                                {
                                    l=m+1;
                                }
                            else
                                {
                                    r=m;
                                }
                        }
                    cout<<1<<" "<<first_one<<" "<<l<<"\n";
                    int h;
                    cin>>h;
                    if(h==k)
                        {
                            cout<<2<<" "<<first_one<<" "<<l<<"\n";
                            int pp;
                            cin>>pp;
                            continue;
                        }
                    assert(h==k+1);
                    cout<<2<<" "<<first_one+1<<" "<<l<<"\n";
                    int gg;
                    cin>>gg;
                }
            else
                {
                    if((k-p)%2==0)
                        {
                            int x=(k-p)/2;
                            cout<<2<<" "<<first_one-x<<" "<<n<<"\n";
                            int gg;
                            cin>>gg;
                        }
                    else
                        {
                            //assert(1==0);
                            int l=1;
                            int r=n;
                            while(l<r)
                        {
                            int m=(l+r)/2;
                        cout<<1<<" "<<m+1<<" "<<r<<"\n";
                        int a;
                        cin>>a;
                        if(a==2*(r-m))
                            {
                                r=m;
                            }
                        else
                            {
                                l=m+1;
                            }
                        }
                            int last_one=l;
                            int op=0;
                            cout<<"1 "<<first_one<<" "<<last_one-1<<"\n";
                            int x;
                            cin>>x;
                            int y=(k-x)/2;
                            cout<<2<<" "<<first_one-y<<" "<<last_one-1<<"\n";
                            int gg;
                            cin>>gg;
                        }
                }
        }
}