
#include <vector>
#include <iostream>
int
main()
{
  std::vector<int> v = { 1, 2, 3, 4 };
  std::cout << *v.rbegin() << std::endl;
  v.push_back(5);
  std::cout << *v.rbegin() << std::endl;
}
