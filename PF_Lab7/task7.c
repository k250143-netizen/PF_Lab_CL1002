#include <stdio.h>

int main() {
    char characters[5] = {'h', 'e', 'l', 'l', 'o'};
    char element;
    int a = 0, e = 0, i_vowel = 0, o = 0, u = 0, consonants = 0;

    for (int j = 0; j < 5; j++) {
        element = characters[j];

        switch (element) {
        case 'a':
            a++;
            break;
        case 'e':
            e++;
            break;
        case 'i':
            i_vowel++;
            break;
        case 'o':
            o++;
            break;
        case 'u':
            u++;
            break;
        default:
            if ((element >= 'a' && element <= 'z'))
                consonants++;
            break;
        }
    }

    printf("a = %d\n", a);
    printf("e = %d\n", e);
    printf("i = %d\n", i_vowel);
    printf("o = %d\n", o);
    printf("u = %d\n", u);
    printf("Consonants = %d\n", consonants);

    return 0;
}
