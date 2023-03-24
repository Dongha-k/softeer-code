#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define X first
#define Y second
using namespace std;
typedef pair<int, int> P;

int n;
int dr[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
bool visited[25][25] = {false, };
int grid[25][25];
int bfs(int x, int y){
	queue<P> q;
	int res = 0;
	q.push({x, y});
	visited[x][y] = true;
	
	while(!q.empty()){
		P cur = q.front();
		res ++;
		q.pop();
		for(int i = 0 ; i < 4 ; i ++){
			int nx = cur.X + dr[i][0];
			int ny = cur.Y + dr[i][1];
			if(nx < 0 or ny < 0 or nx >= n or ny >= n) continue;
			if(grid[nx][ny] == 0) continue;
			if(visited[nx][ny]) continue;
			visited[nx][ny] = true;
			q.push({nx, ny});
		}
	}
	return res;
}
int main(int argc, char** argv)
{
	cin >> n;
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < n ; j ++){
			char ch;
			cin >> ch;
			grid[i][j] = ch - '0';
		}
	}

	vector<int> res;
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < n ; j ++){
			if(grid[i][j] == 1 and !visited[i][j]) res.push_back(bfs(i, j));
		}
	}
	cout << res.size() << '\n';
	sort(res.begin(), res.end());
	for(auto r : res) cout << r << '\n';
	return 0;
}