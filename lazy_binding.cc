// Q) Does implicit cast from proxy to table copy the entire table?
// A) No

#include <iostream>
#include <sol.hpp>

int main (int argc, char* argv[]) {
  sol::state lua;
  lua.open_libraries(sol::lib::base);

  lua.script("data = { a = 1, b = 2 }");
  auto proxy = lua["data"];
  sol::table table = lua["data"];

  lua["data"]["a"] = 100;
  std::cout << (int)proxy["a"] << " " << (int)table["a"] << std::endl; // SAME

  return 0;
}
