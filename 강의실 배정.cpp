#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> P;
bool comp(const P & a, const P & b){
	if(a.second < b.second) return true;
	if(a.second == b.second and a.first < b.first) return true;
	return false;
}
int main(int argc, char** argv)
{
	vector<P> table;
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i ++){
		int start, end;
		cin >> start >> end;
		table.push_back({start, end});
	}
	sort(table.begin(), table.end(), comp);
	int cur_time = 1;
	int res = 0;
	// for(auto x : table) cout << x.first << ' ' << x.second << '\n';
	for(P x : table){
		int start = x.first;
		int end = x.second;
		if(cur_time <= start){
			res ++;
			cur_time = end;
		}
	}
	cout << res;
	return 0;
}