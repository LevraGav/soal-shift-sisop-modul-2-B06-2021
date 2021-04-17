#define _POSIX_SOURCE
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int signals = 1;

void orphan(int signum) {
    signals =0;
}

int main(int argc, char *argv[]) {
    if (strcmp(argv[1], "-z") == 0)
    {
        FILE *ptr2 = NULL;
        ptr2 = fopen("Killer.sh", "w");
        fputs("#!/bin/bash\nkillall soal3\n rm Killer.sh", ptr2);
        fclose(ptr2);
    }
    if (strcmp(argv[1], "-x") == 0)
    {
        FILE *ptr2 = NULL;
        ptr2 = fopen("Killer.sh", "w");
        fputs("#!/bin/bash\nkillall -15 soal3\n rm Killer.sh", ptr2);
        fclose(ptr2);
        signal(SIGTERM, orphan);
    }
    pid_t pid, sid
    pid = fork();
    if (pid < 0)
    {
        exit(EXIT_FAILURE);
    }
    if (pid > 0)
    {
        exit(EXIT_SUCCESS);
    }
    umask(0);
    sid = setsid();
    if (sid < 0)
    {
        exit(EXIT_FAILURE);
    }
    while (signals) {
        time_t now;
        time(&now);
        struct tm *timern;
        timern = localtime(&now);
        char StrTime[100];
        strftime(StrTime, 100, "%Y-%m-%d_%X", timern);
        if (fork()==0) {
            char *arg[] = {"mkdir", StrTime, NULL};
            execv("/bin/mkdir", arg);
        }
        sleep(1);

        if (fork()==0) {
            chdir(StrTime);
            for (int i = 0;i<10;i++) {
                time_t fnow;
                time(&fnow);
                struct tm ftimern;
                ftimern = *localtime(&fnow);
                ftimern.tm_sec -= 1;
                mktime(&ftimern);
                char FStrTime[100];
                int epoch = (int)fnow % 1000;
                epoch += 50;
                strftime(FStrTime, 100, "%Y-%m-%d_%X", &ftimern);
                char link[100];
                sprintf(link, "https://picsum.photos/%d", epoch);
                if (fork()==0) {
                    char *arg[] = {"wget", link, "-O", FStrTime, NULL};
                    execv("/usr/bin/wget", arg);
                }
                sleep(5);
            }
            char status[] = {"Download Success"};
            for (int i = 0; i < strlen(status); i++)
            {
                if (status[i] != 32){
                    status[i] += 5;
                    if (status[i] > 90 && status[i] < 97){
                        status[i] -= 26;
                    }
                    if (status[i] > 122){
                        status[i] -= 26;
                    }
                }
            }
            FILE *ptr = NULL;
            ptr = fopen("Status.txt", "w");
            fputs(status, ptr);
            fclose(ptr);
            chdir("..");
            if (fork()==0)
            {
                char abc[30];
                strcpy(abc, StrTime);
                strcat(abc, ".zip");
                //printf("%s\n%s\n\n",StrTime,abc);
                char *arg[] = {"zip", abc, "-rm", StrTime, NULL};
                execv("/usr/bin/zip", arg);
            }
        }
        sleep(39);
    }   
}
