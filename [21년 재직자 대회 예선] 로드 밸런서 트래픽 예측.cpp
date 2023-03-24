#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef unsigned long long ull;
ull n, k;
vector<int> node[100001];
vector<ull> cnt(100001, 0);
vector<int> indegree(100001, 0);
vector<int> lst;

void cal(){
	cnt[1] = k;
	for(int i = 1 ; i <= n ; i ++){
		int idx = lst[i];
		if(node[idx].size() == 0) continue;
		ull q = cnt[idx] / node[idx].size();
		ull r = cnt[idx] % node[idx].size();
		for(int j = 0 ; j < r ; j ++) cnt[node[idx][j]] += (q + 1);
		for(int j = r ; j < node[idx].size() ; j ++) cnt[node[idx][j]] += q;
	}
}
void topology_sort(){
	lst.push_back(-1);
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int cur = q.front();
		lst.push_back(cur);
		q.pop();
		for(int nx : node[cur]){
			indegree[nx] --;
			if(indegree[nx] == 0) q.push(nx);
		}
	}
}


int main(int argc, char** argv){
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i ++){
		int t;
		cin >> t;
		while(t--) {
			int x;
			cin >> x;
			node[i].push_back(x);
			indegree[x] ++;
		}
	}

	topology_sort();
	cal();
	for(int i = 1 ; i <= n ; i ++) cout << cnt[i] << ' ';
	
	return 0;
}