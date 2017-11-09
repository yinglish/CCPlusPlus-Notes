#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>


void test1()
{
    char *s = "yin xian jun";
    char str[32] = "hello world";

    printf("%d ", sizeof(s));
    printf("%d \n", strlen(s));
    printf("%d ", sizeof(str));
    printf("%d \n", strlen(str));
}

void test2()
{
    printf("max of int: %d\n", INT_MAX);
    printf("min of int: %d\n", INT_MIN);
    printf("max of float: %f\n", FLT_MAX);
    printf("min of float: %f\n", FLT_TRUE_MIN);
    printf("negative float: %f\n", -3.14f);
}

void test3()
{
    int a = printf("yin\n");
    printf("%d\n", a);
}

void test4()
{
    char word[10];
    int a = 10;
    puts("Enter a string, please.");
    printf("%d\n", sizeof(word));
    gets(word);
    printf("Your string twice:\n");
    printf("%s\n", word);
    puts(word);
    printf("%d\n", sizeof(word));
    printf("%d\n", strlen(word));
    printf("%d\n", a);
}

void test5()
{
    char words[20];
    puts("Enter a string, please.");
    fgets(words, 20, stdin);
    printf("Your string twice (puts), the fputs):\n");
    puts(words);
    fputs(words, stdout);
}

void test6()
{
    char flower[80];
    char addon[] = "s smell like old shoes.";

    gets(flower);
    strcat(flower, addon);
    puts(flower);
}

void test7()
{
    char flower[20];
    strncpy(flower, "yin", 5);
    //flower[3] = '\0';
    puts(flower);
}

void test8()
{
    char first[20];
    char last[20];
    char formal[41];
    double prize;
    puts("Enter your first name:");
    gets(first);
    puts("Enter your last name:");
    gets(last);
    puts("Enter your prize money:");
    scanf("%lf", &prize);
    sprintf(formal, "%s, %-19s: $%6.2f\n", last, first, prize);
    puts(formal);
}

void test9()
{
    char result[40];
    result[0] = '\0';
    char tmp[10];
    sprintf(tmp, "%d", 51);
    strcat(result, tmp);
    strcat(result, ",");
    sprintf(tmp, "%d", 93);
    strcat(result, tmp);
    puts(result);
}

void test10()
{
    char a[] = "yin";
    char *p = strchr(a, 'i');
    if (p != NULL)
        printf("i exist.\n");
}

void test11()
{
    int a[5];
    memset(a, 0, sizeof(a));
    printf("%d\n", sizeof(a));
    for (int i = 0; i < 5; ++i)
        printf("%d ", a[i]);
    printf("\n");
    int b[5] = {1, 2, 3, 4, 5};
    memcpy(a, b, sizeof(a));
    for (int i = 0; i < 5; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

int main(void)
{
    test11();
    //test10();
    //test9();
    //test8();
    //test7();
    //test6();
    //test1();
    //test2();
    //test3();
    //test4();
    //test5();
    return 0;
}