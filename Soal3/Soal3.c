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
 
  if ((chdir("/")) < 0) {
    exit(EXIT_FAILURE);
  }
 
  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);
  int Tmkdir;
 
    while (1) {
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
        while((wait(&Tmkdir))>0);
        pid_t c2 = fork();
        if (c2 < 0) {
          exit(EXIT_FAILURE);
        } 
        if (c2 == 0) {
          // *arg[] = {"chdir",StrTime,Null};
          // execv(/)
          chdir(StrTime);
          for (int i = 0; i < 10; i++) {
            time_t fnow;
            time(&fnow);
            struct tm *ftimern;
            ftimern = localtime(&fnow);
            char FStrTime[100];
            int epoch = (int)now % 1000;
            epoch += 50;
            //char link2[4];
            //itoa(epoch,link2,10);
            strftime(FStrTime, 100, "%Y-%m-%d_%X", ftimern);
            char link[100] = "https://picsum.photos/";
            *link = sprintf(link,"%d",epoch);
            //strcat(link, link2);
            pid_t c3 = fork();
            if (c3<0) {
              exit(EXIT_FAILURE);
            }
            if (c3==0) { 
              char *arg[] = {"wget",link,"-O",FStrTime,NULL};
              execv("/usr/bin/wget",arg);
            } 
            sleep(5);
          }
        }
    }
}
