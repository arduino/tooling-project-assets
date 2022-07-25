class Foo {
  Foo();
  Foo(int);
  Foo(int, int);
  int bar;
  int baz;
};

Foo::Foo()
  : bar(42),
    baz(42) {}

Foo::Foo(int qux)
  : bar(qux), baz(42) {}

Foo::Foo(int qux, int pippo)
  : bar(qux),
    baz(pippo) {}
