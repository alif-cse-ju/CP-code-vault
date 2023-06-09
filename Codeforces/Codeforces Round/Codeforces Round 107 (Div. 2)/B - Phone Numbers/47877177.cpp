#include<bits/stdc++.h>
using namespace std;
vector<string>names;
vector<int>taxi;
vector<int>pizza;
vector<int>magi;
int main()
    int i,j,n,x;
    int taxi_max=0,pizza_max=0,magi_max=0;
    int taxi_cnt,pizza_cnt,magi_cnt;
    char c[10];
    bool flag;
    string s;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&x);
        getchar();
        cin >> s;
        getchar();
        names.push_back(s);
        taxi_cnt=0,pizza_cnt=0,magi_cnt=0;
        for(j=0; j<x; j++)
        {
            scanf("%s",c);
            getchar();
            if(c[0]==c[1] && c[1]==c[3] && c[3]==c[4] && c[4]==c[6] &&  c[6]==c[7])
            {
                taxi_cnt++;
            }
            else if(c[0]>c[1] && c[1]>c[3] && c[3]>c[4] && c[4]>c[6] && c[6]>c[7])
            {
                pizza_cnt++;
            }
            else
            {
                magi_cnt++;
            }
        }
        taxi.push_back(taxi_cnt);
        pizza.push_back(pizza_cnt);
        magi.push_back(magi_cnt);
        if(taxi_cnt > taxi_max)
        {
            taxi_max=taxi_cnt;
        }
        if(pizza_cnt > pizza_max)
        {
            pizza_max=pizza_cnt;
        }
        if(magi_cnt > magi_max)
        {
            magi_max=magi_cnt;
        }
    }
     printf("If you want to call a taxi, you should call:");
    flag=0;
    for(i=0; i<n; i++)
    {
        if(taxi[i] == taxi_max)
        {
            if(flag == 1)
            {
                printf(",");
            }
            flag=1;
            cout << " " << names[i];
        }
    }
    printf(".\n");
     printf("If you want to order a pizza, you should call:");
    flag=0;
    for(i=0; i<n; i++)
    {
        if(pizza[i] == pizza_max)
        {
            if(flag == 1)
            {
                printf(",");
            }
            flag=1;
            cout << " " << names[i];
        }
    }
    printf(".\n");
     printf("If you want to go to a cafe with a wonderful girl, you should call:");
    flag=0;
    for(i=0; i<n; i++)
    {
        if(magi[i] == magi_max)
        {
            if(flag == 1)
            {
                printf(",");
            }
            flag=1;
            cout << " " << names[i];
        }
    }
    printf(".\n");
     return 0;
}