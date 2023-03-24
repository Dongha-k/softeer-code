#include <iostream>
#include <vector>

using namespace std;
vector<int> adj[100001];
vector<int> w(100001);

int main(int argc, char** argv)
{
	int n, m;
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++) cin >> w[i];
	for(int i = 0 ; i < m ; i ++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int res = 0;
	for(int i = 1 ; i <= n ; i ++){
		bool great = true;
		for(auto j : adj[i]){
			if(w[i] <= w[j]) {
				great = false;
				break;
			}
		}
		if(great) res ++;
	}
	cout << res;
	return 0;
}