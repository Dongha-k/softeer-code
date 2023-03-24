#include <iostream>
#include <string>

using namespace std;

int get_minute(string s){
	int hh = stoi(s.substr(0, 2));
	int mm = stoi(s.substr(3, 5));
	return hh * 60 + mm;
}
int main(int argc, char** argv)
{
	int total = 0;
	for(int i = 0 ; i < 5 ; i ++){
		string a, b;
		cin >> a >> b;
		int a_minute = get_minute(a);
		int b_minute = get_minute(b);
		total += b_minute - a_minute;
	}
	cout << total;
	return 0;
}