int foo();

int foo() { return 42; }

class Bar {
  int foo() { return 42; }
};

int
baz();

int
baz() {
  return 42;
}

class Qux {
  int
  baz() {
    return 42;
  }
};
