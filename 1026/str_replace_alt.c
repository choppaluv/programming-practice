#include <stdio.h>

int read_line(char *line)
{
    char ch;
    int len = 0;
    
    while ((ch=getchar()) != '\n' && ch != EOF)
        line[len++] = ch;
    line[len] = '\0';

    return len;
}

int str_match(char *x, char *y)   // returns 1 for match, 0 for non-match
{
    while (*x && *y)
        if (*y != '?' && *x != *y)
            return 0;   // not matched
        else {
            x++;
            y++;
        }
    if (*y == '\0')
        return 1;   // matched
    else
        return 0;   // x is shorter than y
}

void str_overwrite(char *dest, char *src)
{
    while (*src)
        *dest++ = *src++;

    return;
}

int main()
{
    char x[1001], y[1001], z[1001];
    int len_x, len_y;
    char *p;

    len_x = read_line(x);
    len_y = read_line(y);
    (void) read_line(z);
    
    p = x;
    while (*p)
    {
        if (str_match(p, y))
        {
            str_overwrite(p, z);
            p += len_y;
        }
        else
            p++;
    }
    
    printf("%s\n", x);
    
    return 0;
}
