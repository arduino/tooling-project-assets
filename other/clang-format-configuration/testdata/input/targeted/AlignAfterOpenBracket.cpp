void foo(int arg1, int arg2) {
  (void)arg1;
  (void)arg2;
}

void bar() {
  foo(42,
    1234);
  foo(42,
      1234);
}
