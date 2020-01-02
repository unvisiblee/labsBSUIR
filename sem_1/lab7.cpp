#include <iostream>
#include <string>

using namespace std;

//  6. Из строки, состоящей из букв, цифр, запятых, точек, знаков + и – , выделить подстроку, которая соответствует записи целого числа.

int main() {

    string s1, number;
    cout << "Enter the string: ";
    getline(cin, s1);
    for(int i = 0; i < s1.length(); i++) { // Находим первое число в строке и проверяем, не стоит ли перед ним минус, если стоит - добавляем минус в строку, затем
                                           // идём дальше по строке, пока числовые значения не закончатся.
        if(isdigit(s1[i])) {

            if(s1[i-1] == '-' || s1[i-1] == '+') {

                if(s1[i-1] == '-') {
                    number =+ '-';
                }
                else {
                    number =+'+';
                }
            }
            while(isdigit(s1[i])) {
                    number += s1[i];
                    i++;
            }
            break;

        }
    }
    cout << number;
}

// Written by Vladimir Dragun 16.09.2019
