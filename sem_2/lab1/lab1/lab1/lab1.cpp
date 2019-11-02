#include <iostream> // Does not work on UNIX( at lest Arch linux ) systems, something with memory...
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

ifstream fin; //object for input
ofstream fout; // object for output
struct Student {   // struct for each student
	string name;
	int birthYear, group;
	int phys, math, inf, chem;
	double sball;

	~Student() {   // default destructor
	};


	Student(string name = "NULL", int birthYear = 0, int group = 0, int phys = 0, int math = 0, int inf = 0, int chem = 0) { // constructor
		this->name = name;
		this->birthYear = birthYear;
		this->group = group;
		this->phys = phys;
		this->math = math;
		this->inf = inf;
		this->chem = chem;
		this->sball = (phys + math + inf + chem) / 4.0;
	}

	void Print_info() {  // output of all information
		cout << "\nFIO      | God rozhdenia | Gruppa | Fizika | Matem | Inf-ka | Chimiya | Sr.ball \n" <<
			this->name << '\t' << this->birthYear << '\t' << this->group << '\t' << '\t' << this->phys << '\t' <<
			this->math << '\t' << this->inf << '\t' << this->chem << '\t' << this->sball << '\n';
	}

};

const unsigned int ARRSIZE = 150; // array for keeping all students
Student students[ARRSIZE];

void printAllInfo(); // function prototypes
void saveAllInfo();
void printBySurname(string Surname);
Student newStudent();


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int i = 0;
	fin.open("Database.txt");
	while (fin.read((char*)&students[i], sizeof(Student))) { // loading all info into array that we will work with
		i++;
	}
	fin.close();


	int mode;

	cout << "Viberite rezhim raboti: 1) Sozdanie zapisi novogo studenta, \n 2) Prosmotr dannih studenta, \n"
		" 3) Korrektsia, \n 4) Personal'noye zadanie \n 5) Vihod . . . " << "6) Ochistit' bazu dannih" << endl;
	cin >> mode;

	switch (mode) { // creating a new student
	case 1:
	{
		Student newstudent;
		newstudent = newStudent();
		newstudent.Print_info();
		fout.open("Database.txt", fstream::app);
		fout.write((char*)&newstudent, sizeof(Student)); // saving his data in the database
		fout.close();
		break;
	};
	case 2: // printing info about students
	{
		cout << "Viberite rezhim prosmotra: 1) Po familii, \n 2) Vse studenti";
		int secmode;
		cin >> secmode;
		if (secmode == 1) { // by surname
			cout << "Vvedite familiyu: ";
			string surname;
			cin >> surname;
			printBySurname(surname);
		}
		else if (secmode == 2) { // print all data in the database
			printAllInfo();
		}
		break;
	};
	case 3: // changing info about existing student
	{
		cout << "Vvedite familiyu studenta, informatsiu kotorogo vi hotite izmenit': ";
		string surname1;
		cin >> surname1;
		for (int num = 0; num < ARRSIZE; num++) {
			if (students[num].name.find(surname1) == 0) { // searching for surname in the array
				cout << "Vi izmenite dannie etogo studenta: \n"; 
				students[num].Print_info(); // printing current data about the student
				students[num] = newStudent();
				students[num].Print_info(); // replacing student data with the new data
			}
		}
		saveAllInfo(); // saving this data in the database
		break;
	};
	case 4: // search by group and pring students whos surname begin with 'D', 'V' or 'G'
	{
		int group;
		cout << "Vvedite gruppu dlya poiska: ";
		cin >> group;
		for (int i = 0; i < ARRSIZE; i++) {
			if (students[i].group = group && (students[i].name[0] == 'Д' || students[i].name[0] == 'В' || students[i].name[0] == 'Г') ) {
				students[i].Print_info();
			}
		}
		break;
	};
	case 5:
	{
		cout << "Vihod . . .";
		break;
	};
	case 6:
	{
		fout.open("Database.txt", fstream::trunc); // cleaning the database
		fout.close();
	}

	}
}

void printAllInfo() { // print all current info about students from array
	for (int i = 0; i < ARRSIZE; i++) {
		if (students[i].name == "NULL") {
			break;
		};
		students[i].Print_info();
	}
};

void saveAllInfo() { // save all current info in array into database
	fout.open("Database.txt", fstream::trunc);
	for (int i = 0; i < ARRSIZE; i++) {
		if (students[i].name == "NULL") {
			cout << i << " Students loaded into a database.";
			break;
		}
		fout.write((char*)&students[i], sizeof(Student));
	}
	fout.close();
}

void printBySurname(string surname) { // Searching students by surname and printing all info about them

	for (int i = 0; i < ARRSIZE; i++) {
		if (students[i].name.find(surname) == 0) {
			students[i].Print_info();
		}
	}
}

Student newStudent() { // function for creating a new student, using data from the keyboard
	string name;
	int birthYear, group, phys, math, inf, chem;
	cout << "Vvedite familiyu i initsiali studenta:" << endl;
	cin >> name;
	cout << "Vvedite god rozhdeniya:" << endl;
	cin >> birthYear;
	cout << "Vvedite gruppu:" << endl;
	cin >> group;
	cout << "Vvedite otsenku po fizike:" << endl;
	cin >> phys;
	cout << "Vvedite otsenku po matematike:" << endl;
	cin >> math;
	cout << "Vvedite otsenku po informatike:" << endl;
	cin >> inf;
	cout << "Vvedite otsenku po himii:" << endl;
	cin >> chem;
	Student result = Student(name, birthYear, group, phys, math, inf, chem);
	return result;
}

// Written by Vladimir Dragun. November, 2019.


