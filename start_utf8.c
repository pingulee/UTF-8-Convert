#include <stdio.h>

/* 문자열 길이 구하는 함수 (like strlen)
 * @param str 길이를 구할 문자열
 * @return 문자열의 길이
 */
int my_strlen(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void hex_to_utf8(const char *hex) {
    unsigned int len = my_strlen(hex);
    unsigned char byte;
    unsigned char buffer[256];
    unsigned int buffer_index = 0;

    for (unsigned int i = 0; i < len; i += 3) {
        if (sscanf(hex + i, "%2hhx", &byte) != 1) {
            fprintf(stderr, "잘못된 16진수 형식입니다.\n");
            return;
        }
        buffer[buffer_index++] = byte;
    }
    buffer[buffer_index] = '\0';

    printf("UTF-8 문자열: %s\n", buffer);
}

int main() {
    while (1) {
        char hex_input[512];
        printf("> ");
        if (fgets(hex_input, sizeof(hex_input), stdin) == NULL) {
            perror("입력 오류");
            return 1;
        }

        unsigned int len = my_strlen(hex_input);
        if (len > 0 && hex_input[len - 1] == '\n') {
            hex_input[len - 1] = '\0';
        }

        hex_to_utf8(hex_input);
    }

    return 0;
}
