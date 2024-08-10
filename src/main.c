#include <stdio.h>
#include <stdbool.h>
#include <string.h>

////////////////////////////////////
// START term color codes section //
///////////////////////////////////
#define CNRM  "\x1B[0m"
#define CRED  "\x1B[31m"
#define CGRN  "\x1B[32m"
#define CYEL  "\x1B[33m"
#define CBLU  "\x1B[34m"
#define CMAG  "\x1B[35m"
#define CCYN  "\x1B[36m"
#define CWHT  "\x1B[37m"
//////////////////////////////////
// END term color codes section //
/////////////////////////////////

// Commands list
typedef enum Commands {
    PCD,
    SAY,
    FINISH,
    INVALID_COMMAND
} Command;

const char *commandsArray[] = {
    "pcd",
    "say",
    "finish"
};

Command get_command_enum(const char* cmd) {
    for (int i = 0; i < INVALID_COMMAND; i++) {
        if (strcmp(cmd, commandsArray[i]) == 0) {
            return i;
        }
    }
    return INVALID_COMMAND;
}

int choose_command(Command cmd) {
    switch (cmd) {
        case PCD:
            printf("printing current directory.\n");
            break;
        case SAY:
            printf("echo.\n");
            break;
        case FINISH:
            printf("Exiting.\n");
            return 1;
        default:
            printf("Nothing happened...\n");
            break;
    };
    return 0;
}

int main() {
    printf("%sYAULS!%s\n", CCYN, CNRM);
    char command[50]; // Fixed-size array to hold the command

    while (true) {
        printf("%s> %s", CMAG, CNRM);
        scanf("%s", command);

        Command cmdEnum = get_command_enum(command);
        if (choose_command(cmdEnum)) {
            break;
        }
    }

    return 0;
}
