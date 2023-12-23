#include <iostream>
#include <ctime>
#include "MyStack.h"

using namespace::std;

int main()
{
	//TStack<int> st(5);
	//cin >> st;
	//cout << st;
	//string abc = "(1+2+(12/3)*5+4)/9";
	string abc;
	int n = 60000;
	for (int i = 1; i < n; i++) {
		abc += to_string(i) + "*";
	}
	abc += to_string(n);
	//cout << abc <<endl;
	//cout << "!" << endl;
	unsigned int start_time = clock();
	//cin >> abc;
	TCalculator cal;
	cal.SetExpression(abc);
	cal.ToPostfix();
	//cout << cal.GetPostfix() << endl;
	//cout << cal.CalculatePostfix() << endl;
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << search_time;
}
