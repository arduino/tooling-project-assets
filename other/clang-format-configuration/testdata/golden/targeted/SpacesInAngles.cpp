template<int foo> void bar() {}

void baz() {
  bar< 42 >();
  bar<42>();
}
