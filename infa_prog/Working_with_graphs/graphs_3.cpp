#include <iostream>                                                                                    
#include <vector>                                   
#include <algorithm>                                 
#include <queue>                                     
#include <stack>
using namespace std;
//алгоритмы взяты из лекций
vector<vector<int>> SS(int N, int M) { //список смежности
    vector<vector<int>> Gr;
    Gr.resize(N); //выделяем память под Н строк
    for (int i = 0; i < M; i++) {//пока не считали все ребра
        int x, y;
        cout << "Введите две вершины x и y" << endl;
        cin >> x >> y;

        if (x > N || y > N) //неориентированный граф
            continue;
        else {
            Gr[x].push_back(y);
            Gr[y].push_back(x);
        }

    }
    for (int i = 0; i < N; i++)
        sort(Gr[i].begin(), Gr[i].end()); //сортируем

    for (int i = 0; i < N; ++i)
        Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end()); //удаляем дубликаты

    return Gr;
}

void output(vector<vector<int>> vec) { //функция для вывода списка смежности
    cout << "Список смежности: \n";
    for (int i = 0; i < vec.size(); ++i) {
        cout << i << ": ";
        for (int j = 0; j < vec[i].size(); ++j)
            cout << vec[i][j] << " ";
        cout << endl;
    }
}
void main()
{
    setlocale(LC_ALL, "rus");
    int N, M;

    cout << "количество вершин и ребер" << endl;
    cin >> N >> M;

    vector<vector<int>> vec = SS(N, M);
    output(vec);

    cout << "Ответ:" << endl;
    int k;
    for (int j = 0; j < vec.size(); ++j) { 
        cout << j << ": ";
        k = 0;
        for (int i = 0; i < vec[j].size(); ++i) //ищем вершины
            k++;
        cout << k << endl; 
    }

}
/*
4 4
0 1
0 2
0 3
1 2
*/

/*

   0----3
   | \
   |  2
   | /
   1

*/