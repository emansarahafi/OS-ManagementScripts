//Task 2 by Eman Sarah Afi (A00051) & Yousef Elsonbaty (A00138)

#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
    //Variables to get the system's current time
    time_t systemCurrentTime;
    time(&systemCurrentTime);
    
    //Parent process to print the day of the week
    printf("Today's Day of the Week is: %.3s\n", ctime(&systemCurrentTime));
    
    //Child process to print the full date
    if(fork() == 0)
    {
        printf("Today's Date : %.*s ", 6, ctime(&systemCurrentTime) + 4);
        printf("%.*s\n", 4, ctime(&systemCurrentTime) + 20);
    }

return 0;
}

