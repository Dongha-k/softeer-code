#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case = 0;
	cin >> test_case;
	for(int t = 0 ; t < test_case ; t ++){
		int n;
		int result = 0;
		cin >> n;
		vector<int> service(n);
		for(int i = 0 ; i < n ; i ++) cin >> service[i];
		sort(service.begin(), service.end());
		// 300 <= service[i] <= 900
		int cnt = 0;
		for(int i = 0 ; i < n ; i ++){
			if(service[i] != 300) break;
			cnt ++; 
		}

		int start = cnt;
		int end = n - 1;
		while(start <= end){
			if(service[end] > 600){
				result ++;
				end --;
			}

			else if(service[end] == 600){
				if(cnt > 0) {
					result ++;
					end --;
					cnt --;
				}
				else {
					result ++;
					end --;
				}
			}

			else if(start != end and 300 < service[end] and service[end] < 600){
				if(service[start] + service[end] <= 900) {
					result ++;
					end --;
					start ++;
				}
				else if(cnt > 0){
					result ++;
					end --;
					cnt --;
				}
				else{
					result ++;
					end --;
				}
			}
			else if(start == end and 300 < service[end] and service[end] < 600) {
				if(cnt > 0){
					result ++;
					end --;
					cnt --;
				}
				else{
					result ++;
					end --;
				}
			}
			else break;
			
		}
		result += (cnt / 3);
		if(cnt % 3 != 0) result ++;
		cout << result << '\n';
	}
	return 0;
}