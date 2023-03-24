#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	int k, m, n;
	string arr = "";
	string key = "";
	cin >> m >> n >> k;
	for(int i = 0 ; i < m; i ++) {
		char ch;
		cin >> ch;
		key += ch;
	}
	for(int i = 0 ; i < n; i ++) {
		char ch;
		cin >> ch;
		arr += ch;
	}

	for(int i = 0 ; i <= n - m ; i ++){
		if(key == arr.substr(i, m)) {
			cout << "secret";
			return 0;
		}
	}
	cout << "normal";
	return 0;
}