#include <stdio.h>
#include <stdint.h>
#include <windows.h>

/*
 * 문자열 길이 구하는 함수 (like strlen)
 * @param str 길이를 구할 문자열
 * @return 문자열의 길이
@param 
*/
int my_strlen(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

/*
 * 두 문자열 비교하는 함수 (like strcmp)
 * @param str1 1번째 문자열
 * @param str2 2번째 문자열
 * @return 두 문자열이 같으면 1, 다르면 0
@param 
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

/*
 * UTF-8 바이트 배열을 디코딩하여 문자열로 변환하는 함수
 * @param utf8_bytes 입력된 UTF-8 바이트 배열
 * @param output 디코딩된 문자열을 저장할 버퍼
 */
// void utf8_decode(const uint8_t *utf8_bytes, char *output) {
//     int i = 0;
//     int j = 0;

//     while (utf8_bytes[i] != 0) {
//         uint8_t byte = utf8_bytes[i];
        
//         // 1바이트 문자 (ASCII)
//         if ((byte & 0x80) == 0) {
//             output[j++] = byte;
//         }
//         // 2바이트 문자
//         else if ((byte & 0xE0) == 0xC0) {
//             uint16_t code_point = ((byte & 0x1F) << 6) | (utf8_bytes[i+1] & 0x3F);
//             output[j++] = (char)code_point;
//             i++; // Skip the next byte
//         }
//         // 3바이트 문자
//         else if ((byte & 0xF0) == 0xE0) {
//             uint16_t code_point = ((byte & 0x0F) << 12) | ((utf8_bytes[i+1] & 0x3F) << 6) | (utf8_bytes[i+2] & 0x3F);
//             output[j++] = (char)code_point;
//             i += 2; // Skip the next 2 bytes
//         }
//         // 4바이트 문자
//         else if ((byte & 0xF8) == 0xF0) {
//             uint32_t code_point = ((byte & 0x07) << 18) | ((utf8_bytes[i+1] & 0x3F) << 12) | ((utf8_bytes[i+2] & 0x3F) << 6) | (utf8_bytes[i+3] & 0x3F);
//             // Note: Code points for characters outside the BMP (Basic Multilingual Plane) need additional handling
//             output[j++] = (char)code_point; // Simplification for this example
//             i += 3; // Skip the next 3 bytes
//         }
        
//         i++;
//     }
//     output[j] = '\0';
// }

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    char output[256];

    scanf("%s", output);
    printf("%s\n", output);
    getchar();
    return 0;
}