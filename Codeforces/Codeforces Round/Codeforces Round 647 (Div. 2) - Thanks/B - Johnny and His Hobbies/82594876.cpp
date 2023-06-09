    #include<bits/stdc++.h>
         using namespace std;
         #define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
         int n,a[1030];
    bool mark[1030];
         bool Check(int x)
    {
        int i;
        for(i=0;i<n;i++)
        {
            if(!mark[x ^ a[i]])return false;
        }
        return true;
    }
         int main()
    {
        FAST();
        int i,t;
        cin >> t;
        while(t--)
        {
            cin >> n;
            for(i=0;i<1024;i++)mark[i]=false;
            for(i=0;i<n;i++)cin >> a[i],mark[a[i]]=true;
            for(i=1;i<1024;i++)
            {
                if(Check(i))
                {
                    cout << i << '\n';
                    break;
                }
            }
            if(i == 1024)cout << "-1\n";
        }
        return 0;
    }