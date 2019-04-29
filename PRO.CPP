#include<iostream.h>
#include<fstream.h>
#include<stdlib.h>
#include<conio.h>
#include<iomanip.h>
#include<string.h>
#include<stdio.h>
#include<dos.h>
#include<graphics.h>
const char* fileName = "Employee.txt";

class Employee
{
private:
	int EmpID;
	char EmpName[50], Post[50], Department[10];
	float Salary;
public:
	void ReadData();
	int GetID();
	void DisplayRecord();
	char* GetDepartment();
};

void Employee::ReadData()
{
	cout << endl << "Employee ID:";
	cin >> EmpID;
	cout << "Employee Name:";
	cin >> EmpName;
	cout << "Employee's Post:";
	cin >> Post;
	cout << "Employee's Department:";
	cin >> Department;
	cout << "Salary:";
	cin >> Salary;
}

void Employee::DisplayRecord()
{
	cout << endl << "_______________________________";
	cout << endl << setw(5) << EmpID << setw(15) << EmpName << setw(15) << Post << setw(15) << Department << setw(8) << Salary;
}

int Employee::GetID()
{
	return EmpID;
}

char* Employee::GetDepartment()
{
	return Department;
}

int main()
{
clrscr();
	int choice;
	void asd();
	void qwe();
	int gdriver = DETECT, gmode;
	initgraph(&gdriver,&gmode, "c:\\TURBOC3\\BGI");
	setbkcolor(CYAN);
line(15,10,622,10);
line(15,10,15,466);
line(15,466,622,466);
line(622,466,622,10);
line(25,20,611,20);
line(25,20,25,455);
line(25,455,611,455);
line(611,455,611,20);
settextstyle(5,0,3);
gotoxy(50,200);
outtextxy(60,100,"<<<<<<<<employee management system>>>>>>>>");
       gotoxy(10,15);
	cout<<"\tENTER 1: TO GO TO THE EMPLOYEE SECTION\n\n";
	gotoxy(10,17) ;
	cout<<"\tENTER 2: TO GO TO THE ADMINISTRATOR SECTION\n\n";
	gotoxy(10,19);
	cout<<"	ENTER YOUR CHOICE";
	gotoxy(35,19);

	cin>>choice;
	switch(choice)
	{
	case 1:
	qwe();
	break;
	case 2:
	asd();
	break;
	default:
	cout<<"can't understand that";
	}

  getch();
}

