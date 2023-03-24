#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[300000];
int d[300000];
int d_desc[300000];
vector<int> max_d;


int find(int v){
	int a = 0;
	int b = max_d.size() - 1;
	int mid = (a + b) / 2;
	int answer = -1;
	// cout << "v : " << v << " - ";
	while(a <= b){
		mid = (a + b) / 2;
		if(max_d[mid] < v) answer = max(answer, mid);
		
		if(max_d[mid] < v) a = mid + 1;
		else b = mid - 1;
	}
	// cout << "answer : " << answer << '\n';
	return answer;
}


int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i ++) {
		cin >> arr[i];
	}
	max_d.push_back(0);
	for(int i = 0 ; i < n ; i ++){
		int idx = find(arr[i]);
		d[i] = idx + 1;
		// cout << idx << ' ';
		if(idx + 1 == max_d.size()) max_d.push_back(arr[i]);
		else max_d[idx + 1] = min(max_d[idx + 1], arr[i]);
	}

	// for(int i = 0 ; i < n ; i ++) cout << d[i] << ' ';
	// cout << '\n';

	max_d.clear();
	max_d.push_back(0);
	for(int i = n - 1 ; i >= 0 ; i --){
		int idx = find(arr[i]);
		d_desc[i] = idx + 1;
		// cout << idx << ' ';
		if(idx + 1 == max_d.size()) max_d.push_back(arr[i]);
		else max_d[idx + 1] = min(max_d[idx + 1], arr[i]);
	}


	// for(int i = 0 ; i < n ; i ++) cout << d_desc[i] << ' ';
	// cout << '\n';
	
	int res = 0;
	for(int i = 0 ; i < n ; i ++){
		res = max(res, d[i] + d_desc[i]);
	}
	cout << res - 1;
	return 0;
}