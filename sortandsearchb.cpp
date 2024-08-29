#include <iostream>
#include <string>
#include <iomanip>
using  namespace std;
void printArray(double rainfall[], int SIZE);
void selectionSort(double rainfall[], int SIZE); 
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

   
    selectionSort(rainfall, SIZE);
    cout << "Sorted rainfall/month in Acsending Order:\n";
for (int i = 0; i < SIZE; i++) {
  cout << rainfall[i] << " ";
}
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

void printArray(double rainfall[], int SIZE) 
{
  for (int i = 0; i < SIZE; i++) 
    cout << rainfall[i] << " ";
  cout << endl;
}

void selectionSort(double rainfall[], int SIZE) 
{
  for (int step = 0; step < SIZE - 1; step++) 
  {
    int min_idx = step; 
    for (int i = step + 1; i < SIZE; i++) 
    {
      
      if (rainfall[i] < rainfall[min_idx]) 
        min_idx = i;
    }

    int temp = rainfall[min_idx]; 
    rainfall[min_idx] = rainfall[step]; 
    rainfall[step] = temp;
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




//Write a program that lets the user enter the total rainfall every 12 months into an array of doubles. The program should calculate and display the total rainfall for the year and the average monthly rainfall. Use selection sort to sort the rainfall from the lowest to the highest number. Use binary search to search for a specific rain amount. If found, print a message saying that the rain amount was found.

//Input Validation: Do not accept negative numbers for monthly rainfall figures.