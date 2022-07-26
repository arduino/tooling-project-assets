template<typename T> T foo() {}
template<typename T>
T bar() {}

template<typename T> T baz(int a,
                           int b) {
  (void)a;
  (void)b;
}
template<typename T>
T qux(int a,
      int b) {
  (void)a;
  (void)b;
}
