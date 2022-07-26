// This test data must have multiple indentation levels in order to provide sufficient coverage of how UseTab is
// affected by the unintuitive interaction between IndentWidth and TabWidth. See the TabWidth option notes for details.

int a;                                   // foo
int bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb;  // foo
void bar() {
  int baz =
    42;
  (void)baz;
  {
    int qux =
      42;
    (void)qux;
    {
      int pippo =
        42;
      (void)pippo;
    }
  }
}
