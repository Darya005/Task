#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;


struct  Queue { // создаем структуру очередь
	int inf;
	Queue* next;
	Queue* h;
	Queue* t;
	int plus_ = 0;
	int minus_ = 0;

	bool empt(); // обозначаем функции
	void push(int x);
	void pop();
	int plus();
	int minus();
	int front();
	int back();

	Queue();
	~Queue();
};

Queue::Queue() { // описываем конструктор
	h = t = NULL;
}

bool Queue::empt() { //функция проверки пустоты
	return h == NULL;
}

int Queue::plus() { // функция подсчета положительных
	return plus_;
}

int Queue::minus() { // функция подсчета отрицательных
	return minus_;
}

int Queue::front() { //функция вывода первого элемента
	return t->inf;
}

int Queue::back() { //функция вывода последнего элемента
	return h->inf;
}

void Queue::push(int x) { //функция добавления элемента
	if (x < 0)
		minus_++;
	else
		plus_++;

	if (h == NULL) {
		Queue* inf = new Queue;
		h = inf;

		inf->inf = x;
		inf->next = NULL;

		t = h;
	}
	else {
		Queue* now = new Queue;
		now->inf = x;
		now->next = NULL;
		h->next = now;
		h = now;
	}
}

void Queue::pop() { //функция удаления элемента
	if (t->inf < 0)
		minus_--;
	else
		plus_--;


	if (front() != NULL)
	{
		Queue* now = t;

		t = t->next;

		delete now;
	}
}

Queue::~Queue() { // описываем диструктор 
	while (h != NULL) {
		Queue* now = h;

		h = h->next;
		now->next = NULL;

		delete now;
	}
}

int main() {

	int n;
	cin >> n;
	Queue q;

	for (int i = 0; i < n; i++) { // инициализируем очередь
		int x;
		cin >> x;
		q.push(x);
	}

	for (int i = 0; i < n; i++) // выводим сначала отрицат потом положит 
		if (q.front() < 0) {
			cout << q.front() << ' ';
			q.pop();
		}
		else {
			q.push(q.front());
			q.pop();
		}
	while (!q.empt()) {
		cout << q.front() << ' ';
		q.pop();
	}
	return 0;
}

/*
9
1 -5 7 9 -8 -6 2 3 1
*/