void qwe()
{
clrscr();
	Employee emp, e;
	char ch, Dept[50];
	int option,ID, isFound;
	system("cls");
	     int login();
		system("cls");
	     setbkcolor(CYAN);
			fstream file;
	file.open(fileName, ios::ate | ios::in | ios::out | ios::binary);

		isFound = 0;
		cout << endl << "Enter ID of an employee to be searched:";
		cin >> ID;
		login();
		setbkcolor(CYAN);
		file.seekg(0, ios::beg);
		file.read((char*)&e, sizeof(e));
		while (!file.eof())
		{
			if (e.GetID() == ID)
			{
				cout << endl << "The record found...." << endl;
				cout << endl << setw(5) << "ID" << setw(15) << "Name" << setw(15) << "Post" << setw(15) << "Department" << setw(8) << "Salary";
				e.DisplayRecord();
				isFound = 1;
				break;
			}
			file.read((char*)&e, sizeof(e));
		}
		file.clear();
		if (isFound == 0)
			cout << endl << "Data not found for employee ID#" << ID;



}
void asd()
{
 clrscr();
	Employee emp, e;
	char ch, Dept[50];
	int option,ID, isFound;
	int login();
	login();
	setbkcolor(CYAN);
	fstream file;
	file.open(fileName, ios::ate | ios::in | ios::out | ios::binary);
	do
	{
		cout << "\n\n\n\t\t*******Menu********\n";
		cout << endl << "\t\tEnter your option\n";
		cout << endl << "\t\t1 => Add a new record\n";
		cout << endl << "\t\t2 => Search record from employee id\n";
		cout << endl << "\t\t3 => List Employee of particular department\n";
		cout << endl << "\t\t4 => Display all employee\n";
		cout << endl << "\t\t5 => Update record of an employee\n";
		cout << endl << "\t\t6 => Delete record of particular employee\n";
		cout << endl << "\t\t7 => Exit from the program\n" << endl;
		cout << "\t\t********************\n" << endl;

		cin >> option;
		switch (option)
		{
		case 1:
		{

		system("cls");
		setbkcolor(CYAN);
		emp.ReadData();
		file.seekg(0, ios::beg);
		isFound = 0;
		file.read((char*)&e, sizeof(e));
		while (!file.eof())
		{
			if (e.GetID() == emp.GetID())
			{
				cout << "This ID already exist...Try for another ID";
				isFound = 1;
				break;
			}
			file.read((char*)&e, sizeof(e));
		}
		if (isFound == 1)
			break;
		file.clear();
		file.seekp(0, ios::end);
		file.write((char*)&emp, sizeof(emp));
		cout << endl << "New record has been added successfully...";
		break;
		}
		case 2:
		{

		system("cls");
		setbkcolor(CYAN);
			isFound = 0;
		cout << endl << "Enter ID of an employee to be searched:";
		cin >> ID;
		file.seekg(0, ios::beg);
		file.read((char*)&e, sizeof(e));
		while (!file.eof())
		{
			if (e.GetID() == ID)
			{
				cout << endl << "The record found...." << endl;
				cout << endl << setw(5) << "ID" << setw(15) << "Name" << setw(15) << "Post" << setw(15) << "Department" << setw(8) << "Salary";
				e.DisplayRecord();
				isFound = 1;
				break;
			}
			file.read((char*)&e, sizeof(e));
		}
		file.clear();
		if (isFound == 0)
			cout << endl << "Data not found for employee ID#" << ID;
		break; }
		case 3:

		system("cls");
		setbkcolor(CYAN);
		{	isFound = 0;
		cout << "Enter department name to list employee within it:";
		cin >> Dept;
		file.seekg(0, ios::beg);
		file.read((char*)&e, sizeof(e));
		while (!file.eof())
		{
			if (strcmp(e.GetDepartment(), Dept) == 0)
			{
				cout << endl << "The record found for this department" << endl;

				cout << endl << setw(5) << "ID" << setw(15) << "Name" << setw(15) << "Post" << setw(15) << "Department" << setw(8) << "Salary";
				e.DisplayRecord();
				isFound = 1;
				break;
			}
			file.read((char*)&e, sizeof(e));
		}
		file.clear();
		if (isFound == 0)
			cout << endl << "Data not found for department" << Dept;
		break;
		}
		case 4:
		system("cls");
		setbkcolor(CYAN);
		{	cout << endl << "Record for employee";
		file.clear();
		file.seekg(0, ios::beg);
		int counter = 0;
		file.read((char*)&e, sizeof(e));
		while (!file.eof())
		{
			counter++;
			if (counter == 1)
			{
				cout << endl << setw(5) << "ID" << setw(15) << "Name" << setw(15) << "Post" << setw(15) << "Department" << setw(8) << "Salary";
			}
			e.DisplayRecord();
			file.read((char*)&e, sizeof(e));
		}
		cout << endl << counter << "records found......";
		file.clear();
		break;
		}
		case 5:
		{

		system("cls");
		setbkcolor(CYAN);
			int recordNo = 0;
		cout << endl << "File is being modified....";
		cout << endl << "Enter employee ID to be updated:";
		cin >> ID;
		isFound = 0;
		file.seekg(0, ios::beg);
		file.read((char*)&e, sizeof(e));
		while (!file.eof())
		{
			recordNo++;
			if (e.GetID() == ID)
			{
				cout << "The old record of employee having ID" << ID << "is:";
				e.DisplayRecord();
				isFound = 1;
				break;
			}
			file.read((char*)&e, sizeof(e));
		}

		if (isFound == 0)
		{
			cout << endl << "Data not found for employee ID#" << ID;
			break;
		}
		file.clear();
		int location = (recordNo - 1) * sizeof(e);
		file.seekp(location, ios::beg);
		cout << endl << "Enter new record for employee having ID" << ID;
		e.ReadData();
		file.write((char*)&e, sizeof(e));
		break;
		}
		case 6:
		{

		system("cls");
		setbkcolor(CYAN);
			int recordNo = 0;//Fix Needed?
		cout << endl << "Enter employment ID to be deleted:";
		cin >> ID;
		isFound = 0;
		file.seekg(0, ios::beg);
		file.read((char*)&e, sizeof(e));
		while (!file.eof())
		{
			recordNo++;//Fix Needed?
			if (e.GetID() == ID)
			{
				cout << " The old record of employee having ID " << ID << " is: ";
				e.DisplayRecord();
				isFound = 1;
				break;
			}
			file.read((char*)&e, sizeof(e));
		}
		char tempFile[] = "temp.txt";
		fstream temp(tempFile, ios::out | ios::binary);
		if (isFound == 0)
		{
			cout << endl << "Data not found for employee ID#" << ID;
			break;
		}
		else
		{
			file.clear();
			file.seekg(0, ios::beg);
			file.read((char*)&e, sizeof(e));
			while (!file.eof())
			{
				if (e.GetID() != ID)
					temp.write((char*)&e, sizeof(e));
				file.read((char*)&e, sizeof(e));
			}
			file.close();
			temp.close();
			temp.open(tempFile, ios::in | ios::binary);
			file.open(fileName, ios::out | ios::binary);
			temp.read((char*)&e, sizeof(e));
			while (!temp.eof())
			{
				file.write((char*)&e, sizeof(e));
				temp.read((char*)&e, sizeof(e));
			}
		}
		temp.close();
		file.close();
		remove(tempFile);
		file.open(fileName, ios::ate | ios::in | ios::out | ios::binary);
		break; }

		case 7:
		{
		cout<<"thank u for visitng!!!!!\n" ;
		cout<<"press any key to exit......";

		exit(0);
		break;
		}
		default:
			cout << "Invalid Options";
		}
		cout << "\nDo you want to continue.....?y/n";
		cin >> ch;
	clrscr();
	} while (ch != 'n');
}
int login()
{
   void pass();
   char ch;
   system("cls") ;
   setbkcolor(CYAN);

   gotoxy(70,50);
   cout <<"\n\n\n\n\t\tEMPLOYEE MANAGEMENT SYSTEM";
   cout <<"\n\n\t\tEnter Your Password :";
   pass();


 return 1;
}
void pass()
  {
    int i,x;
    char ch='/0',password[]="password",match[20];
    for(i=0;i>=0;)
     {
       ch=getch();

      if(ch!=8&&ch!=13)
	{
	 cout<<"*";
	 match[i]=ch;
	 i++;
	}
      else if (ch==8) // if backspace is presssed
       {
	 cout<<"\b \b"; // moves cursor to the left print <space> again move cursor to left
	 i--;
       }
      else if(ch==13)
    {
	 match[i]='\0'; // if enter is pressed, last character in match[] becomes null
	break;         // for end of string
    }
    else
    {
	 break;
    }
  }
  if(strcmp(match,password)==0)// comparing two strings.. if equal returns 0
  {

  cout<<"\n\n\n\t\tLOADING \n\t\t";
	for(int a=1;a<8;a++)
	{
		delay(500);
		cout << "...";
	}
      cout << "\n\n\n\t\tAccess Granted!! \n\n\n";

      system("PAUSE");
      system("CLS");

   }else{
      cout << "\n\t\tAccess Aborted...\n";
      login();

   }
}

