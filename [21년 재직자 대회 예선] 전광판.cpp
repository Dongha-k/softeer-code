#include <iostream>
#include <string>
using namespace std;

unsigned char segment[11] = {
	0b11111100,
	0b01100000,
	0b11011010,
	0b11110010,
	0b01100110,
	0b10110110,
	0b10111110,
	0b11100100,
	0b11111110,
	0b11110110,
	0b00000000
};
int get_bit_count(unsigned char c){
	int cnt = 0;
	for(int i = 0 ; i < 8 ; i ++){
		if( ( (c & (1 << i) ) >> i) == 1) cnt ++;
	}
	return cnt;
}

int get_diff(int a, int b){
	unsigned char res = segment[a]^segment[b];
	return get_bit_count(res);
}

int main(int argc, char** argv)
{
	int n;

	cin >> n;
	for(int i = 0 ; i < n ; i ++){
		int res = 0;

		string a, b;
		cin >> a >> b;
		if(a.size() > b.size()){
			int len = a.size() - b.size();
			for(int i = 0 ; i < len ; i ++){
				b = (char)('0' + 10) + b;
			}
		}
		else {
			int len = b.size() - a.size();
			for(int i = 0 ; i < len ; i ++){
				a = (char)('0' + 10) + a;
			}
		}
		for(int i = 0 ; i < b.size() ; i ++){
			res += get_diff(a[i] - '0', b[i] - '0');
		}
		cout << res << '\n';
		
	}

	return 0;
}