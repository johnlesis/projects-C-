#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <fstream>

using namespace std;

class employee
{
protected:
  employee(string in_name, string in_surname, int in_pnumber, string in_email, int in_empid); // constructor employee
  friend ostream &operator<<(ostream &left, employee &right);
  string name;    // name
  string surname; // surname
  int pnumber;    // phone number
  string email;   // employee email
  int empid;      // employee ID

public: // functions for employee class
  void menu();
  void addEmp();
  void viewEmp();
  void viewAll();
  void remEmp();

}; // end of class employee

class teacher : public employee
{
private:
  teacher(string in_name, string in_surname, int in_pnumber, string in_email, int in_empid, string in_subject, string in_teachergrade, double in_hourlywage); // contructor teacher
  friend ostream &operator<<(ostream &left, teacher &right);
  string subject;      // class the teacher has
  string teachergrade; // grade of teacher
  double hourlywage;   // hourly wage of teacher

public:
}; // end of class teacher

class administrator : public employee
{
private:
  administrator(string in_name, string in_surname, int in_pnumber, string in_email, int in_empid, string in_edulevel, string in_degree, double in_salary);
  friend ostream &operator<<(ostream &left, administrator &right);
  string edulevel; // education level of administrative worker
  string degree;   // type of degree of administrative worker
  double salary;   // salary of administrative worker

public:
}; // end of class administrator

employee::employee(string in_name, string in_surname, int in_pnumber, string in_email, int in_empid)
{
  name = in_name;
  surname = in_surname;
  pnumber = in_pnumber;
  email = in_email;
  empid = in_empid;
}; // constructor employee initialation

teacher::teacher(string in_name, string in_surname, int in_pnumber, string in_email, int in_empid, string in_subject, string in_teachergrade, double in_hourlywage)
    : employee(in_name, in_surname, in_pnumber, in_email, in_empid)
{
  subject = in_subject;
  teachergrade = in_teachergrade;
  hourlywage = in_hourlywage;
}; // constructor teacher initialation with inherited base class atributes

administrator::administrator(string in_name, string in_surname, int in_pnumber, string in_email, int in_empid, string in_edulevel, string in_degree, double in_salary)
    : employee(in_name, in_surname, in_pnumber, in_email, in_empid)
{
  edulevel = in_edulevel;
  degree = in_degree;
  salary = in_salary;
}; // consrtuctor administrator initialation with inherited base class atributes

// Operators
ostream &operator<<(ostream &left, employee &right)
{
  left << "(" << right.name << "," << right.surname << "," << right.pnumber << right.email << right.empid << ")";

  return left;
};

ostream &operator<<(ostream &left, teacher &right)
{
  left << "(" << right.name << "," << right.surname << "," << right.pnumber << right.email << right.empid << right.subject << right.teachergrade << right.hourlywage << ")";

  return left;
};
ostream &operator<<(ostream &left, administrator &right)
{
  left << "(" << right.name << "," << right.surname << "," << right.pnumber << right.email << right.empid << right.edulevel << right.degree << right.salary << ")";

  return left;
};

void employee::menu() // main menu
{
  system("cls");
m:
  int choice;

  cout << "\t\t\t\t        1) add an employee      \n";
  cout << "\t\t\t\t                                \n";
  cout << "\t\t\t\t        2) view an employee     \n";
  cout << "\t\t\t\t                                \n";
  cout << "\t\t\t\t        3) view all employees   \n";
  cout << "\t\t\t\t                                \n";
  cout << "\t\t\t\t        4) delete an employee   \n";
  cin >> choice;
  switch (choice)
  {
  case 1:
  {
    addEmp();
    break;
  }

  case 2:
  {
    viewEmp();
    break;
  }

  case 3:
  {
    viewAll();
    break;
  }
  case 4:
  {
    remEmp();
    break;
  }

  default:
  {
    cout << "please give a valid selection: ";
    break;
  }
  }
  goto m;
};

