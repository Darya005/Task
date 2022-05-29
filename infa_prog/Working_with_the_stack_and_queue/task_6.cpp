#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;


struct  Stack { // создаем структуру стек
	int inf;
	Stack* next;
	Stack* h;
	int max_;

	bool empt(); // обозначаем функции
	void push(int x);
	void pop();
	int head();
	void print();
	int s_max();

	Stack();
	~Stack();
};

Stack::Stack() { // описываем конструктор
	h = NULL;
}

int Stack::s_max() { // описываем функцию поиска максимума
	return max_;
}

bool Stack::empt() { //функция проверки пустоты
	return h == NULL;
}

void Stack::push(int x) { //функция добавления элемента
	max_ = max(x, max_);
	Stack* r = new Stack;
	r->inf = x;
	r->next = h;
	h = r;
}

void Stack::pop() { //функция удаления элемента

	Stack* now = h;
	h = h->next;
	now->next = NULL;
	delete now;
}

int Stack::head() { //фунция возврата значения верхнего элемента
	return h->inf;
}

void Stack::print() { //функция вывода стэка
	vector<int> a;
	Stack* now = h;
	while (now != NULL) {
		a.push_back(now->inf);
		now = now->next;
	}

	reverse(a.begin(), a.end());

	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
}

Stack::~Stack() { // описываем диструктор 
	while (h != NULL) {
		Stack* now = h;

		h = h->next;
		now->next = NULL;

		delete now;
	}
}

int main() {

	int n;
	cin >> n;
	Stack res;

	for (int i = 0; i < n; i++) { // инициализация
		int x;
		cin >> x;
		res.push(x);
	}

	Stack res1;

	while (!res.empt()) { // перезаписываем стек без максимумов
		if (res.head() != res.s_max())
			res1.push(res.head());
		res.pop();
	}

	Stack res2;

	while (!res1.empt()) { // разворачиваем стек
		res2.push(res1.head());
		res1.pop();
	}

	res2.print(); // выводим стэк

	return 0;
}

/*
8
5 1 1 5 3 4 5 1
*/


