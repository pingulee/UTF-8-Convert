int sscanf(const char *str, const char *format, ...);

str: 입력 문자열입니다. 이 문자열로부터 데이터를 읽어들입니다.
format: 데이터를 읽어들이는 형식을 지정하는 서식 문자열입니다. 예를 들어, %d는 정수, %f는 실수, %2x는 2자리의 16진수를 의미합니다.
...: 데이터를 저장할 변수의 포인터들입니다. 서식 문자열에 따라, 데이터가 해당 변수들에 저장됩니다.

char str[] = "123 45.67";
int i;
float f;

sscanf(str, "%d %f", &i, &f);
printf("정수: %d, 실수: %.2f\n", i, f);