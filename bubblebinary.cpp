#include <iostream>
#include <iomanip>
using  namespace std;

void  bubbleSort(int account[], int SIZE);
int binarySearch(int account[], int x, int low, int high);

int main() {

  const int SIZE = 18;
  int account[SIZE] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 8080152, 4562555, 5552012, 5050552, 7825877, 1250255, 1005231, 6545231, 3852085, 7576651, 7881200, 4581002};

  bubbleSort(account, SIZE);
  cout << "After sorting, the account numbers are:" << endl;
  for (int i = 0; i < SIZE; i++) 
    cout << account[i] << " \n";
  cout << endl;

  int x;
  cout << "Enter the account number to search for: ";
  cin >> x;
  int n = SIZE;
  int result = binarySearch(account, x, 0, n - 1);
  if (result != -1)
    cout << "This account number is valid, you may proceed with your transaction." << endl;
  else
    cout << "Invalid account number" << endl;

  return 0;
  
}

void  bubbleSort(int account[], int SIZE) {
  double temp; 
  int iteration; 
  int index;

  for (iteration = 1; iteration < SIZE; iteration++) 
  {
    for (index = 0; index < SIZE - iteration; index++) 
    {
     if (account[index] > account[index + 1]) 
      {
       temp = account[index];  
       account[index] = account[index + 1];  
       account[index + 1] = temp; 
      }
    }
  }
}

int binarySearch(int account[], int x, int low, int high) {

  while (low <= high) {

    int mid = low + (high - low) / 2;

    if (account[mid] == x)
      return mid;

    if (account[mid] < x)
      low = mid + 1;                 
    else                      
      high = mid - 1;    
  }
  return -1;
}
