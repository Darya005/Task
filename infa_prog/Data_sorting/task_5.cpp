#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt"); // подключаем файлы

struct date {
	string name, prof, salary, worktimer, dob;
};

date a[21];

bool cmp(date a, date b) { //функция сравнения двух переменных
	return a.prof > b.prof;
}

void make_Heap(int v, int n) { //пирамидальная сортировка
	if ((2 * v + 1) >= n) //условие выхода
		return;

	make_Heap(2 * v + 1, n); //идем на левой стороне
	make_Heap(2 * v + 2, n); //по правой

	if (2 * v + 2 == n)//если сущ один сын то сравниваем его с его родителем
		if (cmp(a[2 * v + 1], a[v]))
			swap(a[v], a[2 * v + 1]);
		else;
	else //если 2 сына то сравниваем их
		if (cmp(a[2 * v + 1], a[2 * v + 2])) {  //если левый больше то сравниваем его с родителем
			if (cmp(a[2 * v + 1], a[v])) {
				swap(a[2 * v + 1], a[v]);
				make_Heap(2 * v + 1, n); //если поменяли элемент с родителем	то идем вниз по дереву и также проверяем 
			}
		}
		else
			if (cmp(a[2 * v + 2], a[v])) { //если правый больше то сравниваем его с родителем
				swap(a[2 * v + 2], a[v]);
				make_Heap(2 * v + 2, n);
			}
}

void check_Heap(int v, int n) {

	if ((2 * v + 1) >= n)
		return;

	if (2 * v + 2 == n)
		if (cmp(a[2 * v + 1], a[v]))
			swap(a[v], a[2 * v + 1]);
		else;
	else
		if (cmp(a[2 * v + 1], a[2 * v + 2])) {
			if (cmp(a[2 * v + 1], a[v])) {
				swap(a[2 * v + 1], a[v]);
				check_Heap(2 * v + 1, n);
			}
		}
		else
			if (cmp(a[2 * v + 2], a[v])) {
				swap(a[2 * v + 2], a[v]);
				check_Heap(2 * v + 2, n);
			}
}


int main() {

	int n;
	in >> n;

	for (int i = 0; i < n; i++)
		in >> a[i].name >> a[i].prof >> a[i].dob >> a[i].worktimer >> a[i].salary;

	make_Heap(0, n); //создаем кучу и сортируем ее
	swap(a[0], a[n - 1]); //меняем первый и последний элемент местами
	int m = n - 1;
	while (m > 0) { //проделываем то же самое в check_Heap пока существуют элементы 
		check_Heap(0, m);
		swap(a[0], a[m - 1]);
		m--;
	}

	out << "ans" << endl; //ответ
	for (int i = 0; i < n; i++)
		out << a[i].name << " " << a[i].prof << " " << a[i].dob << " " << a[i].worktimer << " " << a[i].salary << endl;

	return 0;
}