#include <stdio.h>
#include <string.h>
#include <stddef.h>

#define max_num 200

typedef struct
{
    char name[100];
    int loan_money[100];
} User;

void signin(User *ptr, int *num);
void check(User *ptr, int *num);
void loan(User *ptr, int *num);
void grade();
void repayment(User *ptr, int *num);

int main(void)
{
    int person = 0;
    User user[max_num];
    int choice;
    while (1)
    {
        printf(" -------------------------\n");
        printf("   은행 대출 관리 시스템    \n");
        printf("                        \n");
        printf("    1. 회원 가입          \n");
        printf("    2. 회원 정보 확인      \n");
        printf("    3. 대출 신청          \n");
        printf("    4. 신용등급 정보       \n");
        printf("    5. 대출 상한          \n");
        printf("    6. 종료              \n");
        printf("                        \n");
        printf("   -------------------------\n");
        printf(" choice your item :");
        scanf("%d", &choice);
        if (choice == 1)
        {
            signin(user, &person);
        }
        if (choice == 2)
        {
            check(user, &person);
        }
        if (choice == 3)
        {
            loan(user, &person);
        }
        if (choice == 4)
        {
            grade();
        }
        if (choice == 5)
        {
            repayment(user, &person);
        }
        if (choice == 6)
        {
            printf("\n[EXIT]\n");
            return 0;
        }
    }
}

void signin(User *ptr, int *num)
{
    if (*num < max_num)
    {
        printf("\n[INSERT] \n");
        printf("INPUT NAME : ");
        scanf("%s", ptr[*num].name);
        (*num)++;
        printf("\nSUCCESS !! \n");
    }

    else
    {
        printf("Data Full \n\n");
    }
}

void check(User *ptr, int *num)
{
    char name[100];
    if (*num > 0)
    {
        printf("INPUT NAME : ");
        scanf("%s", name);
        for (int i = 0; i < max_num; i++)
        {
            if (strcmp(name, ptr[i].name) == 0)
            {
                printf("\n Data Found !!\n\n");
                printf("이름 : %s\n", ptr[i].name);
                printf("대출 금액 : %d원\n", *ptr[i].loan_money);
            }
        }
    }
    else
    {
        printf("No Data !!\n");
    }
}

void loan(User *ptr, int *num)
{
    char name;
    int money;
    if (*num > 0)
    {
        char name;
        int money = 0;
        printf("INPUT NAME : ");
        scanf("%s", &name);
        for (int j = 0; j < max_num; j++)
        {
            if (strcmp(&name, ptr[j].name) == 0)
            {
                printf("대출 신청 금액을 입력하세요 : ");
                scanf("%d", &money);
                *ptr[j].loan_money += money;
                printf("대출 신청 후 %s님의 대출 총액은 %d원입니다. \n", ptr[j].name, *ptr[j].loan_money);
            }
        }
    }
    else
    {
        printf("No Data !! \n\n");
    }
}

void grade()
{
    char *arr[] = {"200,000,000", "150,000,000", "100,000,000", "70,000,000", "40,000,000"};
    printf("[신용등급 표]\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d등급\t%s원\n", i + 1, arr[i]);
    }
}

void repayment(User *ptr, int *num)
{
    int money;
    char name;
    if (*num > 0)
    {
        int money;
        char name;
        printf("INPUT NAME : ");
        scanf("%s", &name);
        for (int i = 0; i < max_num; i++)
        {
            if (strcmp(ptr[i].name, &name) == 0)
            {
                printf("%s님의 대출 총액은 %d원입니다. \n", ptr[i].name, *ptr[i].loan_money);
                printf("갚으실 금액을 입력하세요 : ");
                scanf("%d", &money);
                *ptr[i].loan_money -= money;
                printf("대출 상환 후 %s님의 대출 금액은 %d원입니다.\n\n", ptr[i].name, *ptr[i].loan_money);
            }
        }
    }
    else
    {
        printf("No Data !! \n\n");
    }
}
