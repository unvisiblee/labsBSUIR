#include <iostream>
using namespace std;

//	6. Задана матрица размером NxM. Определить количество различных значений матрицы, т.е. повторяющиеся элементы считать один раз.

int main() {
    int i, n, m, arr1pos; // n,m - размеры массива
    cout << "Enter size N: ";
    cin >> n;
    cout << "Enter size M: ";
    cin >> m;                  // получение размеров массива

    double **arr;
    arr = new double *[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new double[m];        //динамическое размещение двухмерного массива
    }

    cout << "Enter matrix NxM:" << '\n';
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {
            cin >> *(*(arr+i)+j);   //получение значений элементов матрицы
        }
    }

    double arr1[n*m];      // принцип: создаём новый массив arr1 и заносим туда все впервые встречающиеся уникальные элементы,
     arr1[0] = arr[0][0];  // если элемент повторяется - пропускаем, если уникален - добавляем к счётчику(arr1pos) +1 и заносим новый
                           // уникальный элемент в массив arr1, первый элемент матрицы заносится по умолчанию,
     arr1pos = 1;
     for(int i =0; i < n; i++) {

         for(int j = 0; j < m; j++) {
             int  isMatched = 0;


             for(int s = 0; s < arr1pos; s++) {

                 if (*(*(arr+i)+j) == arr1[s]) {
                     isMatched = 1;
                     s = arr1pos;
                 }

             }
             if(isMatched == 0) {
                 arr1[arr1pos++] = *(*(arr + i) + j);
             }
         }
     }
   cout << "The number of unique matrix elements is: " << arr1pos << '\n';
    for(int i = 0; i < n; i++) {   //очистка памяти
        delete []arr;
    }
}

// Written by Vladimir Dragun, 17.09.2019, BSUIR