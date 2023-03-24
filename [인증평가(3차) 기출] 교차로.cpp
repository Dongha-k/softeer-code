#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;
int main(int argc, char** argv)
{	
	int n;
	int cur = 1000000001;
	vector<P> v[4];
	queue<P> q[4];
	
	cin >> n;
	
	vector<int> result(n, -1);
	for(int i = 0 ; i < n ; i ++){
		int t;
		char load;
		cin >> t >> load;
		cur = min(cur, t);
		q[load-'A'].push({t, i});
	}
	

	while(n){
		bool possible[4];
		bool canGo[4];
		int cnt0 = 4;
		for(int i = 0 ; i < 4 ; i ++) {
			if(!q[i].empty() and q[i].front().first <= cur) possible[i] = true; // 출발할 준비가 되어있는 차가 있음
			else {
				possible[i] = false;
				cnt0 --;
			}
		}
		if(cnt0 == 0){
			cur = 1000000001;
			for(int i = 0 ; i < 4 ; i ++){
				if(!q[i].empty()) cur = min(cur, q[i].front().first);
			}
			continue;
		}
		
		
		int cnt = 4;
		for(int i = 0 ; i < 4 ; i ++){
			if(!possible[i]) {
				canGo[i] = false;
				cnt --;
			}
			else{
				if(possible[(i + 3) % 4]) { // 오른쪽 차도 갈 수 있을 때
					canGo[i] = false;
					cnt --;
				}
				else{
					canGo[i] = true;
					int t = q[i].front().first;
					cur = max(cur, t);
				}
			}
		}

		
		for(int i = 0 ; i < 4 ; i ++){
			if(canGo[i]){
				int idx = q[i].front().second;
				result[idx] = cur;

				q[i].pop();
				n--;
			}
		}

		if(cnt == 0) break; // dead lock
		else cur ++;
	}
	
	for(auto x : result) cout << x << '\n';	

	return 0;
}