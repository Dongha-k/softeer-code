#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int n, k;
	int moving_time[100][100][100] = {0, }; // moving[a][b][c][d] : a번 조립 라인의 b 작업장 -> c번 조립 라인의 b+1 작업장 간의 이동 시간
	int task[100][100]; // task[i][j] : i번째 조립라인의 j번째 작업장에서의 작업 소요 시간
	int min_time[100][100]; // min_time[i][j] : i번째 조립라인의 j번째 작업장까지를 포함한 가능한 최소 도달 시간
	
	cin >> k >> n;

	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < k ; j ++) cin >> task[j][i];
		if(i != n - 1) {
			for(int j = 0 ; j < k ; j ++){
				for(int z = 0 ; z < k ; z ++){
					if(j == z) continue;
					cin >> moving_time[j][i][z];
				}
			}
		}
	}
	
	for(int i = 0 ; i < k ; i ++) min_time[i][0] = task[i][0];
	
	for(int i = 1 ; i < n ; i ++){
		for(int j = 0 ; j < k ; j ++){
			
			min_time[j][i] = min_time[j][i-1];
			for(int z = 0 ; z < k ; z ++){
				if(z != j) min_time[j][i] = min(min_time[j][i], min_time[z][i-1] + moving_time[z][i-1][j]);
			}
			
			min_time[j][i] += task[j][i];
		}
	}
	
	int res = min_time[0][n-1];
	for(int i = 1 ; i < k ; i ++){
		res = min(res, min_time[i][n-1]);
	}

	
	cout << res;
	return 0;
}