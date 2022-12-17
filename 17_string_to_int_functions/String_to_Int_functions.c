#include <stdio.h>
#include <stdlib.h>
#define EXIT_FAILURE 0
int myatoi (const char * str) //converts a string into an integer
{
    int result = 0;
    unsigned char starting_flag_for_sign = 0;
    unsigned char starting_flag_for_decimal = 0;

    unsigned char sign_flag = 0;
    while(*str != '\0')
    {
        if(starting_flag_for_sign == 0)
        {
            if (*str == '-')
            {
                sign_flag = 1;
                starting_flag_for_sign=1;
                str ++;
                if (*str == '0')
                {
                    printf("Please enter integers only\n");
                    return EXIT_FAILURE;
                }
                continue;
            }
            else if(*str>'9' || *str<'0')
            {
                printf("Please enter integers only\n");
                return EXIT_FAILURE;
            }
            starting_flag_for_sign=1;
        }
        if (*str>'9' || *str<'0')
        {
            printf("Please enter integers only\n");
            return EXIT_FAILURE;
        }
        switch(*str)
        {
            case '0':
                if (starting_flag_for_decimal == 0)
                {
                    result*=0;
                    result += 0;
                    starting_flag_for_decimal=1;
                }
                else
                {
                    result*=10;
                    result += 0;
                }
                break;

            case '1':
                if (starting_flag_for_decimal == 0)
                {
                    result*=0;
                    result += 1;
                    starting_flag_for_decimal=1;
                }
                else
                {
                    result*=10;
                    result += 1;
                }
                break;

            case '2':
                if (starting_flag_for_decimal == 0)
                {
                    result*=0;
                    result += 2;
                    starting_flag_for_decimal=1;
                }
                else
                {
                    result*=10;
                    result += 2;
                }
                break;
            case '3':
                if (starting_flag_for_decimal == 0)
                {
                    result*=0;
                    result += 3;
                    starting_flag_for_decimal=1;
                }
                else
                {
                    result*=10;
                    result += 3;
                }
                break;

            case '4':
                if (starting_flag_for_decimal == 0)
                {
                    result*=0;
                    result += 4;
                    starting_flag_for_decimal=1;
                }
                else
                {
                    result*=10;
                    result += 4;
                }
                break;

            case '5':
                if (starting_flag_for_decimal == 0)
                {
                    result*=0;
                    result += 5;
                    starting_flag_for_decimal=1;
                }
                else
                {
                    result*=10;
                    result += 5;
                }
                break;
            case '6':
                if (starting_flag_for_decimal == 0)
                {
                    result*=0;
                    result += 6;
                    starting_flag_for_decimal=1;
                }
                else
                {
                    result*=10;
                    result += 6;
                }
                break;
            case '7':
                if (starting_flag_for_decimal == 0)
                {
                    result*=0;
                    result += 7;
                    starting_flag_for_decimal=1;
                }
                else
                {
                    result*=10;
                    result += 7;
                }
                break;
            case '8':
                if (starting_flag_for_decimal == 0)
                {
                    result*=0;
                    result += 8;
                    starting_flag_for_decimal=1;
                }
                else
                {
                    result*=10;
                    result += 8;
                }
                break;
            case '9':
                if (starting_flag_for_decimal == 0)
                {
                    result*=0;
                    result += 9;
                    starting_flag_for_decimal=1;
                }
                else
                {
                    result*=10;
                    result += 9;
                }
                break;
        }
        str++;
    }
    if(sign_flag == 1) {return result*(-1);}
    else {return result;}
}
int main()
{
    printf("Testing myatoi function .... \n");
    const char * str = "123";
    printf("test 1: \nstring:  %s\n", str);
    int n = myatoi(str);
    printf("Integer: %d\n\n",n);

    str = "1111111";
    printf("test 2: \nstring:  %s\n", str);
    n = myatoi(str);
    printf("Integer: %d\n\n",n);

    str = "10101010";
    printf("test 3: \nstring:  %s\n", str);
    n = myatoi(str);
    printf("Integer: %d\n\n",n);

    str = "0";
    printf("test 4: \nstring:  %s\n", str);
    n = myatoi(str);
    printf("Integer: %d\n\n",n);

    str = "-1";
    printf("test 5: \nstring:  %s\n", str);
    n = myatoi(str);
    printf("Integer: %d\n\n",n);

    str = "-99";
    printf("test 6: \nstring:  %s\n", str);
    n = myatoi(str);
    printf("Integer: %d\n\n",n);

    str = "aa";
    printf("test 7: \nstring:  %s\n", str);
    n = myatoi(str);
    printf("Integer: %d\n\n",n);
    return 0;
}
