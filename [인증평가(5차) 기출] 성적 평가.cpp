#include <iostream>

using namespace std;
int main(int argc, char** argv)
{
	int n;
	int cnt[3][1001] = {0, };
	int total_cnt[3001] = {0, };
	int total_per_person[100000] = {0, };
	int score_per_person[3][100000] = {0, };


	int total[3001] = {0, };
	cin >> n;
	for(int c = 0 ; c < 3 ; c ++){
		for(int i = 0 ; i < n ; i ++){
			int x; 
			cin >> x;
			cnt[c][x] ++;
			score_per_person[c][i] = x;
			total_per_person[i] += x;
		}
	}
	
	
	for(int i = 0 ; i < n ; i ++) total_cnt[total_per_person[i]] ++;
	
	// cnt 계산
	for(int c = 0 ; c < 3 ; c ++){
		int cur_cnt = 0;
		for(int i = 1000 ; i >= 0 ; i --){
			if(cnt[c][i] == 0) continue;
			int before = cnt[c][i];
			cnt[c][i] = cur_cnt + 1;
			// cout << i << " : " << cnt[c][i] << ' ';
			cur_cnt += before;
		}
		for(int i = 0 ; i < n ; i ++) cout << cnt[c][score_per_person[c][i]] << ' ';
		cout << '\n';
	}
	

	// total 계산
	int cur_cnt = 0;
	for(int i = 3000 ; i >= 0 ; i --){
		if(total_cnt[i] == 0) continue;
		int before = total_cnt[i];
		total_cnt[i] = cur_cnt + 1;
		cur_cnt += before;
	}
	for(int i = 0 ; i < n ; i ++) cout << total_cnt[total_per_person[i]] << ' ';
	cout << '\n';
	return 0;
}
