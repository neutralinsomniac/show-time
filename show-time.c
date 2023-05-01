#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

volatile int quit;

void handle_sigint(int sig)
{
    quit = 1;
}

int main()
{
    time_t rawtime;
    time_t oldtime = 0;
    struct tm *timeinfo;

    quit = 0;

    signal(SIGINT, handle_sigint);

    printf("\033[2J");
    while(quit == 0) {
        time(&rawtime);
        if (oldtime != rawtime) {
            timeinfo = localtime(&rawtime);
            printf("\033[0;0H%s", asctime(timeinfo));
            oldtime = rawtime;
        }
        usleep(10);
    }

    return 0;
}
