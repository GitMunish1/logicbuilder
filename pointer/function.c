#include <stdio.h>
// write a function and pass the value by reference
void multiplybyten(int *p){
    *p = *p * 10;

}
int main(){
    int i = 4;
    multiplybyten(&i);
    printf("value of i after multiplying by ten = %d", i);
    return 0;
}