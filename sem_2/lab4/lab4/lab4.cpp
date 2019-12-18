#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

struct Worker {
	string name;
	unsigned int id;
	int hours;
	float hourRate;
	float salary;

	Worker() {};
	~Worker() {};
};

ofstream fout;

void print(vector <Worker>&);
void bblSort(vector <Worker>&);
void qckSort(vector <Worker>&, int, int);
void srch(vector <Worker>&, double);
void binSrch(vector <Worker>&, double);


int main()
{
	setlocale(LC_ALL, "Russian");
	vector <Worker> workers;
	char option;

	while (true)
	{
		cout << "------------------------------------------------------------------------------------------------------" << endl;
		cout << "Фамилия и инициалы | Таб. номер | Часы | Тариф | Зар. плата" << endl;
		cout << "------------------------------------------------------------------------------------------------------" << endl;
		print(workers);
		cout << "------------------------------------------------------------------------------------------------------" << endl;
		cout << endl;
		cout << "Введите 1, чтобы создать запись" << endl << "Введите 2, отсортировать работников по заработной плате"
			<< endl << "Введите 3, чтобы найти работника по заработной плате" << endl << "Введите 4, чтобы выйти" << endl;
		cin >> option;

		switch (option)
		{
		case '1':
		{
			Worker buff;
			cout << "Введите фамилию и инициалы: ";
			SetConsoleCP(1251);
			cin.ignore();
			getline(cin, buff.name);
			SetConsoleCP(866);
			cout << "Введите табельный номер: ";
			cin >> buff.id;
			cout << "Введите количество часов за месяц: ";
			cin >> buff.hours;
			cout << "Введите часовой тариф: ";
			cin >> buff.hourRate;
			if (buff.hours > 144.0)  // hours under 144 get payed in a double rate
				buff.salary = 144.0 * buff.hourRate + (buff.hours - 144.0) * buff.hourRate * 2;
			else
				buff.salary = buff.hourRate * buff.hours;
			workers.push_back(buff);
			break;
		}
		case '2':
		{
			vector <Worker> sort;
			sort = workers;
			cout << "Результат сортировки прямым выбором:" << endl;
			bblSort(sort); // bubble sort
			print(sort);
			sort = workers;
			qckSort(sort, 0, sort.size() - 1); // quicksort
			cout << "Результат QuckSort:" << endl;
			print(sort);
			// workers = sort; !!! uncomment, if needed
			system("pause");
			break;
		}
		case '3':
		{
			vector <Worker> search;
			double key = 0;
			cout << "Введите заработную плату для поиска: ";
			cin >> key;
			cout << endl;
			search = workers;
			srch(search, key); // linear search
			cout << "Результат прямого поиска:" << endl;
			print(search);
			search = workers;
			qckSort(search, 0, search.size() - 1); // sorting the array for binary search
			binSrch(search, key); // binary search
			cout << "Результат двоичного поиска:" << endl;
			print(search);
			system("pause");
			break;
		}
		case '4':
		{
			return 0;
		}
		}

		fout.open("workers.txt", ios_base::trunc);
		for (size_t i = 0; i < workers.size(); i++)
		{
			fout << workers[i].name << " " << workers[i].id << " " << workers[i].hours << " " << workers[i].hourRate << " " <<
				workers[i].salary << endl;
		}
		fout.close();
		system("cls");
	}
	return 0;
}

void print(vector <Worker> &out)
{
	for (size_t i = 0; i < out.size(); i++) {
		cout << out[i].name << "\t \t " << out[i].id << "\t " << out[i].hours << "  \t " << out[i].hourRate << " \t " <<
			out[i].salary << endl;
	}
}

void bblSort(vector <Worker> &srt)
{
	Worker buff;
	for (size_t i = 1; i < srt.size(); i++)
		for (int j = i; j > 0 && srt[j - 1].salary < srt[j].salary; j--) {
			swap(srt[j - 1], srt[j]);
		}
}

//void bblSort(vector <Worker>& srt) // reversed bubble sort (uncomment if needed)
//{
//	Worker buff;
//	for (size_t i = 0; i < srt.size(); i++)
//		for (int j = 0; j < srt.size() - i - 1; j++)
//		{
//			if(srt[j+1].salary < srt[j].salary)
//				swap(srt[j + 1], srt[j]);
//		}
//}

void qckSort(vector <Worker> &srt, int first, int last)
{
	int f = first;
	int l = last;
	Worker bear = srt[(f + l) / 2];

	do {
		while (srt[f].salary > bear.salary) 
			f++;
		while (srt[l].salary < bear.salary)
			l--;
		if (f <= l) {
			swap(srt[f], srt[l]);
			f++;
			l--;
		}
	} while (f < l); 
	if (first < l) qckSort(srt, first, l);
	if (last > f) qckSort(srt, f, last);
}

//void qckSort(vector <Worker>& srt, int first, int last) { // reversed quickSort (uncomment if needed)
//	int f = first;
//	int l = last;
//	Worker bear = srt[(f + l) / 2];
//
//	do {
//		while (srt[f].salary < bear.salary)
//			f++;
//		while (srt[l].salary > bear.salary)
//			l--;
//		if (f <= l) {
//			swap(srt[f], srt[l]);
//			f++;
//			l--;
//		}
//	} while (f < l);
//	if (first < l)
//		qckSort(srt, first, l);
//	if (last > f)
//		qckSort(srt, f, last);
//}

void srch(vector <Worker> &src, double key) {

	for (size_t i = 0; i < src.size(); i++) {

		if (src[i].salary != key) {
			src.erase(src.begin() + i);
			i--;
		}
	}
}

void binSrch(vector <Worker> &srch, double key) {
	vector <Worker> buff;
	int bear;
	int first = 0;
	int last = srch.size();
	int n;

	while (first < last) {
		bear = (first + last) / 2;
		if (srch[bear].salary == key) {
			buff.push_back(srch[bear]);
			for (int n = first; n < bear; n++) {
				if (srch[n].salary == key) {
					buff.push_back(srch[n]);
				}
			}
			for (int n = bear + 1; n < last; n++) {
				if (srch[n].salary == key) {
					buff.push_back(srch[n]);
				}
			}
		}

		if (srch[bear].salary < key) {
			last = bear;
		}
		else {
			first = bear + 1;
		}
	}

	srch.clear();
	srch = buff;
}