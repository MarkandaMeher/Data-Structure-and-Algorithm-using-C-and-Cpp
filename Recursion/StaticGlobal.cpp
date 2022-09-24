#include<stdio.h>
// for global int x = 0; same result
int fun(int n){
    static int x =0;
    if(n>0){
        x++;
        return fun(n-1)+x;
    }
    return 0;
}
int main(){
    int r;
    r = fun(5);
    printf("%d ",r);
    return 0;
}