void foo(void (*)()) {}

void bar() {
  foo([]()
  {
    return;
  });

  foo([]() {
    return;
  });
}
