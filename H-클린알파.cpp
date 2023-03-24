#include <iostream>
#include <map>
#define MOD 1000000007
using namespace std;
typedef unsigned long long ull;

map<int, ull> cache;

ull pow(int x, int a){ // x ^ a
	if(a == 0) return 1;
	else if(a == 1) return x;
	else{
		if(cache.count(a / 2) == 0) cache[a / 2] = pow(x, a / 2);
		if(cache.count(a / 2 + a % 2) == 0) cache[a / 2 + a % 2] = pow(x, a / 2 + a % 2);
		return (cache[a / 2] * cache[a / 2 + a % 2]) % MOD;
	}
}

int main(int argc, char** argv)
{
	int p, n;
	ull res = 0;
	cin >> p >> n;
	while(n--){
		ull a;
		cin >> a;
		res += (a * pow(p, n))  % MOD;
	}
	cout << res % MOD;
	return 0;
}