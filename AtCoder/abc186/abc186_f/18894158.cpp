#include <bits/stdc++.h>

using namespace std;

set <int,greater<int>> S;
int row[200001];
vector <int> col[200001];
vector <long long int> tree;
bool check[200001];
long long int sum(int i)
{
	long long int ans = 0;
	while(i>0)
	{
		ans+=tree[i];
		i -= (i & -i);
	}
	return ans;
}

void update(int i,long long int diff)
{
	while(i<tree.size())
	{
		tree[i] += diff;
		i += (i & (-i));
	}
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long int res = 0;
	int h,w,m;
	int x,y;

	cin >> h >> w >> m;
	tree.resize(h);
	fill(row,row+200001,w);

	for(int i=0;i<m;i++)
	{
		cin >> x >> y;
		x-=1;
		y-=1;
		row[x] = min(row[x],y);
		col[y].push_back(x);
	}

	memset(check,false,sizeof(check));
	res = 1;

	int X = h;
	for(int x=1;x<h;x++)
	{
		if(row[x]==0)
		{
			X = x;
			break;
		}
		//cout << x << ' ' << res << ' ' << row[x] << '\n';
		res += (row[x]);
	}
	//cout << X << '\n';
	
	for(int x=X;x<h;x++)
	{
		check[x] = true;
		update(x,1);
	}

	//cout << res << '\n';
	for(int y=1;y<w;y++)
	{
		if(row[0]==y)
		{
			break;
		}
		int MIN = h;
		for(auto it : col[y])
		{
			MIN = min(MIN,it);
			//S.insert(it);
		}

		res += sum(MIN-1);
		res++;
		//res += (h - X + 1);
		//cout << y << ' ' << sum(MIN-1) << ' ' << MIN << '\n';
		for(auto it : col[y])
		{
			if(!check[it])
			{
				update(it,1);
				check[it] = true;
			}
		}		
	}

	cout << res << '\n';

	return 0;
}	