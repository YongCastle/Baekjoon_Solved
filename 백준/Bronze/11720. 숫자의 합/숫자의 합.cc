#include <cstdio>
#include <cstring>

int main(void){
    int T; scanf("%d", &T);
    getchar();  //'\n' Buffer Remove
    int sum=0;
    char ch;
	for(int i=0; i<T; i++){
        scanf("%c", &ch);
        sum += int(ch)-int('0');
    }
    printf("%d", sum);
	return 0;
}