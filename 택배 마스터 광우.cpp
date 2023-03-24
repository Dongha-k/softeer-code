#include <iostream>
#include <algorithm>
using namespace std;
int answer = 987654321;
bool used[10] = {false, };
int idxs[10];
int w[10];
int n, m, t;
void f(int k, int n){
	if(k == n){
		int res = 0;
		int cur = 0;
		for(int i = 0 ; i < t ; i ++){
			int bucket = 0;
			for(; ; cur = (cur + 1) % n){
				if(bucket + w[idxs[cur]] > m) break;
				else bucket += w[idxs[cur]];
			}
			res += bucket;
		}
		answer = min(answer, res);
		
		return;
	}

	for(int i = 0 ; i < n ; i ++){
		if(!used[i]){
			used[i] = true;
			idxs[k] = i;
			f(k + 1, n);
			used[i] = false;
		}
	}

}
int main(int argc, char** argv)
{
	cin >> n >> m >> t;
	for(int i = 0 ; i < n ; i ++) cin >> w[i];
	f(0, n);
	cout << answer;
	return 0;
}