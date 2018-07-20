#include <iostream>
using namespace std;
#include "shape.h"
#include "circle.h"

ostream &operator<<(ostream &out, CShape &P) {
	P.Print();
	return out;
}

template <typename T>
struct Node {
	T data;
	Node<T> *next;
	Node<T> *prev;
	Node(T d, Node<T> *n = NULL, Node<T> *p = NULL) : data(d), next(n), prev(p) {}
};

template <typename T>
class ListIterator {
private:
	Node<T> *ptr;

public:
	ListIterator(Node<T> *p = 0) : ptr(p) {}
	void operator++(int) { ptr = ptr->next; }
	void operator--(int) { ptr = ptr->prev; }
	T &operator*() { return ptr->data; }
	void operator=(Node<T> *p) { ptr = p; }
	ListIterator<T> operator+(int adv) {
		ListIterator<T> tmp;
		for (int i = 0 ; i < adv ; i++) {
			ptr = ptr->next;
			tmp = ptr;
		}
		for (int i = 0 ; i < adv ; i++)
			ptr = ptr->prev;

		return tmp;
	}
	template <typename S>friend class MyList;
};

template <typename T>
class MyList {
private:
	Node<T> *start;
	Node<T> *last;

public:
	MyList() : start(NULL), last(NULL) {}
	typedef ListIterator<T> iterator;
	Node<T> *begin() { return start; }
	Node<T> *rbegin() { return last; }
	void push(T d) {
		Node<T> *temp = new Node<T>(d, NULL, NULL);
		if (start == NULL) {
			start = temp;
			last = temp;
		}
		else {
			temp->prev = last;
			last->next = temp;
			last = temp;
		}
	}
	void insert(iterator iter, T d) {
		push(last->data);
		Node<T> *temp_add = new Node<T>(d, NULL, NULL);
		Node<T> *temp_tmp = new Node<T>(d, NULL, NULL);
		iterator add(temp_add);
		iterator tmp(temp_tmp);
		*add = *iter;
		*iter = d;
		iterator end(last);
		iter++;
		for (; iter != end ;) {
			*tmp = *iter;
			*iter = *add;
			*add = *tmp;
			iter++;
		}
		delete temp_add;
		delete temp_tmp;
	}
};
	
int main(void) {
	int i;
	MyList<CCircle<double> > intL;
	MyList<CCircle<double> >::iterator lIter;

	for (i = 0 ; i < 5 ; i++)
		intL.push(CCircle<double>(1, 1, i + 1.1));

	lIter = intL.begin();
	intL.insert(lIter + 2, CCircle<double>(1, 1, 1.1));
	for (i = 0 ; i < 6 ; i++) {
		cout << *lIter;
		lIter++;
	}

	lIter = intL.rbegin();
	for (i = 0 ; i < 6 ; i++) {
		cout << *lIter;
		lIter--;
	}

	return 0;
}
