template<int maxn>
struct FFT {
  using val_t = complex<double>;
  const double PI = acos(-1);
  val_t w[maxn];
  FFT() {
    for (int i = 0; i < maxn; ++i) {
      double arg = 2 * PI * i / maxn;
      w[i] = val_t(cos(arg), sin(arg));
    }
  }
  void bitrev(val_t *a, int n); // see NTT 
  void trans(val_t *a, int n, bool inv = false); // see NTT;
  // remember to replace LL with val_t
};
