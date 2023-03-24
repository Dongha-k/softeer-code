#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> P;

int dr[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int pixel[128][128];

int n, m;
void bfs(int x, int y, int p){
	int myColor = pixel[x][y];
	queue<P> q;
	q.push({x, y});
	pixel[x][y] = p;

	while(!q.empty()){
		P cur = q.front();
		q.pop();
		for(int i = 0 ; i < 4 ; i ++){
			int nx = cur.X + dr[i][0];
			int ny = cur.Y + dr[i][1];
			if(nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
			if(pixel[nx][ny] != myColor) continue;
			pixel[nx][ny] = p;
			q.push({nx, ny});
		}
	}
}
int main(int argc, char** argv)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin >> n >> m;

	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < m ; j ++){
			cin >> pixel[i][j];
		}
	}
	
	cin >> q;

	for(int i = 0 ; i < q ; i ++){
		int x, y, p;
		cin >> x >> y >> p;
		x --;
		y --;
		if(pixel[x][y] == p) continue;
		bfs(x, y, p);
	}
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < m ; j ++){
			cout << pixel[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}