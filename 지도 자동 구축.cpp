#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
	int len[16];
	len[0] = 2;
	for(int i = 1 ; i <= 15 ; i ++){
		len[i] = len[i-1] * 2 - 1;
	}
	int n;
	cin >> n;
	cout << len[n] * len[n];	

	return 0;
}