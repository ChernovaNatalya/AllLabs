//#ifndef _MY_STACK_
#define _MY_STACK_

#include <iostream>
#include <string>

using namespace std;

template <class T>
class TStack {
protected:
	int size;
	int top;
	T* mas;
public:
	TStack(int n = 0);
	TStack(TStack<T>& stack);
	~TStack();

	void Push(T a);
	T Pop();
	T TopView();

	int GetSize();
	int GetTop();

	//операторы вводы и выводы

	bool IsEmpty();
	bool IsFull();

	TStack& operator=(const TStack<T>& stack);

	friend ostream& operator<<(ostream& ostr, const TStack<T>& stack) noexcept {
		ostr << "My Stack: " << endl;
		for (int i = 0; i < stack.size; i++) {
			ostr << stack.mas[i] << endl;
		}
		return ostr;
	}
	friend istream& operator>>(istream& istr, const TStack<T>& stack) noexcept {
		for (int i = 0; i < stack.size; i++) {
			istr >> stack.mas[i];
		}
		return istr;
	}
};

template <class T>
TStack<T>::TStack(int n) {
	if (n > 0)
	{
		size = n;
		top = 0;
		mas = new T[size];
	}
	else
	{
		throw "Negative size";
	}
}

template <class T>
TStack<T>::TStack(TStack<T>& stack) {
	if (stack.mas == nullptr)
	{
		size = 0;
		top = 0;
		mas = nullptr;
	}
	else
	{
		size = stack.size;
		top = stack.top;
		mas = new T[size];
		for (int i = 0; i < size; i++) {
			mas[i] = stack.mas[i];
		}
	}
}

template <class T>
TStack<T>::~TStack() {
	delete[]mas;
	size = 0;
	top = 0;
}

template <class T>
bool TStack<T>::IsEmpty() {
	if (top == 0) {
		return true;
	}
	else {
		return false;
	}
}

template <class T>
bool TStack<T>::IsFull() {
	if (top == size) {
		return true;
	}
	else {
		return false;
	}
}

template <class T>
void TStack<T>::Push(T el) {
	if (IsFull()) {
		throw "Stack is full";
	}
	mas[top] = el;
	top++;
}

template <class T>
T TStack<T>::Pop() {
	if (IsEmpty()) {
		throw "Stack is empty";
	}
	top--;
	return mas[top];
}

template <class T>
int TStack<T>::GetSize() {
	return size;
}

template <class T>
int TStack<T>::GetTop() {
	return top;
}

template <class T>
T TStack<T>::TopView() {
	if (IsEmpty()) {
		throw "Stack is empty";
	}
	return mas[top - 1];
}

template <class T>
TStack<T>& TStack<T>::operator=(const TStack<T>& stack) {
	if (this == &stack) {
		return *this;
	}
	delete[]mas;
	size = stack.size;
	top = stack.top;
	mas = new T[size];
	for (int i = 0; i < size; i++) {
		mas[i] = stack.mas[i];
	}
}





class TCalculator {
private:
	string infix;
	string postfix;
	TStack<double> st;
	TStack<char> stop;

public:

	TCalculator() :st(25), stop(25)
	{
		infix = "";
		postfix = "";
	}
	TCalculator(string str) : st(str.length()), stop(str.length()) {
		infix = str;
		postfix = "";

	}
	void SetExpression(string expression) {
		infix = expression;
	}
	string GetExpression() {
		return infix;
	}
	string GetPostfix() {
		return postfix;
	}
	int Priority(char elem);
	void ToPostfix();
	double CalculatePostfix();
	double CalculateAll();
};
int TCalculator::Priority(char elem) {
	switch (elem) {
	case'(':
	case')':return 1;
	case'+':
	case'-':return 2;
	case'*':
	case'/':return 3;
	default: throw elem;
	}

}

void TCalculator::ToPostfix() {
	postfix = "";
	string src = "(" + infix + ")";
	char elem = '!';
	unsigned int i = 0;
	while (i < src.size()) {
		if (src[i] >= '0' && src[i] <= '9' || src[i] == '.') {
			postfix += src[i];
		}
		else if (src[i] == '+' || src[i] == '-' || src[i] == '*' || src[i] == '/') {
			postfix += " ";
			elem = st.Pop();
			while (Priority(elem) >= Priority(src[i])) {
				postfix += elem;
				elem = st.Pop();
			}
			st.Push(elem);
			st.Push(src[i]);
		}
		else if (src[i] == '(') {
			st.Push(src[i]);
		}
		else if (src[i] == ')') {
			elem = st.Pop();
			while (elem != '(') {
				postfix += elem;
				elem = st.Pop();
			}
		}
		i++;
	}
}

double TCalculator::CalculatePostfix() {
	unsigned int i = 0;

	while (i < postfix.size()) {
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
			double b = st.Pop();
			double a = st.Pop();
			switch (postfix[i]) {
			case '+': {
				st.Push(a + b);
				break;
			}
			case '-': {
				st.Push(a - b);
				break;
			}
			case '*': {
				st.Push(a * b);
				break;
			}
			case '/': {
				st.Push(a / b);
				break;
			}
			}
		}
		else if (postfix[i] >= '0' && postfix[i] <= '9' || postfix[i] == '.') {
			size_t idx;
			double tmp = stod(&postfix[i], &idx); //перевод строки в число (число double, количество символов)   например stod("6.123, &idx) выведет 6.123 5
			st.Push(tmp);
			i += idx - 1;
		}
		i++;
	}
	return st.Pop();
}

double TCalculator::CalculateAll() {
	ToPostfix();
	return CalculatePostfix();
}


 
