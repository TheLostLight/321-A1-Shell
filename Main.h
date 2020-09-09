const char NULL_CHAR   = '\0';
const char ESCAPE_CHAR = '\n';
const char MY_PROMPT[] = "\033[0;36mCustom Shell>\033[0m ";

const char *commands[] = {
    "exit",
    "ls",
    "cat",
    "cd",
    "echo",
    "dir",
    "dog"
};

//void (*command_functions[6]) ( void );

char user_input[20];
char next_char;

char exit_command[10] = "exit";

void setNull(char *str, int buffer_size);

//void exit(void);

//void ls(void);

//void cat(void);

//void cd(void);

//void echo(void);

//void dog(void);