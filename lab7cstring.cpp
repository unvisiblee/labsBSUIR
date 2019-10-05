
#include <string.h>
#include <iostream>
    using namespace std;

// 	6. Из строки, состоящей из букв, цифр, запятых, точек, знаков + и – , выделить подстроку, которая соответствует записи целого числа.
    int main() {
        char s1[255];
        char number[255];

        cout << "Enter the string: ";
        cin >> s1;
        int pos = 0;

        for(int i = 0; i < strlen(s1); i++) {

            if(isdigit(s1[i])) {
                if(s1[i-1] == '-') {
                    number[0] = '-';
                    pos++;
                }
                while(isdigit(s1[i])) {
                    number[pos] = s1[i];
                    pos++;
                    i++;
                }
                break;
            }
        }

        for( int i = 0; i < pos; i ++ ) {
            cout << number[i];
        }

    }

    // Written by Vladimir Dragun 16.09.2019, BSUIR
