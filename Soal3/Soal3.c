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
int main(int argc, char* argv[]) {
    int killT;
    if(strcmp(argv[1],"-z")==0){
        FILE *ptr2 = NULL;
        ptr2 = fopen("Killer.sh","w");
        fputs("#!/bin/bash\nkillall soal3\n rm Killer.sh",ptr2);
        fclose(ptr2);
    }
    while(wait(&killT)>0);
  pid_t pid, sid;        // Variabel untuk menyimpan PID
 
  pid = fork();     // Menyimpan PID dari Child Process
 
  /* Keluar saat fork gagal
  * (nilai variabel pid < 0) */
  if (pid < 0) {
    exit(EXIT_FAILURE);
  }
 
  /* Keluar saat fork berhasil
  * (nilai variabel pid adalah PID dari child process) */
  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }
 
  umask(0);
 
  sid = setsid();
  if (sid < 0) {
    exit(EXIT_FAILURE);
  }
 
  //if ((chdir("/")) < 0) {
  //  exit(EXIT_FAILURE);
  //}
 
 
  //close(STDIN_FILENO);
  //close(STDOUT_FILENO);
  //close(STDERR_FILENO);
    while (1) {
        if(strcmp(argv[1],"-x")==0){ 
            FILE *ptr2 = NULL;
            ptr2 = fopen("Killer.sh","w");
            char kill2[1000];
            sprintf(kill2,"#!/bin/bash\nkill %d\nkill %d\nrm Killer.sh",pid,getpid());
            fputs(kill2,ptr2);
            fclose(ptr2);
        }
        int Tmkdir;
        //printf("AA\n");
        time_t now;
        time(&now);
        struct tm *timern;
        timern = localtime(&now);
        char StrTime[100];
        strftime(StrTime, 100, "%Y-%m-%d_%X", timern);
        char *arg[] = {"mkdir",StrTime,NULL}; 

        pid_t c1 = fork();
        if (c1 < 0) {
          exit(EXIT_FAILURE);
        } 
        if (c1 == 0) {
          execv("/bin/mkdir",arg);
        }
        printf("OTW LURR \n\n\n\n\n");
        while((wait(&Tmkdir))>0);
        pid_t c2 = fork();
        if (c2 < 0) {
          exit(EXIT_FAILURE);
        } 
        if (c2 == 0) {
            // *arg[] = {"chdir",StrTime,Null};
            // execv(/)
            chdir(StrTime);
            int wait1;
            for (int i = 0; i < 10; i++) {
            time_t fnow;
            time(&fnow);
            struct tm *ftimern;
            ftimern = localtime(&fnow);
            char FStrTime[100];
            int epoch = (int)fnow % 1000;
            epoch += 50;
            //printf("%d\n\n\n\n\n",epoch);
            //char link2[4];
            //itoa(epoch,link2,10);
            strftime(FStrTime, 100, "%Y-%m-%d_%X", ftimern);
            char link[100];
            sprintf(link,"https://picsum.photos/%d",epoch);
            printf("%s\n",link);
            pid_t c3 = fork();
            if (c3<0) {
              exit(EXIT_FAILURE);
            }
            if (c3==0) { 
              char *arg[] = {"wget",link,"-O",FStrTime,NULL};
              execv("/usr/bin/wget",arg);
              //printf("%d\n",epoch);
            } 
            sleep(5); 
          }
            while(wait(&wait1)>0);
            char status[] = {"Download Success"};
            for (int i=0; i<strlen(status);i++) {
                status[i]+=5;       
            }
            FILE *ptr = NULL;
            ptr= fopen("Status.txt","w");
            fputs(status, ptr);
            fclose(ptr); 
            chdir("..");
            int wait3;
            pid_t c4 = fork();
            if (c4<0) {
                exit(EXIT_FAILURE);
            }
            if (c4==0) {
                char abc[30];
                strcpy(abc,StrTime);
                strcat(abc,".zip");
                printf("%s\n%s\n\n",StrTime,abc);
                char *arg[] = {"zip",abc,"-r",StrTime,NULL};
                execv("/usr/bin/zip",arg);
            }
            while(wait(&wait3)>0);
            pid_t c7 = fork();
            if (c7<0) {
                exit(EXIT_FAILURE);
            }
            if (c7==0) {
                char *arg[] = {"rm","-r",StrTime,NULL};
                execv("/usr/bin/rm",arg);
            } 
        }
        sleep(40);
    }
}
