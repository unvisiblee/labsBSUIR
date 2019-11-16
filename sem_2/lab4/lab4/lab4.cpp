#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>
using namespace std;


ifstream fin; //object for input
ofstream fout;

struct Worker {
	string name;
	unsigned int id;
	int hours;
	float hourRate;
	float salary;

	void Print_info() {
		cout << "\nFIO      | Tab. nomer | Hours | Chas. tarif | Zar. plata \n" <<
			this->name << '\t' << this->id << '\t' << this->hours << '\t' << '\t' << this->hourRate << '\t' <<
			this->salary << '\n';
	}

	Worker(string name = "NULL", unsigned int id = 0, int hours = 0, float hourRate = 0.0, float salary = 0.0) {
		this->name = name;
		this->id = id;
		this->hours = hours;
		this->hourRate = hourRate;
		if (hours > 144.0)  // hours under 144 get payed in twice rate
			salary = 144.0 * hourRate + (hours - 144.0) * hourRate * 2;
		else
			this->salary = hourRate * hourRate;
	}

	~Worker() { }; // default destructor
};

void printAllInfo(); // function prototypes
void saveAllInfo();
void loadAllInfo();
Worker newWorker();

  vector <Worker> workers; // vector for storing all data

int main() {
	while (true) {

		loadAllInfo();
		int mode;
		cout << "Viberite rezhim raboti: 1) Sozdanie zapisi novogo rabotnika, \n 2) Prosmotr vseh dannih, \n"
			" \n 3) Zarabotnaya plata vseh sotrudnikov \n 4) Vihod . . . " << "5) Ochistit' bazu dannih" << endl;
		cin >> mode;

		switch (mode) {
		case 1:
		{
			Worker newworker = newWorker();
			workers.push_back(newworker);
			saveAllInfo();
			break;
		};
		case 2:
		{
			printAllInfo();
			break;
		};
		case 3:
		{
			break;
		};
		case 4:
		{
			cout << "Vihod . . .";
			return 0;
		};
		case 5:
		{
			fout.open("Database.txt", fstream::trunc); // cleaning the database
			fout.close();
			break;
		};
		}
	}




}

void loadAllInfo() {
	int i = 0;
	Worker buffer;
	fin.open("Database.txt");
	while (fin.read((char*)&buffer, sizeof(Worker))) { // loading all info into array that we will work with
		cout << "Loaded";
		workers.push_back(buffer);
		i++;
	}
	fin.close();
}

void printAllInfo() { // print all current info about students from array
	for (int i = 0; i < workers.size(); i++) {
		workers[i].Print_info();
	}
};

void saveAllInfo() { // save all current info in array into database
	fout.open("Database.txt", fstream::trunc);
	for (int i = 0; i < workers.size(); i++) {
		fout.write((char*)&workers[i], sizeof(Worker));
	}
	cout << "Workers loaded to database" << '\n';
	fout.close();
}

Worker newWorker() {
	string name;
	int id;
	float hours, hourRate;
	cout << "Vvedite familiyu i initsiali rabotnika:" << endl;
	cin >> name;
	cout << "Vvedite tabelniy nomer:" << endl;
	cin >> id;
	cout << "Vvedite chasi za mesyats:" << endl;
	cin >> hours;
	cout << "Vvedite chasovoy tarif:" << endl;
	cin >> hourRate;
	Worker result = Worker(name, id, hours, hourRate);
	return result;
}