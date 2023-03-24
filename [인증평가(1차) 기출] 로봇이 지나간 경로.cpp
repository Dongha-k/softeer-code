#include <iostream>
#include <map>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> P;
int dr[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char arrow[4] = {'>', 'v', '<', '^'};
int main(int argc, char** argv)
{
	int n, m;
	char map[25][25];
	cin >> n >> m;
	for(int i = 0 ; i < n ; i ++){
		cin >> map[i];
	}
	
	P start = {-1, -1};
	P end = {-1, -1};
	int dir = -1;
	bool escape = false;
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < m ; j ++){
			if(map[i][j] == '#'){
				int cnt = 0;
				for(int k = 0 ; k < 4 ; k ++){
					int nx = i + dr[k][0];
					int ny = j + dr[k][1];
					if(nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
					if(map[nx][ny] == '#') cnt++;
					
				}
				if(cnt == 1) {
					if(start.X == -1) {
						start = {i, j};
						for(int k = 0 ; k < 4 ; k ++){
							int nx = i + dr[k][0];
							int ny = j + dr[k][1];
							if(nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
							if(map[nx][ny] == '#') {
								dir = k;
								break;
							}
						}
					}
					else{
						end = {i, j};
						escape = true;
						break;
					}
				}
			}
		}
		if(escape) break;
	}

	cout << start.X  + 1<< ' ' << start.Y + 1 << '\n' << arrow[dir] << '\n';
	
	P cur = start;
	
	while(cur.X != end.X or cur.Y != end.Y){
		int nx = cur.X + dr[dir][0];
		int ny = cur.Y + dr[dir][1];
		int nnx = nx + dr[dir][0];
		int nny = ny + dr[dir][1];

		// out of bound case 
		if(nnx < 0 or nnx >= n or nny < 0 or nny >= m or nx < 0 or nx >= n or ny < 0 or ny >= m or map[nx][ny] == '.' or map[nnx][nny] == '.') {
			int left_x = cur.X + dr[(dir + 3) % 4][0];
			int left_y = cur.Y + dr[(dir + 3) % 4][1];
			int right_x = cur.X + dr[(dir + 1) % 4][0];
			int right_y = cur.Y + dr[(dir + 1) % 4][1];

			if(left_x < 0 or left_x >= n or left_y < 0 or left_y >= m or map[left_x][left_y] == '.') {
				// turn right
				cout << "R";
				dir = (dir + 1) % 4;
			}
			else{
				// turn left
				cout << "L";
				dir = (dir + 3) % 4;
			}
		}
		else{
			cout << "A";
			cur = {nnx, nny};
		}
	}

	return 0;
}