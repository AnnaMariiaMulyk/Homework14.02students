#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
#include <list>
using namespace std;

/*struct date {
	int day;
	string month;
	int year;
};

struct phone {
	string phoneNumber;
	string brand;
	string model;
	string color;
	date dateCreate;
};

	list<phone> phoneBook;

	void createNewPhone() {
		phone newPhone;
		cout << "Enter phone number: ";
		cin >> newPhone.phoneNumber;

		cout << "Enter phone brand: ";
		cin >> newPhone.brand;

		cout << "Enter phone model: ";
		cin >> newPhone.phoneNumber;

		cout << "Enter phone color: ";
		cin >> newPhone.color;
		phoneBook.push_back(newPhone);

	}

	void showPhones() {
		for (phone item : phoneBook)
		{
			cout << "Phone number: " << item.phoneNumber << endl;
			cout << "Phone brand: " << item.brand << endl;
			cout << "Phone model: " << item.model << endl;
			cout << "Phone color: " << item.color << endl;

		}
	}*/

struct student
{
	string fullname;
	int age;
	string email;
	string phoneNumber;
	string address;
	list<int> marks;
};

list<student> listStudents;

void showStudents()
{
	cout << "\tSHOW STUDENT" << endl;
	for (student item : listStudents)
	{
		cout << item.fullname << endl;
		cout << item.age << endl;
		cout << item.email << endl;
		cout << item.phoneNumber << endl;
		cout << item.address << endl;
		for (int itemM : item.marks)
		{
			cout << itemM << endl;
		}
	}
}
void addStudent()
{
	student newStudent;
	cout << "\tADD STUDENT" << endl;
	cout << endl;

	cout << "Enter full name: ";
	cin.ignore();
	getline(cin, newStudent.fullname);
	cout << "Enter age: ";
	cin >> newStudent.age;
	cout << "Enter email: ";
	cin >> newStudent.email;
	cout << "Enter phone number: ";
	cin >> newStudent.phoneNumber;
	cout << "Enter count of marks: ";
	int a;
	cin >> a;
	cout << "Enter marks: ";
	for (int i = 0; i < a; i++)
	{
		int temp;
		cin >> temp;
		newStudent.marks.push_back(temp);
	}


	listStudents.push_back(newStudent);
}
void exellentSudent()
{
	float arythmeticMean = 0;
	int count;
	cout << "\tEXELLENT STUDENTS" << endl;
	list<student> exellentStudents;
	for (student item : listStudents)
	{
		arythmeticMean = 0;
		count = 0;
		for (int iteM : item.marks)
		{
			arythmeticMean += iteM;
			count++;
		}
		if (count >= 1)
		{
			arythmeticMean = arythmeticMean / count;
		}
		if (arythmeticMean >= 9)
		{
			exellentStudents.push_back(item);
		}
	}
	for (student item : exellentStudents)
	{
		cout << item.fullname << endl;
		for (int itemM : item.marks)
		{
			cout << itemM << endl;
		}
	}
	
}
void addMarks()
{
	cout << "\tADD MARKS" << endl;
	string tempName = "";
	cout << "Enter sudent`s name: ";
	cin.ignore();
	getline(cin, tempName);
	for (student item : listStudents)
	{
		if (tempName == item.fullname)
		{
			int a;
			int temp;
			cout << "Enter count of marks: ";
			cin >> a;
			cout << "Enter mark: ";
			for (int i = 0; i < a; i++)
			{
				cin >> temp;
				item.marks.push_back(temp); //не пушить (T ^ T)
			}
		}
	}
	
}
int main()
{
	/*date dc = { 12, "September", 2017 };
	phone myPhone = { "+380960621486",
		"Apple",
		"iPhone X",
		"space gray"
	};

	const int size = 10;
	int numbers[size];
	phone contactBook[size];

	cout << myPhone.phoneNumber << endl;
	cout << myPhone.brand << endl;
	cout << myPhone.model << endl;
	cout << myPhone.color << endl;

	list<int> listNumbers = {1, 1, 1, 1, 1};
	listNumbers.push_back(23);

	for (int item: listNumbers) {
		cout << item << endl;
	}


	createNewPhone();
	createNewPhone();
	createNewPhone();

	showPhones();*/


	int choiseMenu;

	do {
		cout << "\tMENU" << endl;
		cout << "1. Show students" << endl;
		cout << "2. Add student" << endl;
		cout << "3. Show excellent students" << endl;
		cout << "4. Add marks" << endl;
		cout << "5. Exit" << endl;
		cout << endl;
		cout << "Enter action: ";
		cin >> choiseMenu;

		switch (choiseMenu)
		{
		case 1:

			showStudents();
			break;
		case 2:

			addStudent();
			break;
		case 3:
			exellentSudent();
			break;
		case 4:
			addMarks();
			break;
		case 5:
			cout << "Goodbye!" << endl;
			break;
		default:
			break;
		}

	} while (choiseMenu != 5);

	system("pause");
	return 0;
}