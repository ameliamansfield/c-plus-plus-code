#ifndef INVENTORYQUEUE_H
#define INVENTORYQUEUE_H

#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;


class Inventory {

private:

queue<Inventory> queue;
    int serialNum;
    int manufactDate;
    int lotNum;

public:

void enqueue(const Inventory &item);

  Inventory();
  ~Inventory();

//set
void setSerialNum(int s);
void setManufactDate(int d);
void setLotNum(int l);

//get
int getSerialNum() const;
int getManufactDate() const;
int getLotNum() const;

//see linkedlist
void display() const;

};

class InventoryQueue {
private:
    queue<Inventory> queue; 

public:
  
    void enqueue(const Inventory &item);
    Inventory dequeue();
    bool isEmpty() const;
    void displayAll() const;
};

#endif

