#include <iostream>
using namespace std;
#include "stack.h"
#include <cstring>

int main(int argc, char *argv[]) {
  Stack s;
  int match;
  char c;
  int i, j, in, out;
  for (int j = 1; j < argc; j++) {
    for (i = 0; i < strlen(argv[j]); i++) {
      match = 1;
      switch (argv[j][i]) {
      case '[':
      case '{':
        s.push(argv[j][i]);
        in++;
        break;

      case ']':
        c = s.pop();
        out++;
        if (c != '[')
          match = 0;
        break;
      case '}':
        c = s.pop();
        out++;
        if (c != '{')
          match = 0;
        break;
      default:
        break;
      }
    }
  }
  if (match == 0)
    cout << "doesn't match" << endl;
  else if (in < out)
    cout << "\ntoo many close bracket\n" << endl;
  else if (in > out)
    cout << "\ntoo many in bracket\n" << endl;
  else
    cout << "parentheses match" << endl;
}