#include <iostream>
#include <algorithm>
#define X first
#define Y second
#define ABS(x) ( ((x) > 0) ?  (x) : -(x))
using namespace std;
typedef pair<int, int> P;
int n, m, q;

int dr[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

P get_possible_pos(int table[20][20]){
	static int D[25][25];
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < m ; j ++){
			D[i][j] = 10000000;
			for(int x = 0 ; x < n ; x ++){
				for(int y = 0 ; y < m ; y ++){
					if(table[x][y] != 0) D[i][j] = min(D[i][j], (i - x) * (i - x) + (j - y) * (j - y));
				}
			}
		}
	}

	P result = {-1, -1};
	int max_d = -1;
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < m ; j ++){
			if(table[i][j] != 0) continue;
			int possible = true;
			for(int k = 0 ; k < 4 ; k ++){
				int nx = i + dr[k][0];
				int ny = j + dr[k][1];
				if(nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
				
				if(table[nx][ny] != 0){
					possible = false;
					break;
				}
			}
			if(possible){
				if(max_d < D[i][j]){
					max_d = D[i][j];
					result = {i, j};
				}
			}
		}
	}
	return result;
}
int main(int argc, char** argv)
{
	bool eat[10001] = {false, };
	bool leave[10001] = {false, };
	P mySeat[10001];
	int table[20][20] = {0, };
	cin >> n >> m >> q;
	for(int i = 0 ; i < q ; i ++){
		string cmd;
		int idx;
		cin >> cmd >> idx;

		switch(cmd[0]){
			case 'O':
				if(!eat[idx]) cout << idx << " didn't eat lunch.\n";
				else if(leave[idx]) cout << idx << " already left seat.\n";
				else {
					leave[idx] = true;
					table[mySeat[idx].X][mySeat[idx].Y] = 0;
					cout << idx << " leaves from the seat (" << mySeat[idx].X + 1 << ", " << mySeat[idx].Y + 1 << ").\n";
				}
			break;			
			case 'I':
				if(eat[idx] and !leave[idx]) cout << idx << " already seated.\n";
				else if(leave[idx]) cout << idx << " already ate lunch.\n";
				else {
					P pos = get_possible_pos(table);
					if(pos.X == -1 and pos.Y == -1) cout << "There are no more seats.\n";
					else{
						eat[idx] = true;
						table[pos.X][pos.Y] = idx;
						mySeat[idx] = pos;
						cout << idx << " gets the seat (" << pos.X + 1 << ", " << pos.Y + 1 << ").\n";
					}
				}
			break;
		}
	}
	
	return 0;
}
