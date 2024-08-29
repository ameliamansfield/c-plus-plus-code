#include <iostream>
#include <string>
#include <iomanip>
using  namespace std;
void  bubbleSort(double rainfall[], int SIZE);
int binarySearch(double rainfall[], double x, int low, int high);

int main() {
  const int SIZE = 12;
  string months[SIZE] = {"January", "February", "March", "April", "May", "June" , "July", "August", "September", "October", "November", "December"};
  double rainfall[SIZE];

  for (int i = 0; i < SIZE; i++){
    do {
      cout << "Enter the amount of rainfall in " << months[i] <<       ": ";
      cin >> rainfall[i];
      if (rainfall[i] < 0) {
        cout << "Please enter a non-negative number." << endl;
      }
    } while (rainfall[i] < 0);
  }


  cout << fixed << setprecision(2);
  for (int i = 0; i < SIZE; i++) {
      cout << months[i] << ": " << rainfall[i] << " inches\n";
  }

  double yearlyTotal = 0;
  for (int i = 0; i < SIZE; i++) {
      yearlyTotal += rainfall[i];
  }
  cout << "Yearly total: " << yearlyTotal << " inches\n";

  double averageRainfall = yearlyTotal / SIZE;
  cout << "Average monthly rainfall: " << averageRainfall << " inches\n";

  bubbleSort(rainfall, SIZE);
  cout << "After sorting, the monthly totals are:" << endl;
  for (int i = 0; i < SIZE; i++) 
    cout << rainfall[i] << " ";
  cout << endl;


  double x;
  cout << "Enter the rainfall amount to search for: ";
  cin >> x;
  int n = SIZE;
  int result = binarySearch(rainfall, x, 0, n - 1);
  if (result != -1)
    cout << "Element is found at index " << result <<      " which is " << months[result] << endl;
  else
    cout << "Not found" << endl;

  
  return 0;
}

void  bubbleSort(double rainfall[], int SIZE) {
  double temp; 
  int iteration; 
  int index;

  for (iteration = 1; iteration < SIZE; iteration++) 
  {
    for (index = 0; index < SIZE - iteration; index++) 
    {
     if (rainfall[index] > rainfall[index + 1]) 
      {
       temp = rainfall[index];  
       rainfall[index] = rainfall[index + 1];  
       rainfall[index + 1] = temp; 
      }
    }
  }
}

int binarySearch(double rainfall[], double x, int low, int high) {
     
  while (low <= high) {

    int mid = low + (high - low) / 2;
  
    if (rainfall[mid] == x)
      return mid;

    if (rainfall[mid] < x)
      low = mid + 1;                 
    else                      
      high = mid - 1;    
  }
  return -1;
}




// Write a program that lets the user enter the total rainfall every 12 months into an array of doubles. The program should calculate and display the total rainfall for the year and the average monthly rainfall. Use bubble sort to sort the rainfall from lowest to highest number. Use binary search to search for a specific rain amount. If found, print a message saying that the rain amount was found.

//Input Validation: Do not accept negative numbers for monthly rainfall figures.