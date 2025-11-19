#include <stdio.h>
void myfunction(){
    printf("this is my function\n");
}
void myfunction1();
int main(){
myfunction();
myfunction1(5,10);
    return 0;
}
void myfunction1(int a, int b){
int c=a+b;
    printf("%d", c);


}