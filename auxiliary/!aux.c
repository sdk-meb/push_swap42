#include "aux.h"


/*void    random_val(int *val)
{
    char    f[val[0] + 1];
    static int b;
    while (val[0])
    {
        b = val[0] + val[1] - val[0]/3 + b / 4;
        if (b < val[2] && b > val[1] && f[b] != 'n')
        {
            printf("%d  ",b);
            f[b] = 'n';
            val[0]--;
        }   
    }
}

int main()
{
    int r[3];
    char  s[]="\0\0\0\0\0\0\0\0\0\0";
    int     val[3];
    write(1, "count values ??  ", 17);
    r[0] = read (1, s, 10);
    val[0] = atoi(s);
    write(1, "min value ??  ", 15);
    r[1] = read (1, s, 10);
    val[1] = atoi(s);
    write(1, "max value ??  ", 15);
    r[2] = read (1, s, 10);
    val[2] = atoi(s);
    random_val(val);
}*/