#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverseString(char* s, int sSize) 
{
		if(sSize <= 0) return;
    char copy[sSize];
    memcpy(copy, s, sizeof(char)*sSize); // copy s
    int i = 0;
    // while(sSize >= 0) { s[i++] = copy[--sSize]; } 	// 這樣在我這邊會過，但在 leetcode 會到 -1
    while(sSize > 0) {;s[i++] = copy[--sSize];  } 		// 這樣在 leetcode 會過，但在我這邊會 ollehhannaH
}

int main()
{

	// 用 "" 會發生 warning: excess elements in char array initializer
	// char t[] = {"H","a","n","n","a","h"};  
	char t[6] = {'H', 'a', 'n', 'n', 'a', 'h'};
	reverseString(t, 6);
	printf("%s\n", t);

	// 有宣告初始值的字元陣列宣告可以不用寫長度
	// (一般建立字串用 char* = ""，建立字元陣列才用 char[] = {})
	char u[] = {'h', 'e', 'l', 'l', 'o'};
	reverseString(u, 5);
	printf("%s\n", u);

	char v[] = {};
	reverseString(v, 0);

	return 0;
}