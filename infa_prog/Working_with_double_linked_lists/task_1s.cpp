#include <iostream>
#include <algorithm>

using namespace std;

struct list {   // структура списка
	int inf;
	list* next;
	list* prev;
};

void push(list*& h, list*& t, int x) { //вставка элемента в конец списка
	list* r = new list;  //создаем новый элемент
	r->inf = x;
	r->next = NULL;  //всегда последний
	if (!h && !t) {   //если список пуст
		r->prev = NULL;   //первый элемент
		h = r;      //голова
	}
	else {
		t->next = r;   //r - следующий для хвоста 
		r->prev = t;    //хвост - предыдущий для r
	}
	t = r;       //r теперь хвост
}

void delNode(list*& h, list*& t, list*& x) {//удаляем элемент
	if (x == h && x == t) {    //единственный элемент списка
		h = t = NULL;
	}
	else if (x == h) {       //удаляем голову списка
		h->next->prev = NULL;      //сдвигаем голову
		h = h->next;
	}
	else if (x == t) {     //удаляем хвост списка
		t->prev->next = NULL;    //сдвигаем хвост
		t = t->prev;
	}
	else {
		x->next->prev = x->prev; //для следующего от х предыдущим становится х->prev
		x->prev->next = x->next; //для предыдущего от х следующим становится х->next
	}
	delete x;   //удаляем х
}

void print(list*& h, list*& t) {	// вывод списка
	list* p = h;   //указатель на голову
	while (p) {        //пока не дошли до конца списка
		cout << p->inf << ' ';
		p = p->next;        //переход к следующему элементу
	}
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "rus");
	int n;
	cin >> n;		//кол-во элементов
	list* h = NULL;
	list* t = NULL;
	int x;
	int maxi = -1000000;
	for (int i = 0; i < n; i++) {			// вводим элементы списка
		cin >> x;
		maxi = max(maxi, x);
		push(h, t, x);
	}
	for (list* x = h; x != NULL; ) {		// проходимся по списку и если
		if (x->inf == maxi) {				// элемент равен максимуму, удаляем его
			list* q = x->next;
			delNode(h, t, x);
			x = q;
		}
		else
			x = x->next;
	}
	print(h, t);

	return 0;
}