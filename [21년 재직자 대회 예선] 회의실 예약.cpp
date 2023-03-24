#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int n, m;
	
	cin >> n >> m;
	vector<vector<bool>> table(n, vector<bool>(11, false));
	vector<string> room_name(n);
	map<string, int> idx_of;
	for(int i = 0 ; i < n ; i ++){
		cin >> room_name[i];
	}
	sort(room_name.begin(), room_name.end());
	for(int i = 0 ; i <  n  ; i ++) idx_of[room_name[i]] = i;
	for(int i = 0 ; i < m ; i ++){
		string name;
		int begin, end;
		cin >> name >> begin >> end;
		begin -= 9;
		end -= 9;
		int idx = idx_of[name];
		for(int j = begin ; j < end ; j ++) table[idx][j] = true;
		table[idx].back() = true;
	}

	for(auto name : room_name){
		string print_out = "";

		int idx = idx_of[name];
		cout << "Room " << name << ":\n";
		int cnt = 0;
		int begin = -1;
		int end = -1;
		for(int i = 0 ; i < 10 ; i ++){
			if(table[idx][i]){
				if(begin != -1 and end != -1)	{
					cnt ++;
					if(begin == 0) print_out += "0";
					print_out += to_string(begin + 9) + "-" + to_string (end + 10) + '\n';
					begin = -1;
					end = -1;
				}
			}
			else{
				if(begin == -1) {
					begin = i;
					end = i;
				}
				else end = i;
			}
		}
		if(begin != -1 and end != -1 and begin != end){
			
			cnt++;
			if(begin == 0) print_out += "0";
			print_out += to_string(begin + 9) + "-" + to_string (end + 9) + '\n';

		}

		if(cnt == 0) cout << "Not available\n";
		else{
			cout << cnt << " available:\n";
			cout << print_out;
		}
		if(idx != n - 1) cout << "-----\n";
	}
	return 0;
}