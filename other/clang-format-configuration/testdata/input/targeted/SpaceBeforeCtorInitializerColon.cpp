class Foo {
  Foo();
  Foo(int);
  int bar;
};

Foo::Foo() : bar(42) {}

Foo::Foo(int baz): bar(baz) {}
