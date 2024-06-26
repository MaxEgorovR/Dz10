#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
class Queue {
	shared_ptr<T[]> arr;

	int length = 0;

	int count = 0;

public:
	Queue() {}

	Queue(int length)
	{
		cout << "Enter all elems:\n";
		this->length = length;
		this->arr = make_shared<T[]>(length);
		for (int i = 0; i < length; i++) {
			cin >> arr[i];
			this->count++;
		}
	}

	Queue(int length, shared_ptr<T[]>& arr)
	{
		this->length = length;
		this->arr = arr;
	}

	void pop() {
		this->length--;
		shared_ptr<T[]> tmp = make_shared<T[]>(this->length);
		for (int i = 1; i < this->length + 1; i++) {
			tmp[i - 1] = this->arr[i];
		}
		this->arr.swap(tmp);
	}

	void push_back(T elem) {
		this->length++;
		shared_ptr<T[]> tmp = make_shared<T[]>(this->length);
		for (int i = 0; i < this->length - 1; i++) {
			tmp[i] = this->arr[i];
		}
		tmp[this->length - 1] = elem;
		this->arr.swap(tmp);
	}

	void info() {
		cout << "The length: " << this->count << endl;
		cout << "The count of elems: " << this->count << endl;
		cout << "All elems:\n";
		for (int i = 0; i < this->length; i++) {
			cout << this->arr[i] << " ";
		}
		cout << endl;
	}
};