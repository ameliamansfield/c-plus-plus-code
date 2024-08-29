#include "inventoryqueue.h"

using namespace std;

Inventory::Inventory() : serialNum(0), manufactDate(0), lotNum(0) {}

Inventory::~Inventory() {}

//set
void Inventory::setSerialNum(int s) {
  serialNum = s;
}

void Inventory::setManufactDate(int d) {
  manufactDate = d;
}

void Inventory::setLotNum(int l) {
  lotNum = l;
}

//get
int Inventory::getSerialNum() const {
  return serialNum;
}

int Inventory::getManufactDate() const {
  return manufactDate;
}

int Inventory::getLotNum() const {
  return lotNum;
}

void Inventory::display() const {
    std::cout << "Serial Number: " << serialNum << "\n";
    std::cout << "Manufacture Date: " << manufactDate << "\n";
    std::cout << "Lot Number: " << lotNum << "\n";
}

void InventoryQueue::enqueue(const Inventory &item) {
  queue.push(item);
}

Inventory InventoryQueue::dequeue() {
  Inventory item = queue.front();
  queue.pop();
  return item;
}

bool InventoryQueue::isEmpty() const {
  return queue.empty();
}

void InventoryQueue::displayAll() const {
  std::queue<Inventory> tempQueue = queue;
  while (!tempQueue.empty()) {
      tempQueue.front().display();
      tempQueue.pop();
  }
}

int main() {
  InventoryQueue inventoryQueue;
  char response;

  do {
    cout << "Would you like to (a)dd an item or (r)emove an item to the inventory? ";
    char choice;
    cin >> choice;

    if (choice == 'A' || choice == 'a')
    {
      Inventory item;
      int serialNum, lotNum, manufactDate;
      
        cout << "Enter the item's serial number: ";
        cin >> serialNum;
        item.setSerialNum(serialNum);
      
        cout << "Enter the item's manufacturing date: ";
        cin >> manufactDate;
        item.setManufactDate(manufactDate);
      
        cout << "Enter the item's lot number: ";
        cin >> lotNum;
        item.setLotNum(lotNum);

        inventoryQueue.enqueue(item);
    }
    else if (choice == 'R' || choice == 'r')
    {
      if (!inventoryQueue.isEmpty()) {
              Inventory item = inventoryQueue.dequeue();
        cout << "Item removed from the inventory. Current inventory:\n";
              item.display();
          } else {
              cout << "Inventory is empty.\n";
          }
      }
    else
    {
        cout << "Invalid choice. Please enter 'A' to add or 'R' to remove an item." << endl;
    }

      cout << "Remaining items in inventory:\n";
      inventoryQueue.displayAll();


    cout << "Are you finished? (Y/N): ";
    cin >> response;

  } while (response == 'N' || response == 'n');

  cout << "\nFinal inventory:" << endl;
  inventoryQueue.displayAll();


  return 0;
  }


