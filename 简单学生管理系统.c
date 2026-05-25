#include<stdio.h>

#define MAX 100

struct student {
    int id;
    char name[20];
    float score;
};

struct student stu[MAX];
int cnt=0;

void add();
void show();
void search();

int main()
{
    int choice;
    while(1) {
    printf("\n===== 学生成绩管理系统 =====\n");
        printf("1. 添加学生\n");
        printf("2. 查看全部学生\n");
        printf("3. 查询学生\n");
        printf("0. 退出\n");
        printf("请选择：");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                add();
                break;

            case 2:
                show();
                break;

            case 3:
                search();
                break;

            case 0:
                printf("程序结束！\n");
                return 0;

            default:
                printf("输入错误！\n");
        }
    }

    return 0;
}

void add() {
    printf("请输入学号：");
    scanf("%d",&stu[cnt].id);
    printf("请输入姓名：");
    scanf("%s",stu[cnt].name);
    printf("请输入成绩：");
    scanf("%f",&stu[cnt].score);
    cnt++;
}

void show() {
    printf("\n学号\t姓名\t成绩");
    for(int i=0;i<cnt;i++) {
        printf("\n%d\t%s\t%.2f",stu[i].id,stu[i].name,stu[i].score);
    }
}

void search() {
    int id1;
    printf("请输入要查询学生的学号：");
    scanf("%d",&id1);
    for(int i=0;i<cnt;i++) {
        if (stu[i].id==id1) {
            printf("学生的姓名:%s 成绩：%f",stu[i].name,stu[i].score);
            return;
        } 
        }
        printf("未找到该学生");
    }
    
