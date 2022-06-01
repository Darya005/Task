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

bool cmp(date a, date b) { //функция сравнения переменных
	return a.name > b.name || (a.name == b.name && a.worktimer > b.worktimer) || (a.name == b.name && a.worktimer == b.worktimer && a.salary > b.salary);

}

void ChnCh(int n) { //сортировка чет нечет
	for (int i = 0; i <= n - 1; i++) //элементы сравниваются парами; Для четных i проход начинается с нуля, для нечетных — с единицы
		if (i % 2 == 0)
			for (int j = 2; j <= n - 1; j += 2)
				if (cmp(a[j - 1], a[j]))
					swap(a[j - 1], a[j]);
				else;
		else
			for (int j = 1; j <= n - 1; j += 2)
				if (cmp(a[j - 1], a[j]))
					swap(a[j - 1], a[j]);
}

int main() {

	int n;
	in >> n;

	for (int i = 0; i < n; i++)
		in >> a[i].name >> a[i].prof >> a[i].dob >> a[i].worktimer >> a[i].salary;

	ChnCh(n); //вызов сортировки

	out << "ans" << endl; //ответ
	for (int i = 0; i < n; i++)
		out << a[i].name << " " << a[i].prof << " " << a[i].dob << " " << a[i].worktimer << " " << a[i].salary << endl;

	return 0;
}