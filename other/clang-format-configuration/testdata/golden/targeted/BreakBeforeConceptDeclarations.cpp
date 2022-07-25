template<typename T>
concept foo = requires(T bar) {
  (void)bar;
};

template<typename T> concept baz = requires(T bar) {
  (void)bar;
};
