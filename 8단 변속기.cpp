#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char** argv)
{
	int res = 0;
	int mul = pow(10, 7);
	for(int i = 0 ; i < 8 ; i ++){
		int x;
		cin >> x;
		res += (x * mul);
		mul /= 10;
	}
	if(res == 12345678) cout << "ascending";
	else if(res == 87654321) cout << "descending";
	else cout << "mixed";
	return 0;
}