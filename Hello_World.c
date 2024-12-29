#include <stdio.h>

void print_binary(unsigned char n) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1); // 每一位按位右移，输出每一位的值
    }
}

int main() {
    char str[] = "Hello, World!";
    
    // 遍历每个字符
    for (int i = 0; str[i] != '\0'; i++) {
        printf("Character: %c\n", str[i]);

        // 打印二进制
        printf("Binary: ");
        print_binary(str[i]);
        printf("\n");

        // 打印八进制
        printf("Octal: %o\n", str[i]);

        // 打印十进制
        printf("Decimal: %d\n\n", str[i]);
    }

    return 0;
}

