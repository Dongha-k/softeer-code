#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main(int argc, char** argv)
{
	int n, q;
	vector<int> score;
	cin >> n >> q;
	score = vector<int>(n + 1, 0);

	for(int i = 1 ; i <= n ; i ++) {
		cin >> score[i];
		score[i] += score[i - 1];
	}

	
	while(q--){
		int a, b;
		cin >> a >> b;
		a--;
		printf("%.2f\n", (score[b] - score[a]) / (double)(b - a));
	}
	return 0;
}
