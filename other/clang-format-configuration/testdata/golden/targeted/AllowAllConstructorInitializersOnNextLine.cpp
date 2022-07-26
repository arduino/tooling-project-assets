class Foo {
  Foo();
  Foo(int);
  int bar;
  int baz;
};

Foo::Foo()
  : bar(42), baz(1234) {}

Foo::Foo(int qux)
  : bar(qux),
    baz(1234) {}
