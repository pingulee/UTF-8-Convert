#include <stdio.h>

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

int main() {
    
    return 0;
}
