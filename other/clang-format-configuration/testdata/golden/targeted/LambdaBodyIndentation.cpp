void foo(void (*)()) {}

void bar() {
  foo(
    []() {
      // baz
    });

  foo(
    []() {
      // baz
    });
}
