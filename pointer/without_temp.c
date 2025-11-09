#include <stdio.h>
// swap without temp variable in pointer
void swap(int *x, int *y){
    *x = *x + *y;// a = a+b;
    *y = *x - *y;// b = a-b;
    *x = *x - *y;// a = a-b;
}
int main(){
 int a = 5, b = 10;
 swap(&a, &b);
 printf("a=%d b=%d", a, b);
    return 0;
}