#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> P;
int main(int argc, char** argv)
{
	int w, n;
	int res = 0;
	vector<P> v;
	cin >> w >> n;
	for(int i = 0 ; i < n ; i ++){
		int w, v_per_kg;
		cin >> w >> v_per_kg;
		v.push_back({-v_per_kg, w});
	}
	sort(begin(v), end(v));

	for(auto &x : v){
		if(w == 0) break;
		res += (min(w, x.second)) * (-x.first);
		w -= min(w, x.second);
	}
	
	cout << res;
	return 0;
}