class Foo {
  Foo();
  Foo(int);
  Foo(int, int);
  Foo(int, int, int);
  int aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa;
  int bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb;
  int cccccccccccccccccccccccccccccccccccccccccccccccccc;
  int d;
  int e;
  int f;
  int ddddddddddddddddddddddddd;
  int ggggggggggggggggggggggggg;
  int hhhhhhhhhhhhhhhhhhhhhhhhh;
  int iiiiiiiiiiiiiiiiiiiiiiiii;
};

Foo::Foo()
  : aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa(42),
    bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb(1234),
    cccccccccccccccccccccccccccccccccccccccccccccccccc(11) {}

Foo::Foo(int bar)
  : aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa(bar), bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb(1234),
    cccccccccccccccccccccccccccccccccccccccccccccccccc(11) {}

Foo::Foo(int bar, int baz, int qux)
  : ggggggggggggggggggggggggg(bar), hhhhhhhhhhhhhhhhhhhhhhhhh(baz), iiiiiiiiiiiiiiiiiiiiiiiii(qux) {}
