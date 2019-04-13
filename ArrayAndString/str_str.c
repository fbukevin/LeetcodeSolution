#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int strStr(char* haystack, char* needle)
{
  int i = 0, pos = 0, len_needle = strlen(needle);
  char* copy = haystack; // avoid override haystack

  // 如果 copy 的剩餘長度小於 needle，就不用再找了
  while(strlen(copy) >= len_needle)
  {
    while(copy[i] == needle[i] && needle[i] != '\0') i++;
    if(needle[i] == '\0') return j;

    copy += 1;  // 將 haystack 向左移一位
    pos += 1;   // 累加已走訪的 haystack 的 index
    i = 0;      // reset index i
  }

  // 找無，回傳 -1
  return -1;
}

int main()
{

  char* haystack = "hello", *needle = "ll";
  printf("%d\n", strStr(haystack, needle));

  haystack = "aaaaa", needle = "bba";
  printf("%d\n", strStr(haystack, needle));

  return 0;
}
