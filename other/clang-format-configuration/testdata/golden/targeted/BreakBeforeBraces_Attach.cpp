extern "C" {
  void foo();
}

void foo() {
  switch (1) {
    case 2:
      {
        break;
      }
  }

  if (true) {
    return;
  }

  do {
    continue;
  } while (true);
}

void bar() {
  try {
    foo();
  } catch (int e) {
    (void)e;
  }
  try {
    foo();
  } catch (int e) {
    (void)e;
  }
}

class Foo {
public:
};

enum Foo_t {
  A,
  B
};

namespace {
const int foo = 42;
}

struct Bar_t {
  int foo;
};

union Baz_t {
  int foo;
};
