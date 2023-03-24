#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char** argv)
{
	vector<int> robot_pos;
	int line[20000];
	bool picked[20000] = {false, };
	int n, k;
	cin >> n >> k;
	
	for(int i = 0 ; i < n ; i ++){
		char ch;
		cin >> ch;
		line[i] = ch;
		if(ch == 'P') {
			robot_pos.push_back(i);
			picked[i] = true;
		}
	}

	int res = 0;
	for(auto x : robot_pos){
		for(int i = max(0, x - k) ; i <= min(n - 1, x + k) ; i ++){
			if(!picked[i]){
				res ++;
				picked[i] = true;
				break;
			}
		}
	}
	cout << res;
	
	return 0;
}


//   HHH HH P PPPP H P H P H P H HH P