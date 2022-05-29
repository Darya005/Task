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

	bool empt(); // обозначаем функции
	void push(int x);
	void pop();
	int front();
	int back();
	void print();

	Queue();
	~Queue();
};

Queue::Queue() { // описываем конструктор
	h = t = NULL;
}

bool Queue::empt() { //функция проверки пустоты
	return h == NULL;
}

int Queue::front() { //функция вывода первого элемента
	return t->inf;
}

int Queue::back() { //функция вывода последнего элемента
	return h->inf;
}

void Queue::push(int x) { //функция добавления элемента

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

	if (front() != NULL)
	{
		Queue* now = t;
		t = t->next;
		delete now;
	}
}

void Queue::print() {//функция вывода очереди
	Queue* now = t;
	while (now != NULL) {
		cout << now->inf << ' ';
		now = now->next;
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

	int max_ = -100000000000;
	int min_ = max_ * -1;

	for (int i = 0; i < n; i++) {// Инициализируем очередь
		int x;
		cin >> x;
		max_ = max(x, max_); // ищем макс и мин
		min_ = min(x, min_);
		q.push(x);
	}

	for (int i = 0; i < n; i++) // вставляем перед максимальными минимальные
		if (q.front() == max_) {
			q.push(min_);
			q.push(q.front());
			q.pop();
		}
		else {
			q.push(q.front());
			q.pop();
		}

	q.print(); // выводим ответ

	return 0;
}

/*
9
5 1 2 1 5 3 4 5 1
*/


