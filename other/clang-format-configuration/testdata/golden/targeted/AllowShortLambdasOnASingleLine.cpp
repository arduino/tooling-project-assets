auto foo = []() {};

auto bar = []() {
};

auto baz = []() {
  return 42;
};

void qux(void (*)()) {}
void pippo() {
  qux([]() {});
}
