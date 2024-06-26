#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
class LinkedList {
public:
	struct Node {
	public:
		T val;

		shared_ptr < Node> next;

		Node() :next(nullptr) {}

		Node(T val) :val(val), next(nullptr) {}

		Node(T val, shared_ptr < Node> next) :val(val), next(next) {}
	};

	shared_ptr<Node> head;

	shared_ptr<Node> back;

	LinkedList():head(nullptr),back(nullptr) {}

	LinkedList(T val)
	{
		this->head = make_shared<Node>(val);
		this->back = this->head;
	}

	void push_back(T elem) {
		if (head == nullptr) {
			head = make_shared<Node>(elem);
		}
		else {
			shared_ptr<Node> cur = head;
			shared_ptr<Node> newNode = make_shared<Node>(elem);
			while (cur->next != nullptr) {
				cur = cur->next;
			}
			this->back = newNode;
			cur->next = newNode;
		}
	}

	void pop(T elem) {
		shared_ptr<Node> cur = head;
		if (cur->val == elem) {
			if (this->head == this->back) {
				this->back = this->back->next;
			}
			this->head = this->head->next;
		}
		else {
			while (cur->next != nullptr) {
				if (cur->next->val == elem) {
					if (cur->next == this->back) {
						this->back = cur;
					}
					cur = cur->next->next;
					break;
				}
				cur = cur->next;
			}
		}
	}

	void info() {
		shared_ptr<Node> cur = head;
		if (cur != nullptr) {
			cout << "All elems:\n";
			if (cur->next == nullptr) {
				cout << cur->val;
			}
			else {
				while (cur->next != nullptr) {
					cout << cur->val << " ";
					cur = cur->next;
				}
				cout << cur->val;
			}
			cout << endl;
		}
	}
};