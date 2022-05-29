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

        if (x > N || y > N) //ориентированный граф
            continue;
        else
            Gr[x].push_back(y);

    }
    for (int i = 0; i < N; i++)
        sort(Gr[i].begin(), Gr[i].end()); //сортируем

    for (int i = 0; i < N; ++i)
        Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end()); //удаляем дубликаты

    return Gr;
}
 
void depth(int x, vector<vector<int>>& Gr, vector<int>& used, vector<int>& path) { //обход в глубину
    used[x] = 1;
    path.push_back(x);
    for (int i = 0; i < Gr[x].size(); ++i) {
        if (used[Gr[x][i]] != 1)
            depth(Gr[x][i], Gr, used, path);
    }
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

    int x; cout << "Введите вершину" << endl;
    cin >> x;
    vector<int> res;
    vector<int> used; used.resize(N);
    vector<int> path;
    depth(x, vec, used, path);      //проходим по графу от данной вершины
    cout << "Вершины:"<<endl;       //все элементы в used, не равные 1 - недостижимые
    for (int i = 0; i < used.size(); ++i)
        if (used[i] != 1)
            cout << i << " ";

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