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

vector<int> breadth(int x, vector<vector<int>>& Gr) //����� � ������
{
    vector<int> path;
    vector<int> used; used.resize(Gr.size());
    used[x] = 1; //x - ���������� �������
    path.push_back(x);
    queue<int> h;
    h.push(x); //��������� x � �������
    while (!h.empty()) { //���� ������� �� �����
        int y = h.front(); //��������� ������
        h.pop();
        for (int i = 0; i < Gr[y].size(); ++i)
            if (used[Gr[y][i]] != 1) {//���� ���������� ������������ ������� Gr[y][i],��
                used[Gr[y][i]] = 1;//�������� �� ��� ����������
                path.push_back(Gr[y][i]);//���������� � path
                h.push(Gr[y][i]);//�������� �� � �������
            }
    }
    return used;
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

    vector<int> used;
    vector<int> result;
    for (int j = 0; j < vec.size(); ++j) {      //������ ����� � ������
        used = breadth(j, vec);                 
        bool f = 1;                             //���� ��� ������� ���������, �� ��� �������� used ����� 1
        for (int i = 0; i < used.size(); ++i)
            if (used[i] != 1) {
                f = 0;
                break;
            }

        if (f) result.push_back(j);             //���� ��� �������� ����� 1, �� ����� ������� � result 
    }

    cout << "�����:" << endl;
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