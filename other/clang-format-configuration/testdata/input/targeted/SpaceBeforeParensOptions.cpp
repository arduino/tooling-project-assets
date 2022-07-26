void foo() {
  if (true) {}
  if(true) {}
}

void bar (int);
void baz(int);

void bar (int qux) {
  (void)qux;
}
void baz(int qux) {
  (void)qux;
}

#if (true)
#endif
#if(true)
#endif

class Foo {
public:
  Foo(){};
  Foo(int baz)
    : bar(baz) {}
  int bar;

  Foo operator++ (int qux) {
    (void)qux;
    return Foo(42);
  }

  Foo operator--(int qux) {
    (void)qux;
    return Foo(42);
  }
};

void pippo() {}
void pluto () {}
