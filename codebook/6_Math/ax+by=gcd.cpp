pii exgcd(int a, int b) {
  if (b == 0) return pii(1, 0);
  int p = a / b;
  pii q = exgcd(b, a % b);
  return pii(q.Y, q.X - q.Y * p);
}
/* ax+by=res, let x be minimum non-negative
g, p = gcd(a, b), exgcd(a, b) * res / g
if p.X < 0: t = (abs(p.X) + b / g - 1) / (b / g)
else: t = -(p.X / (b / g))
p += (b / g, -a / g) * t */
