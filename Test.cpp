#include <iostream>
#include <cstring>

using namespace std;

int main() {
  cout << "Welcome! Please enter a sentence." << endl;
  char c[100];
  int spaces = 0;
  cin.get(100, c);
  for (int a = 0; a < 100; a++) {
    if (c[a] == ' ') {
      spaces++;
    }
  }
  cout << "Total number of spaces: " << spaces << endl;
}
