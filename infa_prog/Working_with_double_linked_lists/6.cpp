#include <iostream>
#include <algorithm>
using namespace std;

struct list {							// структура списка
	int inf;
	list* next;
	list* prev;
};

void push(list*& h, list*& t, int x) { // заполнение списка
	list* r = new list;
	r->inf = x;
	r->next = NULL;
	if (!h && !t) {
		r->prev = NULL;
		h = r;
	}
	else {
		t->next = r;
		r->prev = t;
	}
	t = r;
}

void print(list*& h, list*& t) {	// вывод списка
	list* p = h;
	while (p) {
		cout << p->inf << ' ';
		p = p->next;
	}
	cout << endl;
}

void pop(list*& h, list*& t, list*& x) {//удаляем элемент
	if (x == h && x == t) {
		h = t = NULL;
	}
	else if (x == h) {
		h->next->prev = NULL;
		h = h->next;
	}
	else if (x == t) {
		t->prev->next = NULL;
		t = t->prev;
	}
	else {
		x->next->prev = x->prev;
		x->prev->next = x->next;
	}
	delete x;
}

int main() {
	setlocale(LC_ALL, "rus");
	int n;
	cin >> n;		//кол-во элементов
	list* ah = NULL;
	list* at = NULL;

	list* bh = NULL;
	list* bt = NULL;
	int x;
	while (n--) {
		int x;
		cin >> x; //вводим числа распределяя их по двум стекам
		if (x % 2)
			push(ah, at, x);
		else
			push(bh, bt, x);
	}

	list* resh = NULL;
	list* rest = NULL;

	list* q = bh;
	while (bh && bt) { 
		list* temp = q->next;
		push(resh, rest, q->inf);             // добавляем его в конец
		pop(bh, bt, q);                   // удалем из головы
		q = temp;
	}
	list* q1 = ah;
	while (ah && at) {
		list* temp = q1->next;
		push(resh, rest, q1->inf);             // добавляем его в конец
		pop(ah, at, q1);                   // удалем из головы
		q1 = temp;
	}

	print(resh, rest);
}

/*
9
4 2 6 8 1 2 3 2 10
*/

