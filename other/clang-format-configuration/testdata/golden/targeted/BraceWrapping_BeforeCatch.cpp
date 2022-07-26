void foo() {}

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
