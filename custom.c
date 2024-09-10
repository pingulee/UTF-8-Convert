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