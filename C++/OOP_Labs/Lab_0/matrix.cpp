#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Matrix { // Объявление класса матрица

    size_t rows, columns; // Приватные поля класса Matrix
    vector< vector < double > > values;
public:
    Matrix(size_t rows, size_t columns): rows(rows), columns(columns) { //Конструктор класса Matrix
        
        values.resize(rows);
        for (size_t i = 0; i < rows; ++i) {
            values[i].resize(columns);
        }
    };

    size_t getRows() { // Так как поля rows и columns скрыты от пользователя, опишем геттеры
        return this->rows;
    }

    size_t getColumns() {
        return this->columns;
    }

    void create() { // Создание матрицы

        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < columns; ++j) {
                cout << "Введите элемент [" << i << "] " << "[" << j << "] : ";
                cin >> values[i][j];
            }
        }
        cout << "---------- Матрица создана ----------" << endl << endl;
    }
    
    void output() { // Печать матрицы
        for (size_t i = 0; i < rows; ++i) {
            cout << "[ ";
            for (size_t j = 0; j < columns; ++j) {
                cout << values[i][j] << " ";
            }
            cout << "] " << endl;
        }
    }
    bool empty() { // Проверка на пустую матрицу
        if (values.empty()) {
            return true;
        } else {
            return false;
        }
    }  

    bool equal_size(const Matrix other) { // Проверка на одинаковый размер
        return rows == other.rows && columns == other.columns;
    }
    bool can_multiply(const Matrix other){ // Проверка на допустимость сложения
        return columns == other.rows;
    }

    void add(const Matrix other) { // Сложение
        if (!equal_size(other)) {
            cout << "Невозможно сложить матрицы с разными размерами";
        } else {
            for (size_t i = 0; i < rows; ++i) {
                for (size_t j = 0; j < columns; ++j) {
                    values[i][j] += other.values[i][j];
                }
            }
        }
    }

    void sub(const Matrix other) { // Вычитание
        if (!equal_size(other)) {
            cout << "Невозможно вычитать матрицы с разными размерами";
        } else {
            for (size_t i = 0; i < rows; ++i) {
                for (size_t j = 0; j < columns; ++j) {
                    values[i][j] -= other.values[i][j];
                }
            }
        }
    }

    void multiply(double k) { // Умножение на скаляр
        for (size_t i = 0; i < rows; ++i) {
                for (size_t j = 0; j < columns; ++j) {
                    values[i][j] *= k;
                }
        }
    }

    void divide(double k) { // Деление на скаляр
        for (size_t i = 0; i < rows; ++i) {
                for (size_t j = 0; j < columns; ++j) {
                    values[i][j] /= k;
                }
        }
    }

    Matrix multiply(const Matrix other) { // Умножение матриц
        if (!can_multiply(other)) {
            cout << "Невозможно перемножить матрицы с такими размерами";
        } else {
            Matrix result = Matrix(rows, other.columns);

            for (size_t i = 0; i < rows; ++i) {
                for (size_t j = 0; j < other.columns; ++j) {
                    result.values[i][j] = 0;
                    for (size_t k = 0; k < columns; ++k) {
                        result.values[i][j] += values[i][k] * other.values[k][j];
                    }
                }
            }
            return result;
        }
    }

    Matrix transpose() { // Транспонирование
        Matrix transp = Matrix(columns, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                transp.values[j][i] = values[i][j];
            }
        }
        return transp;
    }

    ~Matrix(){} // Деструктор
};

int main() { // Реализация класса Matrix пользовательской программой
    int rows, columns;
    int command;
    bool flag = true;

    do
    {
        cout << "Введите вашу задачу (перемножить - 1, сложить- 2, транспонировать - 3, умножить на число - 4,завершить - 0): ";
        cin >> command;
        if (command == 0) {
            flag = false;
        } else if (command == 1) {
            cout << "Введите количество рядов и столбцов для матрицы 1: ";
            cin >> rows >> columns;
            Matrix matrix = Matrix(rows, columns);
            matrix.create();

            cout << "Введите количество рядов и столбцов для матрицы 2: ";
            cin >> rows >> columns;
            Matrix matrix_2 = Matrix(rows, columns);
            matrix_2.create();
            if (matrix.getColumns() == matrix_2.getRows()){
                Matrix result = matrix.multiply(matrix_2);
                cout << "Результирующая матрица: " << endl;
                result.output();
            } else {
                cout << "Невозможно перемножить матрицы таких размеров" << endl << endl;
            }
            
        } else if (command == 2){
            cout << "Введите количество рядов и столбцов для матрицы 1: ";
            cin >> rows >> columns;
            Matrix matrix = Matrix(rows, columns);
            matrix.create();

            cout << "Введите количество рядов и столбцов для матрицы 2: ";
            cin >> rows >> columns;
            Matrix matrix_2 = Matrix(rows, columns);
            matrix_2.create();
            if (matrix.getColumns() == matrix_2.getColumns() && matrix_2.getRows() == matrix.getRows()) {
                matrix.add(matrix_2);
            
                cout << "Результирующая матрица: " << endl;
                matrix.output();
            } else {
                cout << "Невозможно сложить матрицы таких размеров" << endl << endl;
            }

        } else if (command == 3) {
            cout << "Введите количество рядов и столбцов для матрицы: ";
            cin >> rows >> columns;
            Matrix matrix = Matrix(rows, columns);
            matrix.create();
            Matrix transposed = matrix.transpose();
            cout << "Транспонированная матрица: " << endl;
            transposed.output();
        } else if (command == 4){
            cout << "Введите количество рядов и столбцов для матрицы: ";
            cin >> rows >> columns;
            Matrix matrix = Matrix(rows, columns);
            matrix.create();
            cout << "Введите число для умножения: ";
            double number;
            cin >> number;
            matrix.multiply(number);
            cout << "Результирующая матрица: " << endl;
            matrix.output();
        } else {
            cout << "Несуществующая команда: " << endl;
        }
    } while (flag);
}