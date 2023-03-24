#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;
int dr[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int ice[100][100];
int nxt[100][100];
bool inner[100][100] = {false, };
bool visited[100][100] = {false, };
int n, m;
typedef pair<int, int> P;

void segmentation(){
	for(int i = 0 ; i < n ; i ++) for(int j = 0 ; j < m ; j ++) inner[i][j] = true;
	queue<P> q;
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < m ; j ++){
			if(ice[i][j] == 1) inner[i][j] = false;
			if(i == 0 or i == n - 1 or j == 0 or j == m - 1){
				q.push({i, j});
				inner[i][j] = false;
			}
		}
	}

	while(!q.empty()){
		P cur = q.front();
		q.pop();
		for(int i = 0 ; i < 4 ; i ++){
			int nx = cur.X + dr[i][0];
			int ny = cur.Y + dr[i][1];
			if(nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
			if(!inner[nx][ny]) continue;
			inner[nx][ny] = false;
			q.push({nx, ny});
		}
	}
	
}
void melting(){
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < m ; j ++){
			if(ice[i][j] == 0) continue;
			int cnt = 0;
			for(int k = 0 ; k < 4 ; k ++){
				int nx = i + dr[k][0];
				int ny = j + dr[k][1];
				if(ice[nx][ny] == 0 and inner[nx][ny]) continue;
				if(ice[nx][ny] == 0) cnt ++;
			}
			if(cnt >= 2) nxt[i][j] = 0;
			else nxt[i][j] = 1;
		}
	}
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < m ; j ++){
			ice[i][j] = nxt[i][j];
		}
	}
}

int check(){
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < m ; j ++){
			if(ice[i][j] == 1) return false;
		}
	}
	return true;
}
int main(int argc, char** argv)
{
	cin >> n >> m;
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < m ; j ++){
			cin >> ice[i][j];
		}
	}
	int t;
	for(t = 0 ; ; t ++){
		if(check()) break;
		segmentation();
		// for(int i = 0 ; i < n ; i ++){
		// 	for(int j = 0 ; j < m ; j ++){
		// 		cout << inner[i][j] << ' ';
		// 	}
		// 	cout << '\n';
		// }
		// cout << '\n';
		melting();
	}
	cout << t;	
	return 0;
}