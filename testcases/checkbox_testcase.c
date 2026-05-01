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
    char *hobbies[]={"Cricket","Badminton","Movies","Reading","Swimming","Cooking"};
    int size;
    int index;
    int *x=kui_checkbox(hobbies,6,4,5,4,6,15,&size);
    if(x==NULL) printf("Nothing selected\n");
    else
    {
        printf("Selected options are : \n");
        for(int e=0;e<size;e++)
        {
            index=x[e];
            printf("%s\n",hobbies[index]);
        }
    }
    free(x); // important

    return 0;
}
