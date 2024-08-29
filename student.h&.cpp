student.h:

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

struct Student
{
    std::string name;
    int idnum;
    int* tests;
    double average;
    char grade;
    Student* link;
};

class StudentList
{
private:
    Student* first;
    Student* last;

public:
    StudentList();
    ~StudentList();

    void addStudent();
    void displayStudents();
    void increaseAverage(int id);
};

#endif

 

student.cpp:

#include "student.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

StudentList::StudentList()
{
    first = nullptr;
    last = nullptr;
}

StudentList::~StudentList()
{
    Student* current = first;
    while (current != nullptr)
    {
        Student* temp = current;
        current = current->link;
        delete[] temp->tests;
        delete temp;
    }
}

void StudentList::addStudent()
{
  Student *newStudent = new Student;

  cout << "Enter the student's name: ";
  cin.ignore();
  getline(cin, newStudent->name);
  
  cout << "Enter the student's ID number: ";
  cin >> newStudent->idnum;

  int numTests;
  cout << "Enter the number of test scores: ";
  cin >> numTests;

  newStudent->tests = new int[numTests];
  for (int i = 0; i < numTests; i++)
  {
    cout << "Enter test score " << i + 1 << ": ";
    cin >> newStudent->tests[i];
    while (newStudent->tests[i] < 0)
    {
      cout << "Invalid. Enter a non-negative number: ";
      cin >> newStudent->tests[i];
    }
  }

  int sum = 0;
  for (int i = 0; i < numTests; i++)
  {
    sum += newStudent->tests[i];
  }
  newStudent->average = sum / numTests;

  if (newStudent->average >= 91)
    {
      newStudent->grade = 'A';
    }
    else if (newStudent->average >= 81 && newStudent->average <= 90)
    {
      newStudent->grade = 'B';
    }
    else if (newStudent->average >= 71 && newStudent->average <= 80)
    {
      newStudent->grade = 'C';
    }
    else if (newStudent->average >= 61 && newStudent->average <= 70)
    {
      newStudent->grade = 'D';
    }
    else
    {
      newStudent->grade = 'F';
    }

  newStudent->link = nullptr;

    if (first == nullptr)
    {
      first = newStudent;
      last = newStudent;
    }
    else
    {
      last->link = newStudent;
      last = newStudent;
    }
  }


void StudentList::displayStudents()
{
  Student *current = first;
  while (current != nullptr)
  {
    cout << "Student name: " << current->name << endl;
    cout << "Student ID number: " << current->idnum << endl;
    cout << "Average test score: " << fixed << setprecision(2) << current->average << endl;
    cout << "Course grade: " << current->grade << endl;
    cout << endl;

    current = current->link;
  }
}

 void StudentList::increaseAverage(int id)
  {
    Student *current = first;
    while (current != nullptr)
    {
      if (current->idnum == id)
      {
        current->average += 10;
        if (current->average >= 91)
        {
          current->grade = 'A';
        }
        else if (current->average >= 81 && current->average <= 90)
        {
          current->grade = 'B';
        }
        else if (current->average >= 71 && current->average <= 80)
        {
          current->grade = 'C';
        }
        else if (current->average >= 61 && current->average <= 70)
        {
          current->grade = 'D';
        }
        else
        {
          current->grade = 'F';
        }
        break;
      }
      current = current->link;
    }
  };

int main()
{
  StudentList list;
  char response;

  cout << "Do you want to start? (Y/N): ";
  cin >> response;
  while (response == 'Y' || response == 'y')
  {
    list.addStudent();

    cout << "Do you want to add another student? (Y/N): ";
    cin >> response;
  }

  list.displayStudents();

  int id;
  cout << "Enter a student ID number to potentially increase their average: ";
  cin >> id;
  list.increaseAverage(id);

  list.displayStudents();

  
  return 0;

  }

 
