#include <stdio.h>


float add(float a,float b);
float subtract(float a,float b);
float multiply(float a,float b);
float divide(float a,float b);
int main()
{
    float a,b;
    char c;
    while(1) {
    printf("请输入表达式：");
    scanf("%f %c %f",&a,&c,&b);
    switch (c)
    {
    case '+' :
        printf("%.2f\n",add(a,b));
        break;
    case '-' :
        printf("%.2f\n",subtract(a,b));
        break;
    case '*' :
        printf("%.2f\n",multiply(a,b));
        break;
    case '/' :
        if(b==0) {
            printf("错误:除数不能为0\n");
        } else{
        printf("%.2f\n",divide(a,b));
        }
        break;
    default: printf("不支持这种运算\n");
        break;
    }
 }
    return 0;
}

float add(float a,float b) {
    return a+b;
}

float subtract(float a,float b) {
    return a-b;
}

float multiply(float a,float b) {
    return a*b;
}
float divide(float a,float b) {
    return a/b;
}