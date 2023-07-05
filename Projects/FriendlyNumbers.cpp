/* Task in Replit(Compiler) - https://replit.com/@Bgns/Friendly-numbers-or-93#main.cpp

The code checks for friendly numbers in the range from 4 to 1024. Friendly numbers are pairs of numbers 
where the sum of the proper divisors of one number is equal to the other number, and vice versa.*/

#include <iostream>
using namespace std;
typedef long long ll;
 
int sumOfDivisors(int n)
{
  int sum = 0;
  for(int i=1; i<=n/2; i++)
  {
    if(n%i==0) 
      sum+=i;
  }
  return sum;
}

int main() {
  double start = clock() * 1.0 / CLOCKS_PER_SEC;
  int n=88730;
  short int amount = 0;
  for(int i=220; i<=n; i+=2) // 220 - because friend numbers starts from 220
  {
    int sum1 = sumOfDivisors(i);
    if(sum1 > i && sum1 <= n)
    {
      int sum2=sumOfDivisors(sum1);
      if(sum2 == i)
      {
        cout << i << " and " << sum1 << " are friendly numbers\n";
        amount++;
      }
    }
  }
  double end = clock() * 1.0 / CLOCKS_PER_SEC;
  cout << "Amount of pairs from friendly numbers between 4 and 88730 is " << amount ;
  cout << "\nTooks: "<< end - start << " sec." << endl;
  return 0;
}
