#include <stdio.h>

int main(int argc, char *argv[])
{
    if(argc < 2) {
        printf("ERROR: You need at least one argument.\n");
        return 1;
    }

    // 外层循环遍历所有命令行参数
    for(int j = 1; j < argc; j++) {
        printf("Processing argument %d: %s\n", j, argv[j]);

        // 内层循环遍历当前命令行参数中的每个字符
        for(int i = 0; argv[j][i] != '\0'; i++) {
            char letter = argv[j][i], lowercase_letter = letter;

            // 如果是大写字母，则转换为小写字母
            if(lowercase_letter >= 'A' && lowercase_letter <= 'Z') {
                lowercase_letter = lowercase_letter + 32;  // 转换为小写字母
            }

            switch(lowercase_letter) {
                case 'a':
                    printf("%d: 'a'\n", i);
                    break;

                case 'e':
                    printf("%d: 'e'\n", i);
                    break;

                case 'i':
                    printf("%d: 'i'\n", i);
                    break;

                case 'o':
                    printf("%d: 'o'\n", i);
                    break;

                case 'u':
                    printf("%d: 'u'\n", i);
                    break;

                case 'y':
                    if(i > 2) {
                        printf("%d: 'y'\n", i);
                    }
                    break;

                default:
                    printf("%d: %c is not a vowel\n", i, argv[j][i]);
            }
        }
    }

    return 0;
}

