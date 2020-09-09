#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include "Main.h"

#define true 1
#define false 0

#define EXIT_ERROR 1
#define EXIT_OKAY  0

#define CHILD_PID 0

int main()
{
    pid_t pid;

    while(true)
    {
        
        
        printf("%s", MY_PROMPT);

        setNull(&user_input, sizeof(user_input));

        scanf("%c", &next_char);

        for(int i=0; i<sizeof(user_input) && next_char != ESCAPE_CHAR; i++)
        {
            user_input[i] = next_char;
            scanf("%c", &next_char);
        }

        pid = fork();

        if(pid == CHILD_PID)
        {
            for(int i=0; i<sizeof(commands); i++)
            {
                if(strncmp(user_input, commands[i], strlen(commands[i])) == false)
                {
                    printf("\033[A\r%s\e[31m", MY_PROMPT);
                    for(int j=0; j<strlen(commands[i]); j++) printf("%c", user_input[j]);
                    printf("\e[39m");
                    for(int j=strlen(commands[i]); j<strlen(user_input); j++) printf("%c", user_input[j]);
                    printf(" \n");

                    system(user_input);
                } 
            }
            exit(EXIT_OKAY);
        }

        wait(NULL);

        if(strncmp(user_input, exit_command, strlen(exit_command)) == false) _exit(EXIT_OKAY);
        
    }

    _exit(EXIT_ERROR);
}

void setNull(char *str, int buffer_size)
{
    for(int i=0; i<buffer_size; i++) str[i] = NULL_CHAR;
}