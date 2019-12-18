#include <iostream>
#include <ctime>
using namespace std;

struct Stack {
	int info;
	Stack* next;
};

Stack* push(Stack* p, int in) {
	Stack* t = new Stack;
	t->info = in;
	t->next = p;
	return t;
}

void view(Stack* p) {
	Stack* t = p;
	while (t) { // работает, потому что на конце стека t = NULL, что в if воспринимается как false
		cout << t->info << endl;
		t = t->next;
	}
}

Stack* pop(Stack* p, int &out) {
	Stack* t = p;
	out = p->info;
	p = p->next;
	delete t;
	return p;
};

void deleteAll(Stack** p) {
	Stack* buf;
	while (*p != NULL) {
		buf = *p;
		*p = (*p)->next;
		delete buf;
	}
}

void sortStack(Stack* p) {
	Stack* t = NULL, *t1;
	int buf;
	while (p->next != t) {
		for (t1 = p; t1->next != t; t1 = t1->next)
			if (t1->info > t1->next->info) {
				buf = t1->info;
				t1->info = t1->next->info;
				t1->next->info = buf;
			}
		t = t1;
	}
}

void swapMinMax(Stack* p) {
	Stack* t = p;
	Stack* min = t;
	Stack* max = t;
	int buff;
	while (t != NULL) {
		if (t->info > max->info) { // Если значение элемента стека меньше минимального или больше минимального, то меняем указатели..
			max = t;
		};
		if (t->info < min->info) {
			min = t;
		};
		t = t->next;
	};
	buff = max->info;
	max->info = min->info;
	min->info = buff;
}



int main()
{
	srand(time(NULL));
	Stack* my_stack = NULL; 
	int opt;
	while (true)
	{
		if (my_stack) {
			cout << '\n' << "Current stack:" << '\n';
			view(my_stack);
		};
		if (my_stack != NULL)
		{
			cout << '\n';
		}
		cout << "Enter 1 to fill up the stack with random numbers" << '\n' <<
			"Enter 2 to eject an element from the stack" << '\n' <<
			"Enter 3 to clear all stack" << '\n' <<
			"Enter 4 to swap max and min values in the stack" << '\n' <<
			"Enter 5 to exit" << '\n' <<
			"Enter 6 to sort the stack" << '\n';
		cin >> opt;
		cout << '\n';
		switch (opt) {
		case 1:
		{
			cout << "Enter the stack size" << endl;
			int size;
			cin >> size;
			for (int i = 0; i < size; i++)
			{
				my_stack = push(my_stack, rand() % 200 - 100);
			}
			break;
		}
		case 2:
		{
			int a;
			my_stack = pop(my_stack, a);
			cout << a << " was ejected" << endl;
			system("pause");
			break;
		}
		case 3:
		{
			deleteAll(&my_stack);
			break;
		}
		case 4:
		{
			system("cls");
			cout << "Old stack:" << endl;
			view(my_stack);
			swapMinMax(my_stack);
			cout << endl << "New stack:" << endl;
			view(my_stack);
			system("pause");
			break;
		}
		case 5:
		{
			deleteAll(&my_stack);
			return 0;
		}
		case 6:
		{
			sortStack(my_stack);
		}
		}
	    system("cls");
	}

}
