#include <iostream>
#include <map>
#include <string>
#define MOD 1000000007
using namespace std;
typedef unsigned long long ull;
map<string, ull> cache;
ull pow(ull x, ull a){ // x ^ a
	if(a == 0) return 1;
	else if(a == 1) return x;
	if(cache.count(to_string(a / 2)) == 0)	cache[to_string(a / 2)] = pow(x, a / 2);
	if(cache.count(to_string(a / 2 + a % 2)) == 0)	cache[to_string(a / 2 + a % 2)] = pow(x, a / 2 + a % 2);
	
	return (cache[to_string(a / 2)] * cache[to_string(a / 2 + a % 2)]) % MOD;
}

int main(int argc, char** argv)
{
	ull k, p, n;
	cin >> k >> p >> n;
	cout << (k * pow(p, 10 * n)) % MOD;
	return 0;
}