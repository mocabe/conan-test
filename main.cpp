#include <fmt/format.h>
#include <boost/nowide/iostream.hpp>

int main()
{
  boost::nowide::cout << fmt::format("{}, {}\n", "Hello", "World");
}