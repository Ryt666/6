#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    int n, m;
    cout << "Введите количество строк: ";
    cin >> n;
    cout << "Введите количество столбцов: ";
    cin >> m;
    float** mass = new float* [n]; // строки в массиве
    for (int i = 0; i < n; i++)
    {
        mass[i] = new float[m]; // столбцы в массиве
    }
    cout << "Массив: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mass[i][j] = rand() % (20 + 1) - 2; //rand() % (b - a + 1) + a [a,b]
            cout << setw(4) << mass[i][j] << " ";
        }
        cout << endl;
    }
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (mass[i][j] < 0)
            {
                cout << "Номер столбца: " << j + 1 << "Номер строки: " << i + 1 << "  " << endl;
                for (int j = 0; j < m; j++)
                {
                    for (int i = 0; i < n; i++)
                    {
                        if (mass[i][j] < 0)
                       {
           
                            cout << "Номер строки: " << i + 1 << "  " << "Номер столбца: " << j + 1 << endl;
                            for (int i = 0; i < n; i++)
                            {
                                mass[i][j] /= 2;
                              for (int j = 0; j < m; j++)
                              {
                                cout << setw(4) << mass[i][j] << " ";
                              }
                                cout << endl;
                            }
                            return 0;
                        }
                    }
                }
            }
        }
    }
  
    for (int i = 0; i < n; i++)
    {
        delete[]mass[i];
    }
    return 0;
}