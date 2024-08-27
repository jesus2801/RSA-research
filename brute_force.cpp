#include <bits/stdc++.h>
using namespace std;

long long exec(long long number) {
  string command = "./primegen/primes 1 " + to_string(number / 2);
  unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(), "r"), pclose);

  array<char, 128> buffer;
  if (!pipe) {
    throw std::runtime_error("popen() failed!");
  }

  while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    string prime(buffer.data());
    long long p = stoll(prime);
    if (number % p == 0){
      return p;
    }
  }

  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  long long number;
  cin >> number;

  long long answer = exec(number);
  cout << answer << endl;

  return 0;
}
