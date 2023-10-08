#include <cstdio>

int main() {
    char ch[101];
    scanf("%s", ch);  // 문자열을 읽어들일 때 &를 사용하지 않습니다.
    int i = 0;
    int cnt = 0;
    
    while (ch[i] != '\0') {  // 문자열의 끝은 null 문자로 표시됩니다.
        printf("%c", ch[i]);
        i++;
        cnt++;
        if (cnt == 10) {
            printf("\n");
            cnt = 0;  // 줄 바꿈 후 cnt 초기화
        }
    }
    
    return 0;
}