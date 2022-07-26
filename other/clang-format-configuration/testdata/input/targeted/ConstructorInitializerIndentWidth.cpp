class Foo {
  Foo();
  Foo(int);
  Foo(int, int);
  int pippo;
  int pluto;
  int paperino;
};
class Bar {};
class Baz {};

class Qux
: Foo,
  Bar,
    Baz {};

Foo::Foo()
: pippo(42),
  pluto(42),
    paperino(42) {}
