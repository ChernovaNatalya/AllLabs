#include <iostream>
#include <ctime>
#include "MyQueue.h"

using namespace::std;

int main()
{
	unsigned int start_time = clock();	
	int n = 100000;
	TQueue<int> q(n);
	for (int i = 0; i < n; i++) {
		q.Push(i);
	}
	//cout << q;
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << search_time;
}
