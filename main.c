#include <stdio.h>
#include<stdbool.h>
//Якщо число парне, його крайній правий
// біт буде 1, інакше 0. Виразом (x-1) ми
// змінюємо його парність і або крайній біт
// встановлюємо з 1 до 0, або рухаємо усі послідовність вправо
int bitcount(unsigned x) {
    int count = 0;
    while (x != 0) {
        x &= (x - 1);
        count++;
    }
    return count;
}
int main() {
    unsigned int a = 53;
    printf("%d", bitcount(a));

    return 0;
}
