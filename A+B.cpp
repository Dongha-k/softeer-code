#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
	int n;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++){
		int a, b;
		cin >> a >> b;
		cout << "Case #" << i << ": " << a + b << '\n'; 
	}
	return 0;
}