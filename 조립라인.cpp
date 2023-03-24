#include <iostream>
#include <algorithm>
using namespace std;

// A -> 1 10
// B -> 3 2

int main(int argc, char** argv)
{
	int n;
	int task[2][1000];
	int moving[999][2];
	int min_time[2][1000];
	cin >> n;
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < 2 ; j ++) cin >> task[j][i];
		if(i != n - 1) for(int j = 0 ; j < 2 ; j ++) cin >> moving[i][j];	
	}



	min_time[0][0] = task[0][0];
	min_time[1][0] = task[1][0];
	
	
	for(int i = 1 ; i < n ; i ++){

		min_time[0][i] = min(min_time[0][i-1], min_time[1][i-1] + moving[i-1][1]) +task[0][i]; // A -> A 직전에 직진한 경우, B -> A 직전에서 옮겨온 경우

		min_time[1][i] = min(min_time[1][i-1], min_time[0][i-1] + moving[i-1][0]) +task[1][i]; // B -> B 직전에 직진한 경우, A -> B 직전에서 옮겨온 경우

	}


	cout << min(min_time[0][n-1], min_time[1][n-1]);

	return 0;
}