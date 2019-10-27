#include <iostream>
#include <vector>
#include <string>

int main ()
{
  std::vector<std::string> myvector;

  myvector.emplace("foo");
  myvector.emplace("bar");
  auto ret = myvector.emplace("foo");

  if (!ret.second) std::cout << "foo already exists in myvector\n";

  return 0;
}
