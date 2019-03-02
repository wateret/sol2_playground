#include <sol.hpp>

int main (int argc, char* argv[]) {
  sol::state lua;
  lua.open_libraries(sol::lib::base);

  lua.script("print('Hello, world!')");

  return 0;
}
