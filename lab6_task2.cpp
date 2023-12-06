#include <iostream>
#include <vector>

int main() {
    using namespace std;
    setlocale(LC_ALL, "ru");

    int M, N;
    cout << "Введите количество строк M: ";
    cin >> M;

    cout << "Введите количество столбцов N: ";
    cin >> N;

    if (M <= 0 || N <= 0) {
        cerr << "Ошибка: некорректные значения M и N." << endl;
        return 1;
    }

    // Используем вектор векторов вместо динамических массивов
    vector<vector<int>> matrix(M, vector<int>(N));

    // Ввод матрицы
    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << "Элемент строчки " << i+1 <<" столбца " << j+1 <<": ";
            cin >> matrix[i][j];
        }
    }

    // Поиск минимального и максимального элементов
    int minElement = INT_MAX;
    int maxElement = INT_MIN;
    int minRow = 0, maxRow = 0;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] < minElement) {
                minElement = matrix[i][j];
                minRow = i;
            }
            if (matrix[i][j] > maxElement) {
                maxElement = matrix[i][j];
                maxRow = i;
            }
        }
    }

    // Обмен строк с минимальным и максимальным элементами
    if (minRow != maxRow) {
        swap(matrix[minRow], matrix[maxRow]);
    }

    // Вывод измененной матрицы
    cout << "Матрица после обмена строк:\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}