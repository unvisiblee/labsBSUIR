// lab5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

struct Stack {
	int info;
	Stack* next;
} *begin;

Stack* push(Stack* p, int in) {
	Stack* t = new Stack;			// Захватываем память для элемента
	t->info = in;			// Формируем информационную часть
	t->next = p;			// Формируем адресную часть
	return t;
}

void view(Stack* p) {
	Stack* t = p;
	while (t) {
		cout << t->info << endl; // Вывод на экран информационной части, например, cout <<  t -> info << endl;
		t = t->next;
	}
}

Stack* pop(Stack* p, int *out) {
	Stack* t = p;
	*out = p->info;
	p = p->next;
	delete t;
	return p;
};

void Del_All(Stack** p) {
	Stack* t;
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}



int main()
{
	Stack* myStack = NULL;
	myStack = push(myStack, 5);
	myStack = push(myStack, 10);
	myStack = push(myStack, 15);
	int a;
	myStack = pop(myStack, &a);
	Del_All(&myStack);
	view(myStack); 

}
