#include<stdio.h>
#include<termios.h>
#include<stdlib.h>
#include<unistd.h>
#include<kui_vt100.h>
void err_exit(const char *message)
{
    printf("%s\n",message);
    exit(0);
}

int main()
{
    char *gender[]={"Male","Female","Other"};

    int selected=kui_choice(gender,3,4,4);
    if(selected==-1) printf("Not selected\n");
    else printf("Selected choice : %s\n",gender[selected]);
    return 0;
}
