// copyright [2018] <mituh>
// Palindromes, uVa401

#include <stdio.h>
#include <string.h>
int main() {
  char a[1000];
  scanf("%s", a);
  const char rev[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
  const char let[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
  const char* msg[] = {"not a palindrome.", "a mirror string.",
                       "is a regular palindrome.", "is a mirrored palindrome."};
  int i, is_palindromes = 1, is_mirrored = 1;
  for (int beg = 0, end = strlen(a) - 1; beg <= end; beg++, end--) {
    // judge palindromes
    if (a[beg] != a[end]) is_palindromes = 0;
    // judge mirrored
    for (i = 0; a[end] && let[i] != a[end]; i++) {}
    if (a[beg] != rev[i]) is_mirrored = 0;
  }
  printf("%s -- %s\n", a, msg[is_palindromes*2 + is_mirrored]);
}

// 0, 0 => not a palindrome.         0
// 0, 1 => a mirror string.          1
// 1, 0 => is a regular Palindrome.  2
// 1, 1 => is a mirrored palindrome. 3
