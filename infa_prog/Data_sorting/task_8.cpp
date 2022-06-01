#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdio>
#include <math.h>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt"); // подключаем файлы

struct date {
	string name, prof, worktimer, dob;
	int salary;
};

date a[21];

bool cmp(date a, date b) { //функция сравнения переменнных
	return a.salary > b.salary || (a.salary == b.salary && a.dob > b.dob);

}

void sl(int l, int r) { //сортировка слиянием
	if (l - r == 0) //условие выхода
		return;
	if (l - r == 1) //если в массиве 2 элемента и они не отсортированы то сравниваем их
		if (cmp(a[l], a[r]))
			swap(a[l], a[r]);

	sl(l, (l + r) / 2); //массив рекурсивно разбивается пополам, и каждая из половин делиться до тех пор,
	sl((l + r) / 2 + 1, r);  //пока размер очередного подмассива не станет равным единице;

	int L, R;
	L = l;
	R = (l + r) / 2 + 1;
	date b[100]; //результирующий массив
	int v = 0;


	while (L < ((l + r) / 2 + 1) && R <= r) {
		if (cmp(a[L], a[R])) { //если левый больше
			b[v] = a[R]; //записываем в массив б по возрастанию
			v++;
			R++;
		}
		else { //если правый больше
			b[v] = a[L];
			v++;
			L++;
		}
	}

	while (L < ((l + r) / 2 + 1)) { //из двух результирующих массивов собирается третий общий отсортированный массив
		b[v] = a[L];
		L++;
		v++;
	}
	while (R <= r) {
		b[v] = a[R];
		R++;
		v++;
	}

	for (v = 0; l <= r; l++, v++)   //элементы перезаписываются из результирующего массива в исходный 
		a[l] = b[v];
}

int main() {

	int n;
	in >> n;

	for (int i = 0; i < n; i++)
		in >> a[i].name >> a[i].prof >> a[i].dob >> a[i].worktimer >> a[i].salary;

	sl(0, n - 1); //вызов сортировки

	out << "ans" << endl; //ответ
	for (int i = 0; i < n; i++)
		out << a[i].name << " " << a[i].prof << " " << a[i].dob << " " << a[i].worktimer << " " << a[i].salary << endl;

	return 0;
}