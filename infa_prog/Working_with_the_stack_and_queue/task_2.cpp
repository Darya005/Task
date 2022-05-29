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

	bool empt(); // обозначаем ее функции
	void push(int x);
	void pop();
	int head();
	void print();

	Stack();
	~Stack();
};

Stack::Stack() { // описываем конструктор
	h = NULL;
}

bool Stack::empt() { //функция проверки пустоты
	return h == NULL;
}

void Stack::push(int x) { //функция добавления элемента

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
	Stack a, b;

	while (n--) {
		int x;
		cin >> x;
		if (x % 2)
			b.push(x);
		else
			a.push(x);
	}

	Stack b1, a1, res;

	while (!b.empt()) { // записываем в стек сначала нечетные потом четные
		res.push(b.head());
		b.pop();
	}
	while (!a.empt()) {
		res.push(a.head());
		a.pop();
	}

	Stack res1;

	while (!res.empt()) { // разварачиваем стек
		res1.push(res.head());
		res.pop();

	}
	res1.print(); // выводим стэк

	return 0;
}

/*
7
1 1 2 3 4 5 1
*/


