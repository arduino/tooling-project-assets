void foo(int bar) {
  (void)bar;
}

void baz(int qux) {
  foo(qux);

  foo(qux);
}
