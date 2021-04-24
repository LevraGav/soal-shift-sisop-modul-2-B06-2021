#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
#include <wait.h>
#include <dirent.h>

time_t my_time;
struct tm * timeinfo; 

int cektanggal(int persiapan){
    int hour = 22;
    if(persiapan == 1) hour = 22-6;

    time (&my_time);
    timeinfo = localtime (&my_time);
    if(timeinfo->tm_mday == 9 && timeinfo->tm_mon+1 == 4 && timeinfo->tm_hour == hour && timeinfo->tm_min == 22){
        return 1;
    }
    return 0;
}

void execute(char **args){
    int pid = fork();
    int status;
    if(pid == 0){
        execvp(args[0], args);
    }

    while(wait(&status) > 0);
}

int main(){
    char *foldery[3] = {"Musyik/", "Pyoto/", "Fylm/"};
    char *folderbold[3] = {"MUSIK/", "FOTO/", "FILM/"};
    char *link[3] = {"https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download", "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download"};
    char *nama_terunduh[3] = {"Musik_for_Stevany.zip","Film_for_Stevany.zip","Foto_for_Stevany.zip"};
    char working_dir[] = "/home/nor/sisop/shift2/";

    int terunduh=0, terzip=0;

    pid_t pid, sid;
    pid = fork();

    if(pid < 0) exit(EXIT_FAILURE);
    if(pid > 0) exit(EXIT_SUCCESS);

    umask(0);

    sid=setsid();
    if(sid < 0) exit(EXIT_FAILURE);
    if((chdir("/home/nor/sisop/shift2")) < 0) exit(EXIT_FAILURE);

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    while(1){
        if(cektanggal(1) && terunduh==0){ // e
            // a
            for(int i=0; i<3; i++){
                char *args[] = {"mkdir", foldery[i], NULL};
                execute(args);
            }

            // b
            for(int i=0; i<3; i++){
                if(fork() == 0){
                    char *argv[] = {"wget", "-q","--no-check-certificate", link[i], "-O", nama_terunduh[i], NULL};
                    execv("/usr/bin/wget", argv);
                }
            }

            // tunggu b selesai
            for(int i=0; i<3; i++){
                int status;
                pid_t pid = wait(&status);
                waitpid(pid, &status, WUNTRACED);
            }

            // c
            for(int i=0; i<3; i++){
                if(fork() == 0){
                    char *argv[] = {"unzip", "-q", nama_terunduh[i], "-d", "", NULL};
                    execv("/usr/bin/unzip", argv);
                }
            }

            // tunggu c selesai
            for(int i=0; i<3; i++){
                int status;
                pid_t pid = wait(&status);
                waitpid(pid, &status, WUNTRACED);
            }

            // d
            for(int i=0; i<3; i++){
                DIR *dp;
                struct dirent *ep;
                char curr_dir[100]; sprintf(curr_dir, "%s%s", working_dir, folderbold[i]);
                char move_dir[100]; sprintf(move_dir, "%s%s", working_dir, foldery[i]);
                dp = opendir(curr_dir);

                if(dp != NULL){
                    while((ep = readdir(dp))){
                        if(strcmp(ep->d_name, ".") != 0 || strcmp(ep->d_name, "..") != 0){
                            char file_to_move[355]; sprintf(file_to_move, "%s%s", curr_dir, ep->d_name);
                            char file_move_to[355]; sprintf(file_move_to, "%s%s", move_dir, ep->d_name);
                            char *args[] = {"mv", file_to_move, file_move_to, NULL};
                            execute(args);
                        }
                    }
                }
            }

            terunduh=1;
        }
        
        if(cektanggal(0) && terzip==0){
            // f

            if(1){
                char *args[] = { "zip", "-r", "Lopyu_Stevany", foldery[0], foldery[1], foldery[2], NULL };
                execute(args);
            }

            if(1){
                char *args[] = {"rm", "-rf", foldery[0], foldery[1], foldery[2], folderbold[0], folderbold[1], folderbold[2], NULL};
                execute(args);
            }

            terzip=1;
        }
        
        if(terunduh && terzip){
            exit(EXIT_FAILURE);
        }
        sleep(1);
    }
    return 0;
}
