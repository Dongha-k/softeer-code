#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
	int a, b;
	cin >> a >> b;
	if(a > b) cout << 'A';
	else if(a < b) cout << 'B';
	else cout << "same";
	return 0;
}