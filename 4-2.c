/* Extend atof to handle scientific notation of the form */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

double atof1(char s[]);

int main(void)
{

    char s1[20] = " +2 37.2 4E-5";
    char s2[20] = " -2   37.24E6";
    atof1(s1);
    atof1(s2);

    return 0;
}

double atof1(char s[])
{
    int sign, j = 0;
    double val, power;
    char copy[strlen(s)];

    // Remove all space in input string
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isspace(s[i]))
        {
            copy[j++] = s[i];
        }
    }
    copy[j] = '/0';

    // reset j to 0
    j = 0;
    // check sign of s[] of increase j to next
    sign = (copy[j++] == '-') ? -1 : 1;
    
    for (val = 0.0; isdigit(copy[j]); j++)
    {
        val = 10.0 * val + (copy[j] - '0');
    }
    if (copy[j] == '.')
    {
        j++;
    }
    for (power = 1.0; isdigit(copy[j]); j++)
    {
        val = 10.0 * val + (copy[j] - '0');
        power *= 10.0;
    }
    val = sign * val / power;

    if ((copy[j] == 'e' || copy[j] == 'E' ) && j <= strlen(copy) - 1)
    {
        j++;
        if (copy[j] == '-')
        {
            j++;
            if (isdigit(copy[j]))
            {
                power = pow(10,(copy[j] - '0'));
                val /= power;
            }
        }
        else if (isdigit(copy[j]))
        {
                power = pow(10,(copy[j] - '0'));
                val *= power;
        }
    }
    printf("The value of string %s is %.10f \n", s, val);
    return val;
}