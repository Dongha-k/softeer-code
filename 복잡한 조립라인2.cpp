#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int n, k;
	int task[10000][100];
	int moving_time[99];
	int min_time[10000][100];

	cin >> k >> n;

	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < k ; j ++) cin >> task[j][i];
		if(i != n - 1) cin >> moving_time[i];
	}

	int before_min = 1000000;
	for(int i = 0 ; i < k ; i ++) {
		min_time[i][0] = task[i][0];
		before_min = min(before_min, min_time[i][0]);
	}
	
	for(int i = 1 ; i < n ; i ++){
		for(int j = 0 ; j < k ; j ++){
			min_time[j][i] = min_time[j][i-1] + task[j][i];

			min_time[j][i] = min(min_time[j][i], before_min + moving_time[i-1] + task[j][i] );
		}
		before_min = -1;

		for(int j = 0 ; j < k ; j ++) {
			if(before_min == -1) before_min = min_time[j][i];
			else before_min = min(before_min, min_time[j][i]);
		}
	}



	int res = min_time[0][n-1];
	for(int i = 1 ; i < k ; i ++) res = min(res, min_time[i][n-1]);
	
	cout << res;


	return 0;
}