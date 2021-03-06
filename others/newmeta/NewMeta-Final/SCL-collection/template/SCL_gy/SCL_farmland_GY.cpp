#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
double eps = 1e-12;
struct couple
{
	int x, y;
	couple(){}
	couple(int _x, int _y) : x(_x), y(_y) {}
	void scan() {scanf("%d%d", &x, &y);}
} a[222], c;
int operator * (const couple & x, const couple & y) {return x.x * y.y - x.y * y.x;}
int operator % (const couple & x, const couple & y) {return x.x * y.x + x.y * y.y;}
couple operator - (const couple & x, const couple & y) {return couple(x.x - y.x, x.y - y.y);}
int k, n, x, y, ans, x1, Q, id[222];
bool flag, flag1;
int area;
vector<int> gen;
vector<int> vec[222];
vector<bool> f[222];
map<int, int> mp;
struct Polar
{
	couple o;
	Polar(const couple & _o) : o(_o){}
	bool operator () (const couple & a, const couple & b)
	{
		return atan2((a - o).y, (a - o).x) < atan2((b - o).y, (b - o).x);
	}
	bool operator () (int x, int y)
	{
		return this->operator () (a[x], a[y]);
	}
};
int main()
{
	freopen("01.in", "r", stdin);
	scanf("%d", &Q);
	for(int qq = 1; qq <= Q; qq++)
	{
		scanf("%d", &n);
		mp.clear();
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &id[i]);
			a[i].scan();
			vec[i].clear();
			f[i].clear();
			scanf("%d", &x);
			for(int j = 0; j < x; j++) {scanf("%d", &y); vec[i].push_back(y); f[i].push_back(true);}
		}
		scanf("%d", &k);
		for(int i = 1; i <= n; i++)	
			sort(vec[i].begin(), vec[i].end(), Polar(a[i]));
		ans = 0;
		for(int i = 1; i <= n; i++) for(int j = 0; j < vec[i].size(); j++) if(f[i][j])
		{
			x = i;
			y = j;
			gen.clear();
			for(;;){
				f[x][y] = false;
				gen.push_back(x);
				x1 = x;
				x = vec[x][y];
				y = lower_bound(vec[x].begin(), vec[x].end(), x1, Polar(a[x])) - vec[x].begin();
				y = (y + 1) % vec[x].size();
				if(x == i and y == j) break;//break when x == i and y == j, not only x == i!
			}
			if(gen.size() != k) continue;
			gen.push_back(gen.front());
			area = 0;
			for(int i = 0; i + 1 < gen.size(); i++) area += a[gen[i]] * a[gen[i + 1]];//printf("%d %d %lf\n", gen[i], gen[i + 1], a[gen[i]] * a[gen[i + 1]]);}
			if(area >= 0) continue;
			flag = true;
			for(int i = 0; i + 2 < gen.size(); i++) {for(int j = i + 1; j + 1 < gen.size(); j++) if(gen[i] == gen[j]) {flag = false; break;} if(flag == false) break;}
			ans += flag;
		}
		printf("%d\n", ans);
	}
	fclose(stdin);
	return 0;
}	
