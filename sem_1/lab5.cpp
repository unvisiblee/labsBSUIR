#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Найти сумму элементов массива, расположенных между первым и вторым отрицательными элементами массива.

int main() {

    // задание переменных и выбор режима работы программы

    srand(time(NULL));
    int SIZE, sum, mode;
    sum = 0;

    cout << "Select a program mode : \n 0 - Get numbers from keyboard, \n 1 - randomize numbers" << '\n';
    cin >> mode;

    cout << "Enter the size of the array: " << '\n';
    cin >> SIZE;

    int arr[SIZE];

    // Определение элементов массива в зависимости от режима работы программы

    if (mode == 1) {
        for (int i = 0; i < SIZE; i++) {
            arr[i] = (rand() % 100) - 50; // Заполняем массив числами от -50 до +50
            cout << arr[i] << " ";
        }
        cout << " " << '\n';
    } else {
        for (int i = 0; i < SIZE; i++) {
            cout << "Enter the value of the array element under index " << i << '\n';
            cin >> arr[i];
        }
        cout << " " << '\n';
    }

    // Подсчёт суммы элементов между первым и вторым отрицательными элементами

    int k = 0;  // k - переменная состояния, если 0 - отрицательного не было, если 1 - отрицательное было, если 2 - прекращаем работу
    for (int i = 0; i < SIZE; i++) {
        if (k == 2) break;
        if (arr[i] < 0) {
            k++;
            continue;
        }
        if (k == 1) sum += arr[i];

    }

    if (sum == 0) cout << "The negative values are located nearby or there is no such values..." << '\n';
    else cout << "The sum of the values located between first 2 negative values is " << sum << '\n';

}

// Written by Vladimir Dragun 16.09.2019, BSUIR