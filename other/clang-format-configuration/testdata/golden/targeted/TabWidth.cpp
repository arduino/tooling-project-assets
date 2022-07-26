// This test data must have multiple indentation levels in order to provide sufficient coverage of the unintuitive
// interaction between IndentWidth and TabWidth. See the TabWidth option notes for details.

void foo() {
  int bar =
    42;
  (void)bar;
  {
    int baz =
      42;
    (void)baz;
    {
      int qux =
        42;
      (void)qux;
    }
  }
}
