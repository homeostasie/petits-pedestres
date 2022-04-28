#include <stdio.h>
#include <unistd.h>

int nb_argc(int argc)
{
    if(argc != 2 )
    {
        write(2, "no values given or too much argv\n", 33);
        return 1;
    }
    return argc;
}

int lg_argv(char *argv[])
{
    int arg_i =0;
    int val_i = 0;

    while( argv[1][arg_i] != '\0')
    {
        if (argv[1][arg_i] != ' ')
        {
            val_i++;
        }
        arg_i++;
    }
    return val_i ;
}

int cond_lg_argv(int arg_n)
{
    if (arg_n < 16)
    {
        write(2, "too few values\n", 14);
        return 1;
    }
    else if (arg_n > 16)
    {
        write(2, "too much values\n", 15);
        return 1;
    }
    return arg_n;
}

int cond_int_argv(char arg_i)
{

    int value = (int)arg_i;

    if (value <= 0 || value > 4)
    {
        write(2, "Invalide value\n", 15);
        return -1;
    }
    return value;
}
int cond_char_argv(char *argv[])
{

    int    arg_i = 0;
    int    val_i = 0;
    char   values[16];

    while( argv[1][arg_i] != '\0')
    {
        if (argv[1][arg_i] != ' ')
        {
            values[val_i] = (int)argv[1][arg_i] - 48;
            //printf("%d\n", values[val_i]); //debugging
            if (cond_int_argv(values[val_i]) != -1)
            {
                val_i++;
            }
            else
            {
                return -1;
            }
        }
        arg_i++;
    }
    return 0;
}


int main(int argc, char *argv[])
{
    // compile with ./a "1 2 3 4 1 2 3 4 1 2 3 4 1 2 3 4"
    if (nb_argc(argc) == 2 && 
        cond_lg_argv(lg_argv(argv)) == 16 && 
        cond_char_argv(argv) == 0)
    {
        write(2, "\n End Well \n", 10); 
    }
}