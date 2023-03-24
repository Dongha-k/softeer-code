#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
	int n, m;
	int cnt = 0;
	int limit[100];
	cin >> n >> m;
	for(int i = 0 ; i < n ; i ++){
		int x, speed;
		cin >> x >> speed;
		for(int j = cnt ; j < cnt + x ; j ++){
			limit[j] = speed;
		}
		cnt += x;
	}

	int res = 0;
	cnt = 0;
	for(int i = 0 ; i < m ; i ++){
		int x, speed;
		cin >> x >> speed;
		for(int j = cnt ; j < cnt + x ; j ++){
			res = max(res, speed - limit[j]);
		}
		cnt += x;

	}
	cout << res;
	return 0;
}