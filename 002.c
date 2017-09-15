#include<stdio.h>  
  
/*******递归的方式写字符串长度函数*******/  
int my_strlen(char *str)    
{  
    if(*str == '\0')    //当传入的字符串中没有字符  
        return 0;       //字符串长度为0  
    else  
        return 1+ my_strlen(str+1); /*运用递归，每递归一次 
    长度加1，直到遍历到的'\0'时结束递归*/  
}   
/*******递归方式写字符串反转*******/  
int reverse_string(char *string)  
{  
    int len = my_strlen(string);//调用上面的字符串长度函数;  
    if(len <= 1) //当字符串长度小于等于1时，不执行；  
        return 0;  
    else  
    {  
        char ch = string[len-1];//将最后一个字符赋给第一个字符;  
        string[len-1] = '\0'; 
        if (string[0] != ch)
        {
            return 1;
        }
        else
        {
            return reverse_string(string + 1);  //将最后一个字符的内容赋为'\0'; 
        }
    }  
}  


  
int main()  
{  
    char ch[] = "abcba";  
    char ch2[] = "123";
    char ch3[] = "abccba";
    char ch4[] = "1111";
    printf("%d\n", reverse_string(ch));  
    printf("%d\n", reverse_string(ch2)); 
    printf("%d\n", reverse_string(ch3)); 
    printf("%d\n", reverse_string(ch4)); 
    
    return 0;  
}  