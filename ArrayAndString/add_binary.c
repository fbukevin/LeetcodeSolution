#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* addBinary(char* a, char* b) {
	int carry = 0;
	int len_a = strlen(a), len_b = strlen(b);
	int max_len = len_a > len_b ? len_a : len_b;

	// +2 是因為要塞 \0 和溢出進位(溢位, 999 進位到 1000)
	char* c = malloc(max_len + 2);
	c[max_len + 1] = '\0';

	while(len_a || len_b){ // 任一個還沒結束就繼續

		// 如果兩者的前一位數是 '1'，其 ASCII 減 '0' 的 ASCII 會是整數 1，否則是 0
		// 注意，a[0] 是最左邊，但數字第一位數是最右邊，index 是 len_a - 1
		// 所以下面這兩行等於是從最右邊那個數開始檢查
		if(len_a) carry += (a[--len_a] - '0');
		if(len_b) carry += (b[--len_b] - '0');
		
		// carry 可能是 0(0000), 1(0001), 2(0010)
		// 跟 1 做 AND 運算，是為了取最右邊那個位元放進 c
		c[max_len--] = (carry & 1) + '0';

		// 這個是把 carry 右移一個位元，使 carry 恢復要不是 0 就是 1(有進位)，以便下一輪使用
    carry >>= 1;	
	}
	// 至此，c[1] ~ c[max_len-1] 就是兩數的總和，但是不包含溢位

	// 處理溢出進位最大的那個位數(最左邊)
	// 把 carry 加上 '0' 是假如有溢位，則 c[0] 應為 '1'，否則是 '0'	
	c[0] = carry + '0';

	// carry 跟 1 做 XOR (0 1 1 0)，如果 carry 是 0
	// 運算結果會是 1 (0 XOR 1 = 1)，否則是 0 (1 XOR 1 = 0)
	return c + (carry ^ 1);	
}

int main(){
		char* a = "11", *b = "1";
		char* c = addBinary(a, b);
		printf("%s\n", c);

		a = "1010", b = "1011";
		c = addBinary(a, b);
		printf("%s\n", c);

		a = "0", b = "0";
		c = addBinary(a, b);
		printf("%s\n", c);
}