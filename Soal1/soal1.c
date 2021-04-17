#include <string.h>
#include <stdio.h>
#include <wait.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>
#include <unistd.h>

time_t my_time;
struct tm * timeinfo; 

int persiapan(){
    int hour = 16;

    time (&my_time);
    timeinfo = localtime (&my_time);
    if(timeinfo->tm_mday == 9 && timeinfo->tm_mon+1 == 4 && timeinfo->tm_hour == hour && timeinfo->tm_min == 22){
        return 1;
    }
    return 0;
}

int lopyu(){
    int hour = 22;

    time (&my_time);
    timeinfo = localtime (&my_time);
    if(timeinfo->tm_mday == 9 && timeinfo->tm_mon+1 == 4 && timeinfo->tm_hour == hour && timeinfo->tm_min == 22){
        return 1;
    }
    return 0;
}

void mkfolder(){
    pid_t id_anak;

    id_anak = fork();
    if (id_anak == 0){
        char *argv[] = {"mkdir", "-p", "Pyoto", NULL};
        execv("/bin/mkdir", argv);
    }else{
        id_anak = fork();
        if (id_anak == 0){
            char *argv[] = {"mkdir", "-p", "Fylm", NULL};
            execv("/bin/mkdir", argv);
        }else{
            char *argv[] = {"mkdir", "-p", "Musyik", NULL};
            execv("/bin/mkdir", argv);
        }
    }
}

void unduh(){
    pid_t id_anak;

    id_anak = fork();
    if (id_anak == 0){
        char *argv[] = {"wget", "-q", "--no-check-certificate", "https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download", "-O", "Foto_for_Stevany.zip", NULL};
        execv("/usr/bin/wget", argv);
    }else{
        id_anak = fork();
        if (id_anak == 0){
            char *argv[] = {"wget", "-q", "--no-check-certificate", "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download", "-O", "Film_for_Stevany.zip", NULL};
            execv("/usr/bin/wget", argv);
        }else{
            char *argv[] = {"wget", "-q", "--no-check-certificate", "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", "-O", "Musik_for_Stevany.zip", NULL};
            execv("/usr/bin/wget", argv);
        }
    }
}

void kulitmanggis(){
    pid_t id_anak;

    id_anak = fork();
    if (id_anak == 0){
        char *argv[] = {"unzip", "-qq", "Foto_for_Stevany.zip", "-d", "/home/nor/sisop/shift2/", NULL};
        execv("/usr/bin/unzip", argv);
    }else{
        id_anak = fork();
        if (id_anak == 0){
            char *argv[] = {"unzip", "-qq", "Film_for_Stevany.zip", "-d", "/home/nor/sisop/shift2/", NULL};
            execv("/usr/bin/unzip", argv);
        }else{
            char *argv[] = {"unzip", "-qq", "Musik_for_Stevany.zip", "-d", "/home/nor/sisop/shift2/", NULL};
            execv("/usr/bin/unzip", argv);
        }
    }
}

void salin(){
    pid_t id_anak;

    id_anak = fork();
    if (id_anak == 0){
        char *argv[] = {"cp", "-r", "FOTO/.", "Pyoto/", NULL};
        execv("/bin/cp", argv);
    }else{
        id_anak = fork();
        if (id_anak == 0){
            char *argv[] = {"cp", "-r", "FILM/.", "Fylm/", NULL};
            execv("/bin/cp", argv);
        }else{
            char *argv[] = {"cp", "-r", "MUSIK/.", "Musyik/", NULL};
            execv("/bin/cp", argv);
        }
    }
}

void hapus(){
    pid_t id_anak;

    id_anak = fork();
    if (id_anak == 0){
        char *argv[] = {"rm", "-r", "/home/nor/sisop/shift2/FOTO", NULL};
        execv("/bin/rm", argv);
    }else{
        id_anak = fork();
        if (id_anak == 0){
            char *argv[] = {"rm", "-r", "/home/nor/sisop/shift2/FILM", NULL};
            execv("/bin/rm", argv);
        }else{
            char *argv[] = {"rm", "-r", "/home/nor/sisop/shift2/MUSIK", NULL};
            execv("/bin/rm", argv);
        }
    }
}

void hbd(){
    pid_t id_anak;

    id_anak = fork();
    if (id_anak == 0){
        id_anak = fork();
        if (id_anak == 0){
            id_anak = fork();
            if (id_anak == 0){
                id_anak = fork();
                if (id_anak == 0){
                    id_anak = fork();
                    if (id_anak == 0){}
                    else{
                        char *argv[] = {"zip", "-qr", "Lopyu_Stevany.zip", "Pyoto", "Fylm", "Musyik", NULL};
                        execv("/usr/bin/zip", argv);
                    }
                }else{
                    sleep(5);
                    char *argv[] = {"rm", "-r", "/home/nor/sisop/shift2/Pyoto", NULL};
                    execv("/bin/rm", argv);
                }
            }else{
                sleep(5);
                char *argv[] = {"rm", "-r", "/home/nor/sisop/shift2/Fylm", NULL};
                execv("/bin/rm", argv);
            }
        }else{
            sleep(5);
            char *argv[] = {"rm", "-r", "/home/nor/sisop/shift2/Musyik", NULL};
            execv("/bin/rm", argv);
        }
    }
}

void tminus6(){
    pid_t id_anak;
    // id_anak = fork();
    // int status;
    // if (id_anak == 0){
        id_anak = fork();
        int status;
        if (id_anak == 0){
            id_anak = fork();
            int status;
            if (id_anak == 0){
                id_anak = fork();
                int status;
                if (id_anak == 0){
                    id_anak = fork();
                    if (id_anak == 0){
                        mkfolder();
                    }else{
                        unduh();
                    }
                }else{
                    while(wait(&status) > 0);
                    sleep(5); //5 sec
                    kulitmanggis();
                }
            }else{
                while(wait(&status)>0);
                sleep(5);
                salin();
            }
        }else{
            while(wait(&status)>0);
            sleep(5);
            hapus();
        }
    // }else{
    //     while(wait(&status)>0);
    //     sleep(21600);
    //     hbd();
    // }
}

int main(){
    int terunduh=0, terzip=0;

    pid_t pid, sid;
    pid = fork();

    if(pid < 0) exit(EXIT_FAILURE);
    if(pid > 0) exit(EXIT_SUCCESS);

    umask(0);

    sid=setsid();

    // if ((chdir("/home/nor/sisop/shift2")) < 0) {
    //     exit(EXIT_FAILURE);
    // }
    // if(sid < 0) exit(EXIT_FAILURE);
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    while(1){
        if(persiapan() && terunduh==0){
            tminus6();
            terunduh=1;
        }
        if(lopyu() && terzip==0){
            hbd();
            terzip=1;
        }
        sleep(1);
    }
}
