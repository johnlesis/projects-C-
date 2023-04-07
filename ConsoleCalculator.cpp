#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
  char op;
  double num1;
  double num2;
  double result;

  cout << "****** CALCULATOR ******" << endl;
  cout << "Enter either (+ - * /): ";
  cin >> op;

  cout << "Enter #1; ";
  cin >> num1;

  cout << "Enter #2; ";
  cin >> num2;

  switch (op)
  {
  case '+':
    result = num1 + num2;
    cout << "result: " << result << endl;
    break;

  case '-':
    result = num1 - num2;
    cout << "result; " << result << endl;
    break;

  case '*':
    result = num1 * num2;
    cout << "result; " << result << endl;
    break;

  case '/':
    result = num1 / num2;
    cout << "result; " << result << endl;
    break;

  default:
    cout << "that wasn't a valid response" << endl;
    break;
  }

  cout << "**************************";

  return 0;
};
