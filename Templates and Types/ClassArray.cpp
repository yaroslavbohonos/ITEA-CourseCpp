/* Task in Replit(Compiler) - https://replit.com/@Bgns/Template-class-with-an-array-57#main.cpp

Task:Create a generic class that contains an array of any type and has a method for displaying all elements of such an array on the screen */

#include <iostream>
using namespace std;

template <typename T> class Array
{
private:
  int size;
  T *element;
public:
  Array(int n);

  friend istream& operator>>
    (istream &in, const Array& a)
  {
    cout << "Enter array elements:\n";
    for(int i = 0; i < a.size; i++)
        cin >> a.element[i];
    return in;
  }

  friend ostream& operator<<
      (ostream &out, const Array& a)
  {
    cout << "\nPrinted array: ";
    for(int i = 0; i < a.size; i++)
        cout << a.element[i] << " ";
    return out;
  }
};

template <typename T> Array<T>::Array(int n) 
{
  element = new T[size = n];
}

int main() {
  int size = 10;
  Array<double> A(size);
  cin >> A ;
  cout << A;
}
