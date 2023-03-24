#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef pair<int, int> P;
P position[26];
bool used[26] = {false, };
char table[5][5] = {0, };
int main(int argc, char** argv) {
	string message, key;
	cin >> message >> key;
	
	// J -> I
	for(auto& m : message) if(m == 'J') m = 'I';
	for(auto& k : key) if(k == 'J') key = 'I';
	
	int idx = 0;
	for(char k : key){
		if(used[k-'A']) continue;
		used[k-'A'] = true;
		table[idx / 5][idx % 5] = k;
		idx ++;
	}
	
	used['J' - 'A'] = true;

	for(int i = 0 ; i < 26 ; i ++){
		if(used[i]) continue;
		used[i] = true;
		table[idx / 5][idx % 5] = i + 'A';
		idx ++;
	}
	

	for(int i = 0 ; i < 5 ; i ++){
		for(int j = 0 ; j < 5 ; j ++){
			position[table[i][j] - 'A'] = {i, j};
		}
	}

	string encoded_msg = "";

	for(int i = 0 ; i < message.size() ; i ++){
		if(encoded_msg.size() % 2 == 1 and encoded_msg.back() == message[i]){	
			if(encoded_msg.back() == 'X') encoded_msg += 'Q';
			else encoded_msg += 'X';
		}
		encoded_msg += message[i];
	}

	
	if(encoded_msg.size() % 2 == 1) encoded_msg += 'X';
	
	vector<pair<char, char>> v;
	
	for(int i = 0 ; i < encoded_msg.size() ; i += 2){
		v.push_back({encoded_msg[i], encoded_msg[i + 1]});
	}



	string result = "";
	for(auto x : v){
		char a = x.first;
		char b = x.second;
		int a_x = position[a-'A'].first;
		int a_y = position[a-'A'].second;
		int b_x = position[b-'A'].first;
		int b_y = position[b-'A'].second;

		if(a_x == b_x){
			result += table[a_x][(a_y + 1) % 5];
			result += table[b_x][(b_y + 1) % 5];
		}
		else if(a_y == b_y){
			result += table[(a_x + 1) % 5][a_y];
			result += table[(b_x + 1) % 5][b_y];
		}
		else{
			result += table[a_x][b_y];
			result += table[b_x][a_y];
			
		}
	}
	cout << result;

	


	return 0;
}