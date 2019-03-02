// Based on
// https://sol2.readthedocs.io/en/latest/tutorial/cxx-in-lua.html

#include <sol.hpp>

struct player {
 public:
  int bullets;
  int speed;

  player() : player(3, 100) {}
  player(int ammo) : player(ammo, 100) {}
  player(int ammo, int hitpoints) : bullets(ammo), hp(hitpoints) {}

  void boost () { speed += 10; }
  bool shoot () {
    if (bullets < 1)
      return false;
    --bullets;
    return true;
  }
  void set_hp(int value) { hp = value; }
  int get_hp() const { return hp; }

 private:
  int hp;
};

int main (int argc, char* argv[]) {
  sol::state lua;

  lua.open_libraries(sol::lib::base);

  // note that you can set a
  // userdata before you register a usertype,
  // and it will still carry
  // the right metatable if you register it later

  // set a variable "p2" of type "player" with 0 ammo
  lua["p2"] = player(0);

  // make usertype metatable
  lua.new_usertype<player>("player",

      // 3 constructors
      sol::constructors<player(), player(int), player(int, int)>(),

      // typical member function that returns a variable
      "shoot", &player::shoot,
      // typical member function
      "boost", &player::boost,

      // gets or set the value using member variable syntax
      "hp", sol::property(&player::get_hp, &player::set_hp),

      // read and write variable
      "speed", &player::speed,
      // can only read from, not write to
      "bullets", sol::readonly(&player::bullets)
      );

  lua.script_file("usertype.lua");

  return 0;
}
