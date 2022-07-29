class Foo {
  Foo();
  Foo(int);
  Foo(int, int);
  Foo(int, int, int);
  Foo(int, int, int, int);
  int a;
  int b;
  int c;
  int dddddddddddddddddddddddddddddddddddddddddddddddddd;
  int eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee;
  int ffffffffffffffffffffffffffffffffffffffffffffffffff;
  int d;
  int e;
  int f;
  int ggggggggggggggggggggggggg;
  int hhhhhhhhhhhhhhhhhhhhhhhhh;
  int iiiiiiiiiiiiiiiiiiiiiiiii;
};

Foo::Foo()
  : a(42),
    b(1234),
    c(11) {}

Foo::Foo(int bar)
  : dddddddddddddddddddddddddddddddddddddddddddddddddd(bar), eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee(1234),
    ffffffffffffffffffffffffffffffffffffffffffffffffff(11) {}

Foo::Foo(int bar, int baz) : a(bar), b(baz), c(11) {}

Foo::Foo(int bar, int baz, int qux)
  : dddddddddddddddddddddddddddddddddddddddddddddddddd(bar),
    eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee(baz),
    ffffffffffffffffffffffffffffffffffffffffffffffffff(qux) {}

Foo::Foo(int bar, int baz, int qux, int pippo)
  : ggggggggggggggggggggggggg(bar), hhhhhhhhhhhhhhhhhhhhhhhhh(baz), iiiiiiiiiiiiiiiiiiiiiiiii(qux) {
  (void)pippo;
}
