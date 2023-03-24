#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int n;
	int arr[5000];
	int d[5001];
	unsigned long long res = 0;
	cin >> n;
	for(int i = 0 ; i < n ; i ++) cin >> arr[i];
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j <= n ; j ++) d[j] = 0;
		for(int j = 0 ; j < i ; j ++) if(arr[i] > arr[j]) d[arr[j]] = 1;
		for(int j = n - 1; j > 0 ; j --) d[j] += d[j + 1];
		for(int j = i + 1 ; j < n ; j ++) res += d[arr[j]];
	}
	cout << res;
	return 0;
}