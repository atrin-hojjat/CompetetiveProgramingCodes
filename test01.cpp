#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n,cars = 0;
	cin >> n;
	vector<short> s = vector<short>();
	for (int i = 0; i < n; ++i)
	{
		short x;
		cin >> x;
		s.push_back(x);
	}
	for (int i = 0; i < n; ++i)
	{
		if(s.empty())
			break;
		short begin_val = *s.begin();
		vector<short>::iterator strt_loc = s.begin() +1;
		vector <vector<short>::iterator> rm_locs{s.begin()};
		for (;begin_val <4;)
		{
			vector<short>::iterator best_loc;
			short best_sum_val = -1;
			for (vector<short>::iterator iter = strt_loc;iter!=s.end();++iter)
			{
				short sum_val = *iter + begin_val;
				if(sum_val <=4 && sum_val > best_sum_val){
					best_sum_val = sum_val;
					best_loc = iter;
				}
			}
			if(best_sum_val >0){
				begin_val = best_sum_val;
				strt_loc = best_loc+1;
				rm_locs.push_back(best_loc);
			}
			if(best_sum_val<=0)
				break;
		}
		for (vector<vector<short>::iterator>::iterator iter = rm_locs.begin();
			iter!=rm_locs.end();++iter)
		{
			s.erase(*iter);
		}
		++cars;
	}
	cout << cars << endl;
	return 0;
}