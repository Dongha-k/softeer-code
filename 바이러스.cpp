#include <iostream>
using namespace std;
typedef unsigned long long ull;
int main(int argc, char** argv)
{
	int k, p, n;
	cin >> k >> p >> n;
	ull res = k;
	
	for(int i = 0 ; i < n ; i ++) res = ((res * p) % 1000000007);
	cout << res;
	return 0;
}