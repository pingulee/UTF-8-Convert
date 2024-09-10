#include <stdio.h>

int valid(const char* hex_code, int* byte_good, int* err_num) {
    unsigned int hex;
    int byte_check = 0;
    int char_num = 0;

    *byte_good = 0;
    *err_num = 0;

    while (*hex_code) {
        if (sscanf(hex_code, "%2x", &hex) != 1) break;

        // 첫비트 확인
        if (byte_check == 0) { 
            if ((hex & 0x80) == 0x00) { // 0xxxxxxx = 1바이트
                byte_check = 0;
            } else if ((hex & 0xE0) == 0xC0) { // 110xxxxx = 2바이트
                byte_check = 1;
            } else if ((hex & 0xF0) == 0xE0) { // 1110xxxx = 3바이트
                byte_check = 2;
            } else if ((hex & 0xF8) == 0xF0) { // 11110xxx = 4바이트
                byte_check = 3;
            } else {
                *err_num = char_num + 1;
                return 0;
            }
        } else {
            if ((hex & 0xC0) != 0x80) {
                *err_num = char_num + 1;
                return 0;
            }
            byte_check--;
        }

        (*byte_good)++;
        while (*hex_code && *hex_code != ' ') hex_code++;
        if (*hex_code == ' ') hex_code++;
        
        if (byte_check == 0) {
            char_num++;
        }
    }

    return byte_check == 0;
}

void utf8_decode(const char* hex_code) {
    unsigned int hex;
    int char_count = 0;
    int byte_count = 0;
    int byte_good = 0;
    int err_num = 0;

    if (!valid(hex_code, &byte_good, &err_num)) {
        while (byte_good > 0 && *hex_code) {
            if (sscanf(hex_code, "%2x", &hex) != 1) break;
            printf("%c", hex);
            byte_count++;

            if ((hex & 0xC0) != 0x80) { 
                char_count++;
            }

            while (*hex_code && *hex_code != ' ') hex_code++;
            if (*hex_code == ' ') hex_code++;

            byte_good--;
        }
        printf(" 오류! %d번째 문자\n", err_num);
        return;
    }

    while (*hex_code) {
        if (sscanf(hex_code, "%2x", &hex) != 1) break;
        printf("%c", hex);
        byte_count++;

        if ((hex & 0xC0) != 0x80) { 
            char_count++;
        }

        while (*hex_code && *hex_code != ' ') hex_code++;
        if (*hex_code == ' ') hex_code++;
    }

    printf(" %d %d\n", char_count, byte_count);
}

int main() {
    char input[256];

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        utf8_decode(input);
    }

    return 0;
}
