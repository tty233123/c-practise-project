#include <stdio.h>
#include <string.h>

#define MAX 100
struct Contact
{
    char name[30];
    char phone[20];
    char email[30];
};

struct Contact contacts[MAX];
int cnt=0;

void add() {
    printf("请输入联系人的名字:\n");
    scanf("%s",contacts[cnt].name);
    printf("请输入联系人的电话:\n");
    scanf("%s",contacts[cnt].phone);
    printf("请输入联系人的邮箱:\n");
    scanf("%s",contacts[cnt].email);
    cnt++;
}

void show() {
    printf("联系人名字\t电话\t邮箱\n");
    for (int i = 0; i < cnt; i++)
    {
        printf("%s\t",contacts[i].name);
        printf("%s\t",contacts[i].phone);
        printf("%s\t",contacts[i].email);
        printf("\n");
    }
    
}

void search() {
    char name1[30];
    printf("请输入要查找联系人的名字:");
    scanf("%s",name1);
    for (int i = 0; i < cnt; i++)
    {
        if(!(strcmp(name1,contacts[i].name))) {
            printf("该联系人的电话:%s  邮箱:%s",contacts[i].phone,contacts[i].email);
            return;
        }
    }
    printf("未找到该联系人");
    
}

void modify() {
    char name1[30];
    printf("请输入要修改联系人的名字:");
    scanf("%s",name1);
    for (int i = 0; i < cnt; i++)
    {
        if(!(strcmp(contacts[i].name,name1))) {
            printf("新的电话:");
            scanf("%s",contacts[i].phone);
            printf("新的邮箱:");
            scanf("%s",contacts[i].email);
            printf("修改成功！\n");
            return;
        }
    }
    printf("未找到该联系人");
}

void delete() {
    char name1[30];
    printf("请输入要删除联系人的名字:");
    scanf("%s",name1);
    for (int i = 0; i < cnt; i++)
    {
        if(!(strcmp(contacts[i].name,name1))) {
            for (int j = i; j < cnt-1; j++)
            {
                strcpy(contacts[j].name,contacts[j+1].name);
                strcpy(contacts[j].phone,contacts[j+1].phone);
                strcpy(contacts[j].email,contacts[j+1].email);
            }
            cnt--;
            printf("删除成功!");
            return;
        }
    }
    printf("未找到该联系人");
    

}

void sort() {
    for(int i=0;i<cnt-1;i++) {
        for(int j=0;j<cnt-1-i;j++) {
            if( (strcmp(contacts[j].name,contacts[j+1].name))>0) {
                struct Contact t = contacts[j];
                contacts[j] = contacts[j+1];
                contacts[j+1] = t;
            }
        }
    }
}

void save() {
    FILE *fp = fopen("data","wb");
    if(fp == NULL)
    {
        printf("文件打开失败！\n");
        return;
    }
    fwrite(&cnt,sizeof(int),1,fp);
    fwrite(contacts,sizeof(struct Contact),cnt,fp);
    fclose(fp);
    printf("保存成功！\n");
}

void load() {
    FILE *fp = fopen("data","rb");
    if(fp == NULL)
    {
        printf("文件打开失败！\n");
        return;
    }
    fread(&cnt, sizeof(int), 1, fp);
    fread(contacts, sizeof(struct Contact), cnt, fp);
    fclose(fp);
    printf("加载成功！\n");
}

int main()
{
    int choice;
    load();
    while(1) {

    printf("\n===== 通讯录管理系统 =====\n");
    printf("1. 添加联系人\n");
    printf("2. 查看全部联系人\n");
    printf("3. 查询联系人\n");
    printf("4. 修改联系人\n");
    printf("5. 删除联系人\n");
    printf("6. 按姓名排序\n");
    printf("7. 保存数据\n");
    printf("8. 加载数据\n");
    printf("0. 退出系统\n");
    printf("===================================\n");
    printf("请选择：");
    scanf("%d",&choice);
    switch (choice)
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
    case 4:
        modify();
        break;
    case 5:
        delete();
        break;
    case 6:
        sort();
        break;
    case 7:
        save();
        break;
    case 8:
        load();
        break;
    case 0:
        save();
        printf("系统退出！\n");
        return 0;
    default:printf("输入错误，请重新选择！\n");
        break;
    }
}
    return 0;
}
