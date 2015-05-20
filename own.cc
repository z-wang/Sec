
#include <iostream>

template<typename T, int N, int M>
struct mat
{
  T v[N][M];
  mat();
};

template<typename T, int N, int M>
mat<T,N,M>::mat() {
  for (int n = 0; n < N; ++n)
    for (int m = 0; m < M; ++m)
      std::cout << (v[n][m] = n * M + m) << std::endl;
}

int
main(void)
{
  mat<float, 4,3> m;
  mat<float, 2,4> n;
  std::cout << "end\n";
}
