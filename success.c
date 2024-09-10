#include <stdio.h>
#include <ctype.h>

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

/* 두 문자열 비교하는 함수 (like strcmp)
 * @param str1 1번째 문자열
 * @param str2 2번째 문자열
 * @return 두 문자열이 같으면 1, 다르면 0
 */
int my_strcmp(const char *str1, const char *str2) {
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);

    if (len1 != len2) {
        return 0;
    }

    for (int i = 0; i < len1; i++) {
        if (str1[i] != str2[i]) {
            return 0;
        }
    }

    return 1;
}

#define MAX_INPUT_SIZE 100

int hex_char_to_int(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return -1;
}

int hex_to_bytes(const char *hex_str, unsigned char *bytes) {
    int count = 0;
    while (*hex_str != '\0') {
        if (isspace(*hex_str)) {
            hex_str++;
            continue;
        }
        int high = hex_char_to_int(*hex_str++);
        int low = hex_char_to_int(*hex_str++);
        if (high == -1 || low == -1) {
            return -1;
        }
        bytes[count++] = (unsigned char)((high << 4) | low);
    }
    return count;
}

/* UTF-8 바이트 배열을 출력하고, 문자열의 개수도 출력
 * @param utf8_bytes UTF-8 바이트 배열
 * @param length 바이트 배열의 길이
 */
void print_utf8(const unsigned char *utf8_bytes, size_t length) {
    printf("문자열: ");
    int char_count = 0;
    size_t i = 0;

    while (i < length) {
        if ((utf8_bytes[i] & 0x80) == 0) {
            // 1바이트 문자
            putchar(utf8_bytes[i]);
            i++;
        } else if ((utf8_bytes[i] & 0xE0) == 0xC0) {
            // 2바이트 문자
            putchar(((utf8_bytes[i] & 0x1F) << 6) | (utf8_bytes[i + 1] & 0x3F));
            i += 2;
        } else if ((utf8_bytes[i] & 0xF0) == 0xE0) {
            // 3바이트 문자
            putchar(((utf8_bytes[i] & 0x0F) << 12) | ((utf8_bytes[i + 1] & 0x3F) << 6) | (utf8_bytes[i + 2] & 0x3F));
            i += 3;
        } else if ((utf8_bytes[i] & 0xF8) == 0xF0) {
            // 4바이트 문자
            putchar(((utf8_bytes[i] & 0x07) << 18) | ((utf8_bytes[i + 1] & 0x3F) << 12) | ((utf8_bytes[i + 2] & 0x3F) << 6) | (utf8_bytes[i + 3] & 0x3F));
            i += 4;
        }
        char_count++;
    }

    printf(" %d\n", char_count);
}

int main() {
    char hexInput[MAX_INPUT_SIZE];
    unsigned char utf8Bytes[MAX_INPUT_SIZE];
    int numBytes;

    while (1) {
        printf("> ");
        fgets(hexInput, sizeof(hexInput), stdin);

        numBytes = hex_to_bytes(hexInput, utf8Bytes);

        if (numBytes > 0) {
            print_utf8(utf8Bytes, numBytes);
        } else {
            printf("잘못된 입력입니다. 다시 시도해 주세요.\n");
        }
    }

    return 0;
}
