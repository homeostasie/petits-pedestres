#include <stdio.h>
#include <unistd.h>



int    main(int argc, char *argv[])
{
    if(argc == 2 && argv)
    {
        int    arg_i;
        int    val_i;
        char    values[16];

        arg_i = 0;
        val_i = 0;
        while( argv[1][arg_i] != '\0')
        {
            
            if (argv[1][arg_i] != ' ')
            {
                values[val_i] = (int)argv[1][arg_i] - 48;
                printf("%d\n", values[val_i]); //debugging
                if (values[val_i] <= 0 || values[val_i] > 4 || val_i > 15)
                {
                    write(2, "Invalide value or too much\n", 27);
                    return 1;
                }
                val_i++;
            }
            arg_i++;
        }
        if (val_i < 15)
        {
            write(2, "too few values\n", 27);
            return 1;

        }
    }
    else
    {
        write(2, "no values given or too much argv\n", 33);
        return 1;
    }
    //debug :
    write(2, "\nEnd Well\n", 10); // ne doit pas etre afficher en cas de data non valide
    return 0;
}