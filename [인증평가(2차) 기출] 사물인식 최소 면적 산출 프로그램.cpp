#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

#define X first
#define Y second

#define ABS(x) (((x)<0) ? -(x) : (x))
using namespace std;

typedef pair<int, int> P;
vector<P> points[20];
int res = 2000 * 2000;
P p[20];
bool used[20][100] = {false, };
void f(int k, int n){
	if(k == n){
		int min_x = 1000, min_y = 1000;
		int max_x = -1000, max_y = -1000;
		for(int i = 0 ; i < n ; i ++){
			min_x = min(min_x, p[i].X);
			max_x = max(max_x, p[i].X);
			
			min_y = min(min_y, p[i].Y);
			max_y = max(max_y, p[i].Y);
		}
		int area = ABS(max_x - min_x) * ABS(max_y - min_y);
		res = min(area, res);

		return;
	}
	for(int i = 0 ; i < points[k].size() ; i ++){
		if(!used[k][i]){
			used[k][i] = true;
			p[k] = points[k][i];


			int min_x = 1000, min_y = 1000;
			int max_x = -1000, max_y = -1000;
			for(int i = 0 ; i <= k ; i ++){
				min_x = min(min_x, p[i].X);
				max_x = max(max_x, p[i].X);
				
				min_y = min(min_y, p[i].Y);
				max_y = max(max_y, p[i].Y);
			}

			int area = ABS(max_x - min_x) * ABS(max_y - min_y);
			if(area < res) f(k + 1, n);
			used[k][i] = false;
		}
	}

	
}
int main(int argc, char** argv)
{
	int n, k;
	cin >> n >> k;
	for(int i = 0 ; i < n ; i ++){
		int x, y, l;
		cin >> x >> y >> l;
		points[l-1].push_back({x, y});
	}
	f(0, k);
	cout << res;
	return 0;
}