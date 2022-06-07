#include <iostream>
#include <algorithm>

using namespace std;

struct list {   // ��������� ������
	int inf;
	list* next;
	list* prev;
};

void push(list*& h, list*& t, int x) { //������� �������� � ����� ������
	list* r = new list;  //������� ����� �������
	r->inf = x;
	r->next = NULL;  //������ ���������
	if (!h && !t) {   //���� ������ ����
		r->prev = NULL;   //������ �������
		h = r;      //������
	}
	else {
		t->next = r;   //r - ��������� ��� ������ 
		r->prev = t;    //����� - ���������� ��� r
	}
	t = r;       //r ������ �����
}

void pop(list*& h, list*& t, list*& x) {//������� �������
	if (x == h && x == t) {    //������������ ������� ������
		h = t = NULL;
	}
	else if (x == h) {       //������� ������ ������
		h->next->prev = NULL;      //�������� ������
		h = h->next;
	}
	else if (x == t) {     //������� ����� ������
		t->prev->next = NULL;    //�������� �����
		t = t->prev;
	}
	else {
		x->next->prev = x->prev; //��� ���������� �� � ���������� ���������� �->prev
		x->prev->next = x->next; //��� ����������� �� � ��������� ���������� �->next
	}
	delete x;   //������� �
}

void print(list*& h, list*& t) {	// ����� ������
	list* p = h;   //��������� �� ������
	while (p) {        //���� �� ����� �� ����� ������
		cout << p->inf << ' ';
		p = p->next;        //������� � ���������� ��������
	}
	cout << endl;
}

void sort(list*& h, list*& t) {						//���������� ���������
	for (list* x = h->next; x != NULL; x = x->next)
	{
		list* a = x;
		while (a->prev != NULL && a->inf < a->prev->inf)
		{
			swap(a->inf, a->prev->inf);
			a = a->prev;
		}
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	int n;
	cin >> n;		//���-�� ���������
	list* h = NULL;
	list* t = NULL;
	int x;
	for (int i = 0; i < n; i++) {	  // ������ �������� ������
		cin >> x;
		push(h, t, x);
	}

	sort(h, t);                       //���������a
	print(h, t);

	return 0;
}