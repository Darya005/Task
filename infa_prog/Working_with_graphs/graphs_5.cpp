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

vector<int> breadth(int x, vector<vector<int>>& Gr) //обход в ширину
{
    vector<int> path;
    vector<int> used; used.resize(Gr.size());
    used[x] = 1; //x - посещенная вершина
    path.push_back(x);
    queue<int> h;
    h.push(x); //добавляем x в очередь
    while (!h.empty()) { //пока очередь не пуста
        int y = h.front(); //извлекаем голову
        h.pop();
        for (int i = 0; i < Gr[y].size(); ++i)
            if (used[Gr[y][i]] != 1) {//если существует непосещенная вершина Gr[y][i],то
                used[Gr[y][i]] = 1;//помечаем ее как посещенную
                path.push_back(Gr[y][i]);//записываем в path
                h.push(Gr[y][i]);//пщмещаем ее в очередь
            }
    }
    return used;
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

    vector<int> used;
    vector<int> result;
    for (int j = 0; j < vec.size(); ++j) {      //делаем обход в ширину
        used = breadth(j, vec);                 
        bool f = 1;                             //если все вершины перебрали, то все элементы used равны 1
        for (int i = 0; i < used.size(); ++i)
            if (used[i] != 1) {
                f = 0;
                break;
            }

        if (f) result.push_back(j);             //если все элементы равны 1, то пушим вершину в result 
    }

    cout << "Ответ:" << endl;
    for (int i = 0; i < result.size(); ++i)
        cout << result[i] << " ";

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