void employee::addEmp() // add an employee
{
m:
  system("cls");
  fstream data;
  string n;
  string s;
  int token = 0;
  int p;
  int d;
  string e;

  cout << "\n---------------------" << endl;
  cout << "--- Add an Employee ---" << endl;
  cout << "\n Enter Name of Employee: ";
  cin >> name;
  cout << "\n Enter surname of employee: ";
  cin >> surname;
  cout << "\n Enter phone number of employee: ";
  cin >> pnumber;
  cout << "\n Enter Employee ID: ";
  cin >> empid;
  cout << "\n Enter email of employee: ";
  cin >> email;

  data.open("database.txt", ios::in);
  if (!data)
  {
    data.open("database.txt", ios::app | ios::out);
    data << " " << name << " " << surname << " " << pnumber << " " << empid << " " << email << "\n";
    data.close();
  }
  else
  {
    data >> n >> s >> p >> d >> e;

    while (!data.eof())
    {
      if (n == name)
      {
        token++;
      }
      data >> n >> s >> p >> d >> e;
    }
    data.close();
  }
  if (token == 1)
  {
  }
  else
  {
    data.open("database.txt", ios::app | ios::out);
    data << " " << name << " " << surname << " " << pnumber << " " << empid << " " << email << "\n";
    data.close();
  }
  cout << "data";
  goto m;
};

void employee::viewAll() // Display data of employees
{
  system("cls");
  int total = 1;
  fstream data;
  cout << "\n---------------------------------------------------------------------------------------------" << endl;
  cout << "------------------------------------- Employee Data -------------------------------------------" << endl;
  data.open("database.txt", ios::in);
  if (!data)
  {
    cout << "\n\t\t\tNo Data is Present... ";
    data.close();
  }
  else
  {
    data >> name >> surname >> pnumber >> empid >> email;
    cout << "\n ------------------------------------------------------------------------------------";
    cout << "\n||    NAME    ||    SURNAME    ||    PHONE NUMBER    ||    ID    ||     E-MAIL     ||";
    cout << "\n ------------------------------------------------------------------------------------";
    while (!data.eof())
    {
      cout << "\n";
      cout << total++ << ". " << name << "\t  " << surname << "\t\t  " << pnumber << "\t\t   " << empid << "\t\t  " << email;
      data >> name >> surname >> pnumber >> empid >> email;
    }
  }
  data.close();
};

void employee::viewEmp() // Search an employe
{                        // Displays all details according to Employee's id
  system("cls");
  fstream data;
  int Id;
  cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
  cout << "------------------------------------- Employee Search Data -------------------------------------------" << endl;
  data.open("database.txt", ios::in);
  cout << "\n\nEnter Employee ID: ";
  cin >> Id;
  if (!data)
  {
    cout << "\n\t\t\tNo Data is Present... ";
    data.close();
  }
  else
  {
    data >> name >> surname >> pnumber >> empid >> email;
    while (!data.eof())
    {
      if (empid == Id)
      {
        cout << "\n---------------------\n";
        cout << "Employee Name: " << name << "\n";
        cout << "Employee ID.: " << surname << "\n";
        cout << "Employee Designation: " << pnumber << "\n";
        cout << "Employee Age: " << empid << "\n";
        cout << "Employee CTC: " << email << "\n";
        cout << "------------------------\n";
      }
      data >> name >> surname >> pnumber >> empid >> email;
    }
  }
  data.close();
};

void employee::remEmp() // Delete data of an employee
{
  system("cls");
  int Id;
  fstream data, data1;
  int found = 0;
  cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
  cout << "------------------------------------- Delete Employee Data ------------------------------------------" << endl;
  data.open("Employee_Record.txt", ios::in);
  if (!data)
  {
    cout << "\n\t\t\tNo Data is Present..";
    data.close();
  }
  else
  {
    cout << "\nEnter Employee Id To Remove Data: ";
    cin >> Id;
    data1.open("record.txt", ios::app | ios::out);
    data >> name >> surname >> pnumber >> empid >> email;
    while (!data.eof())
    {
      if (empid == Id)
      {
        data1 << " " << name << " " << surname << " " << pnumber << " " << empid << " " << email << " "
              << "\n";
      }
      else
      {
        found++;
        cout << "\n\t\t\tSuccessfully Delete Data";
      }
      data >> name >> surname >> pnumber >> empid >> email;
    }
    if (found == 0)
    {
      cout << "\n\n\tEmployee ID Not Found.. Please Try Again";
    }
    data1.close();
    data.close();
    remove("database.txt");
    rename("database1.txt", "database.txt");
  }
};

int main() // calling the function in main
{
  void menu();
  return 0;
};