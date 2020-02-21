#include<stdio.h>

int main(int argc, char **argv)
{
        int ch;
        FILE *file = fopen(*++argv, "r");
        if ( file == NULL ) file = stdin;

        while ( (ch = getc(file)) != EOF )
        {
                if ( ch <= 31 || ch >= 127 ) if (ch != 9 && ch != 10 && ch != '') ch = ' ';
                putc(ch, stdout);
        }

        fclose(file);
        return 0;
}
