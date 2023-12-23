//#ifndef _MY_STACK_
#define _MY_STACK_

#include <iostream>

using namespace std;

template <class T>
class TQueue {
protected:
	int size;
	int start;
	int end;
	int count;
	T* mas;

public:
	TQueue(int n = 0);
	TQueue(TQueue <T>& queue);
	~TQueue();

	void Push(T a);
	T Get();
	T Pop();

	bool IsFull();
	bool IsEmpty();

	int GetSize();
	int GetStart();
	int GetEnd();
	int GetCount();

	TQueue& operator=(const TQueue<T>& queue);
	bool operator!=(const TQueue<T>& queue);
	bool operator==(const TQueue<T>& queue);
	//операторы вводы и выводы
	friend ostream& operator<<(ostream& ostr, const TQueue<T>& queue) noexcept {
		ostr << "My Queue: " << endl;
		for (int i = 0; i < queue.size; i++) {
			ostr << queue.mas[i] << endl;
		}
		return ostr;
	}
	friend istream& operator>>(istream& istr, const TQueue<T>& queue) noexcept {
		for (int i = 0; i < queue.size; i++) {
			istr >> queue.mas[i];
		}
		return istr;
	}
};


template <class T>
TQueue<T>::TQueue(int n) {
	if (n > 0)
	{
		size = n;
		start = 0;
		end = 0;
		count = 0;
		mas = new T[size];
	}
	else
	{
		throw "Negative size";
	}
}

template <class T>
TQueue<T>::TQueue(TQueue<T>& queue) {
	if (queue.mas == nullptr)
	{
		size = 0;
		start = 0;
		end = 0;
		count = 0;
		mas = nullptr;
	}
	else
	{
		size = queue.size;
		start = queue.start;
		end = queue.end;
		count = queue.count;
		mas = new T[size];
		for (int i = 0; i < size; i++) {
			mas[i] = queue.mas[i];
		}
	}
}

template <class T>
TQueue<T>::~TQueue() {
	delete[]mas;
	size = 0;
	start = 0;
	end = 0;
	count = 0;
}

template <class T>
bool TQueue<T>::IsEmpty() {
	if (count == 0) {
		return true;
	}
	else {
		return false;
	}
}

template <class T>
bool TQueue<T>::IsFull() {
	if (count == size) {
		return true;
	}
	else {
		return false;
	}
}

template <class T>
void TQueue<T>::Push(T el) {
	if (IsFull()) {
		throw "Queue is full";
	}
	mas[end] = el;
	count++;
	end = (end + 1) % size;
}

template <class T>
T TQueue<T>::Get() {
	if (IsEmpty()) {
		throw "Queue is empty";
	}
	return mas[start];
}

template <class T>
T TQueue<T>::Pop() {
	if (IsEmpty()) {
		throw "Queue is empty";
	}
	T p = mas[start];
	mas[start] = 0;
	count--;
	start = (start + 1) % size;
	return p;
}

template <class T>
int TQueue<T>::GetSize() {
	return size;
}

template <class T>
int TQueue<T>::GetStart() {
	return start;
}

template <class T>
int TQueue<T>::GetEnd() {
	return end;
}

template <class T>
int TQueue<T>::GetCount() {
	return count;
}

template <class T>
TQueue<T>& TQueue<T>::operator=(const TQueue<T>& queue) {
	if (this == &queue) {
		return *this;
	}
	delete[]mas;
	size = queue.size;
	start = queue.start;
	end = queue.end;
	count = queue.count;
	mas = new T[size];
	for (int i = 0; i < size; i++) {
		mas[i] = queue.mas[i];
	}
}

template <class T>
bool TQueue<T>::operator==(const TQueue<T>& queue) {
	if (this == &queue) {
		return true;
	}
	if (size != queue.size) {
		return false;
	}
	for (int i = 0; i < size; i++) {
		if (mas[i] != queue.mas[i]) {
			return false;
		}
	}
	return true;
}

template <class T>
bool TQueue<T>::operator!=(const TQueue<T>& queue) {
	if (this == &queue) {
		return false;
	}
	if (size != queue.size) {
		return true;
	}
	for (int i = 0; i < size; i++) {
		if (mas[i] != queue.mas[i]) {
			return true;
		}
	}
	return false;
}
