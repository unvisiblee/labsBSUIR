#include <iostream>
#include <ctime>
using namespace std;

struct Queue {
	int info;
	Queue* next;
	Queue* prev;
} *begin, * end, * t;

void create(Queue**, Queue**, int);
void shift(Queue**, int);
void push(Queue**, int);
void view_beg(Queue*);
void view_end(Queue*);
void task(Queue*);

int main()
{
	srand(time(NULL));
	Queue* begin = NULL;
	Queue* end = NULL;
	int opt;
	int opt_view = 1;
	while (true) {

		if (opt_view == 1) {
			view_beg(begin);
		}
		else {
			view_end(end);
		};

		cout << endl << "Enter 1 to fill up the queue with random numbers" << endl <<
			"Enter 2 to swap min and max values" << endl <<
			"Enter 3 to change view mode. Now is ";

		if (opt_view == 1) {
			cout << "from the begining" << endl;
		}
		else {
			cout << "from the end" << endl;
		};

		cout << "Enter 4 to exit" << endl << endl;
		cin >> opt;
		cout << endl;

		switch (opt) {
		case 1:
		{
			int size;
			cout << "Enter the queue size" << endl;
			cin >> size;

			create(&begin, &end, (rand() % 100 - 50 ));
			for (int i = 0; i < size - 1; i++) {
				shift(&begin, (rand() % 100 - 50));
			}
			break;
		}
		case 2:
		{
			system("cls");
			cout << "Old queue" << endl;

			if (opt_view == 1) {
				view_beg(begin);
			}
			else {
				view_end(end);
			}

			cout << endl << "New queue" << endl;
			task(begin);
			if (opt_view == 1) {
				view_beg(begin);
			}
			else if (opt_view == 0) {
				view_end(end);
			}
			system("pause");
			break;
		}
		case 3:
		{
			if (opt_view == 1) {
				opt_view = 0;
			}
			else {
				opt_view = 1;
			}
			break;
		}
		case 4:
		{
			return 0;
		}
		}
		system("cls");
	}
	system("pause");
	return 0;
}

void create(Queue** b, Queue** e, int in) {
	t = new Queue;
	t->info = in;
	t->next = t->prev = NULL;
	*b = *e = t;
}

void shift(Queue **b, int in) {
	t = new Queue;
	t->info = in;
	t->prev = NULL;
	t->next = *b;
	(*b)->prev = t;
	*b = t;
}

void push(Queue** e, int in) {
	t = new Queue;
	t->info = in;
	t->prev = *e;
	t->next = NULL;
	(*e)->next = t;
	*e = t;
}

void view_beg(Queue* p) {
	Queue* t = p;
	while (t != NULL) {
		cout << t->info << endl;
		t = t->next;
	}
}

void view_end(Queue* p) {
	Queue* t = p;
	while (t != NULL)
	{
		cout << t->info << endl;
		t = t->prev;
	}
}

void task(Queue* b) {
	Queue* t = b;
	Queue* min = t;
	Queue* max = t;
    int buff;

	while (t != NULL) {
		if (t->info > max->info) {
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