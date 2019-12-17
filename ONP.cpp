#include <iostream>
#include <string>

using namespace std;

int temp;

struct tree{
	char    val;
	tree* right;
	tree*  left;
	int start,end;

	tree(string str,int s){
		if(str[s]=='('){
			left  = new tree(str,s+1);
			val   = str[temp];
			right = new tree(str,temp+1);
			temp  = temp+1;
		} else {
			val = str[s];
			left  = NULL;
			right = NULL;
			temp = s+1;
		}
	}
	string RPN(){
		if(right==NULL&&left==NULL)
			return string(1,val);
		else 
			return left->RPN()+right->RPN()+val;
	}
};

int main(){
	int T;
	cin >> T;
	string str;
	for (int t = 0; t < T; ++t)
	{
		cin >> str;
		cout << tree(str,0).RPN() << endl;

	}
	return 0;
}