#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
typedef unsigned long long ll;

int main(int argc, char** argv)
{
	int n;
	char str[20];
	cin >> n;
	cin >> str;
	
	ll b = atoll(str);
	
	vector<ll> a(n);
	for(int i = 0 ; i < n ; i ++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	
	ll first = a.front();
	ll last = a.back() + (ll) pow(b, 0.5);
	ll answer = 0;
	
	while(first <= last){
	
		ll mid = (first + last) / 2; // mid : 최소 성능
		ll bal = 0;
		
		bool inBound = true;
		for(int i = 0 ; i < n ; i ++){
			if(a[i] >= mid) break;
			else if(bal + (mid - a[i]) * (mid - a[i]) > b){
				inBound = false;
				break;
			}
			else bal += (mid - a[i]) * (mid - a[i]);
		}

		if(inBound){
			first = mid + 1;
			answer = mid;
		}
		else last = mid - 1;
	}
	
	cout << answer;

	return 0;
}