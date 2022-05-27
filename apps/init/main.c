#include "../../lib/lib.h"

int main(int argc, char **argv)
{
    int32_t pid = fork();

    if(pid == 0)
        exec("CONSOLE.BIN");
    else
        waitu(pid);

    return 0;
}