#include <iostream>
#include <vector>
using namespace std;

long long dis(pair<long long, long long> a, pair<long long, long long> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
	long long x0, y0, ax, ay, bx, by;
	cin >> x0 >> y0 >> ax >> ay >> bx >> by;
	long long xs, ys, t;
	cin >> xs >> ys >> t;
	vector<pair<long long, long long>> v;
	for(; x0 <= 1e18 / ax && y0 <= 1e18 / ay; x0 = ax * x0 + bx, y0 = ay * y0 + by) {
		v.push_back({x0, y0});
	}
	pair<long long, long long> start = {xs, ys};
	int ans = 0;
	for(int i = 0; i < v.size(); i++)
		for(int j = i; j < v.size(); j++) {
			if(t >= min(dis(start, v[i]), dis(start, v[j])) + dis(v[j], v[i])) ans = max(ans, j - i + 1);
		}
	cout << ans << endl;
	return 0;
}
