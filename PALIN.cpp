#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct BI{
	vector<short> num ;
	BI(){
		num = vector<short>();
		char ch;
		while((ch = cin.get())!='\n')
			num.push_back(ch-'0');
	}

	void pp(int pos){
		if(pos == -1)
			num.insert(num.begin(),1);
		else if(num[pos] == 9){
			num[pos] = 0;
			pp(pos-1);
		}else 
			num[pos]++;
	}

	void pp(){
		pp(num.size()-1);
	}

	operator bool(){
		for(int i=0;i<=num.size()/2;i++)
			if(num[i]!=num[num.size()-i-1])
				return false;
		return true;
	}

	string to_string(){
		string str = "";
		for(int i=0;i<num.size();i++)
			str+=::to_string(num[i]);
		return str;
	}
};

int main(){
	int T;
	cin >> T;
	cin.get();
	while(T--){
		BI n = BI();
		do{n.pp();}while((bool)n);
		cout << n.to_string() << endl;
	}
	return 0;
}