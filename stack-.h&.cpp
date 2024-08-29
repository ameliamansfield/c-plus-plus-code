.h:

#ifndef INVENTORY_H

#include <iostream>
#include <iomanip>

using namespace std;


class inventory {

private:
 struct item {
    int serialNum;
    int manufactDate;
    int lotNum;
    item *next;
 };

item *top;

public:

//see linkedlist con/decon
  inventory();
  ~inventory();

//bring to .cpp
void push(int serialNum, int manufactDate, int lotNum);
void pop(int &serialNum, int &manufactDate, int &lotNum);
bool isEmpty();

//see linkedlist
void displayinventory();


};

#endif

.cpp:

#include "inventory.h"
#include <iostream>
#include <iomanip>

using namespace std;

inventory::inventory()
{
    top = nullptr;
}

inventory::~inventory()
{
    item* current = top;
    while (current != nullptr)
    {
        item* temp = current;
        current = current->next;
        delete temp;
    }
}
//void push pop and bool
void inventory::push(int serialNum, int manufactDate, int lotNum) {
    item *newitem = new item;
    newitem->serialNum = serialNum;
    newitem->manufactDate = manufactDate;
    newitem->lotNum = lotNum;
    newitem->next = top;
    top = newitem;
}

void inventory::pop(int &serialNum, int &manufactDate, int &lotNum) {
    if (isEmpty()) {
        cout << "The stack is empty, cannot pop." << endl;
        return;
    }
  
    serialNum = top->serialNum;
    manufactDate = top->manufactDate;
    lotNum = top->lotNum;

    item *temp = top;
    top = top->next;
    delete temp;
}

bool inventory::isEmpty() {

  return top == nullptr;

}


void inventory::displayinventory()
{
  item *current = top;
  while (current != nullptr)
  {
    cout << "Item serial number: " << current->serialNum << endl;
    cout << "Item manufacturing date: " << current->manufactDate << endl;
    cout << "Item lot number: " << current->lotNum << endl;
    cout << endl;

    current = current->next;
  }
}

int main()
{

  //we want to both ask not only if they want to start, but also display items and ask if they want to add or remove them, and then display the list of those and ask again (if add else if remove else invalid)
  //need current inventory in brackets
  //need final inventory outside
  
  inventory list;
  char response;
  int serialNum, manufactDate, lotNum;  

  do {
      cout << "Would you like to (a)dd an item or (r)emove an item to the inventory? ";
      char choice;
      cin >> choice;

      if (choice == 'A' || choice == 'a')
      {
          cout << "Enter the item's serial number: ";
          cin >> serialNum;
          cout << "Enter the item's manufacturing date: ";
          cin >> manufactDate;
          cout << "Enter the item's lot number: ";
          cin >> lotNum;

          list.push(serialNum, manufactDate, lotNum);
      }
      else if (choice == 'R' || choice == 'r')
      {
          if (list.isEmpty())
          {
              cout << "The stack is empty, cannot pop." << endl;
          }
          else
          {

              list.pop(serialNum, manufactDate, lotNum);  
            
              cout << "Removed item with: \nSerial number: " << serialNum << "\nManufacturing date: " << manufactDate << "\nLot number: " << lotNum << endl;
          }
      }
      else
      {
          cout << "Invalid choice. Please enter 'A' to add or 'R' to remove an item." << endl;
      }

      cout << "\nCurrent inventory:" << endl;
      list.displayinventory();

      cout << "Are you finished? (Y/N): ";
      cin >> response;

  } while (response == 'N' || response == 'n');

  cout << "\nFinal inventory:" << endl;
  list.displayinventory();

  return 0;
  }
