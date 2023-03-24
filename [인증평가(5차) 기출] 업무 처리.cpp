#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

queue<int> tree[2048]; // 1부터 2047 까지 노드의 번호로 인덱싱 / 0은 완료된 업무를 담아놓은 큐
int h, k, r;
int n;
ll result = 0;

void process(int x, int day){
	if(x == 0){
		if(!tree[1].empty()){
			tree[0].push(tree[1].front());
			tree[1].pop();
		}
		process(1, day);
	}
	else{
		if(x >= n) return; // 말단사원의 경우 그냥 넘김
		int target = -1;
		if(day % 2 == 1){ // 홀수일이면
			if(!tree[2*x].empty()) target = 2*x; // 왼쪽 자식노드의 업부부터 확인
		}
		else{ // 짝수일이면
			if(!tree[2*x+1].empty()) target = 2*x+1;
		}
		
		if(target != -1){
			// 업무를 target 직원으로부터 받음
			tree[x].push(tree[target].front());
			tree[target].pop();
		}
		process(2 * x, day);
		process(2 * x + 1, day);
	}
}
int main(int argc, char** argv)
{
	cin >> h >> k >> r;

	n = (1 << (h));
	int total = (1 << (h + 1)) - 1;
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < k ; j ++){
			int x;
			cin >> x;
			tree[n + i].push(x);
		}
	}


	// for(int i = 1 ; i <= 1023 ; i ++){
	// 	if(!tree[i].empty()){
	// 		cout << i << " : ";
	// 		while(!tree[i].empty()){
	// 			cout << tree[i].front() << ' ';
	// 			tree[i].pop();
	// 		}
	// 		cout << '\n';
	// 	}
	// }
	for(int day = 0 ; day < r ; day ++) {
		process(0, day);
		// for(int i = 0 ; i < (n << 1) ; i ++) cout << i << ' ' << tree[i].size() << '\n';
		
		// cout << '\n';
	}
	
	while(!tree[0].empty()) {
		// cout << tree[0].front() << ' ';
		result += tree[0].front();
		tree[0].pop();
	}
	cout << result;
	return 0;
}