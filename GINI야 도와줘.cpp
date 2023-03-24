#include <iostream>
#include <queue>
#define INF 987654321
#define X first
#define Y second
using namespace std;
typedef pair<int, int> P;
int dr[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char map[50][50];
int d[50][50];
int f[50][50];
int n, m;

int rain(){
	queue<P> q;
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < m ; j ++){
			if(map[i][j] == '*'){
				q.push({i, j});
				d[i][j] = 0;
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
			if(map[nx][ny] != '.') continue;
			if(d[nx][ny] > d[cur.X][cur.Y] + 1){
				d[nx][ny] = d[cur.X][cur.Y] + 1;
				q.push({nx, ny});
			}
		}
	}
}

int move(){
	queue<P> q;
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < m ; j ++){
			if(map[i][j] == 'W') {
				q.push({i, j});
				f[i][j] = 0;
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
			if(map[nx][ny] == 'X') continue;
			if(f[cur.X][cur.Y] + 1 >= d[nx][ny]) continue;
			if(f[nx][ny] > f[cur.X][cur.Y] + 1){
				f[nx][ny] = f[cur.X][cur.Y] + 1;
				q.push({nx, ny});
			}
 		}
	}
}


int main(int argc, char** argv)
{	
	cin >> n >> m;
	for(int i = 0 ; i < n ; i ++) cin >> map[i];
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < m ; j ++){
			d[i][j] = INF;
			f[i][j] = INF;
		}
	}
	rain();
	move();
	
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < m ; j ++){
			if(map[i][j] == 'H') {
				if(f[i][j] == INF) cout << "FAIL";
				else cout << f[i][j];
				return 0;
			}
		}
	}
	
	return 0;
}