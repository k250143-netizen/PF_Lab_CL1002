#include <stdio.h>

int byValue(int x);
int byreference(int *x);

int main () {
    int a = 80;

    printf("Before updateValue: %d\n", a);
    int value = byValue(a);
    printf("After updateValue: %d (no change)\n\n",a);
    
    printf("Before updateReference: %d\n", a);
    byreference(&a);
    printf("After updateReference: %d (Updated Successfully)\n", a);

}
byValue(int x) {
    x = 85;
    return x;
}

byreference(int *x) {
    *x = 85;
    return *x;
}