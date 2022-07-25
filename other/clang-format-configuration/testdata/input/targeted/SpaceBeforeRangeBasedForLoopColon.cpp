void foo() {
  for (char bar : "baz") {
    (void) bar;
  }

  for (char bar: "baz") {
    (void) bar;
  }
}
