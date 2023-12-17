#include <iostream>
#include <stdexcept>
#include <string>

//Sum the integers from 1 to n. For example, if n is 5, then sigma returns the sum 1 + 2 + 3 + 4 + 5 == 15.
//@param n integer upper bound of summation
//@pre n >= 1
//@post return value is the sum of the integers from 1 to n.
//@return sum of the integers from 1 to n, where n is specified as an argument or 0 if an error occurred.

unsigned long sigma(unsigned long n)
{
  unsigned long sum = 0;

  try
    {
      if (n < 1)
      {
        std::string strMessage = "Precondition n>=1 violated; invalid value for argument n: " + std::to_string(n) + "(Loc: " + __FILE__ + ", " + std::to_string(__LINE__) + ")";
        throw std::invalid_argument(strMessage);
      }
      for (int i = 1; i <= n; ++i) 
      {
          sum += i;
      }
      if (sum != (n*(n+1)/2))
      {
        std::string strMessage = "Postcondition sum == (n(n+1))/2 violated: sum: " + std::to_string(sum) + "; n(n+1)/2: " + std::to_string((n * (n + 1)) / 2) + "(Loc: " + __FILE__ + ", " + std::to_string(__LINE__) + ")";;
        throw std::runtime_error(strMessage);
      }
    }
    catch (std::runtime_error & ex)
    {
      std::cout << "Exception: " << ex.what() << std::endl;
      std::cout << "Cannot compute sum, returning 0" << std::endl;
      sum = 0;
    }
  return sum;  
}

int main() {
    int sum = sigma(5);
  std::cout << "sigma(5) = " << sum << std::endl;
    sum = sigma(0);
  std::cout << "sigma(0) = " << sum << std::endl;


    return 0; 
}