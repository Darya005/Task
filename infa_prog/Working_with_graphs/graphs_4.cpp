#include <iostream>                                                                                    
#include <vector>                                   
#include <algorithm>                                 
#include <queue>                                     
#include <stack>
using namespace std;
//��������� ����� �� ������
vector<vector<int>> SS(int N, int M) { //������ ���������
    vector<vector<int>> Gr;
    Gr.resize(N); //�������� ������ ��� � �����
    for (int i = 0; i < M; i++) {//���� �� ������� ��� �����
        int x, y;
        cout << "������� ��� ������� x � y" << endl;
        cin >> x >> y;

        if (x > N || y > N) //��������������� ����
            continue;
        else
            Gr[x].push_back(y);

    }
    for (int i = 0; i < N; i++)
        sort(Gr[i].begin(), Gr[i].end()); //���������

    for (int i = 0; i < N; ++i)
        Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end()); //������� ���������

    return Gr;
}
 
void depth(int x, vector<vector<int>>& Gr, vector<int>& used, vector<int>& path) { //����� � �������
    used[x] = 1;
    path.push_back(x);
    for (int i = 0; i < Gr[x].size(); ++i) {
        if (used[Gr[x][i]] != 1)
            depth(Gr[x][i], Gr, used, path);
    }
}

void output(vector<vector<int>> vec) { //������� ��� ������ ������ ���������
    cout << "������ ���������: \n";
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

    cout << "���������� ������ � �����" << endl;
    cin >> N >> M;

    vector<vector<int>> vec = SS(N, M);
    output(vec);

    int x; cout << "������� �������" << endl;
    cin >> x;
    vector<int> res;
    vector<int> used; used.resize(N);
    vector<int> path;
    depth(x, vec, used, path);      //�������� �� ����� �� ������ �������
    cout << "�������:"<<endl;       //��� �������� � used, �� ������ 1 - ������������
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