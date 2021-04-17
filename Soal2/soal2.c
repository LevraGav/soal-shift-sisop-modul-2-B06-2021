//
//  soal2.c
//  soal2
//
//  Created by Arvel Gavrilla R. 
//  on 15-04-2021
//

#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <sys/wait.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

// Fungsi ini agar tidak perlu melakukan fork berulang kali
void call_function (char execute[], char *variable_path[]) //execute tuh isinya /bin/execute
{ 
    int status; 
    pid_t child_id;
    child_id = fork();

    if(child_id == 0)
    {
        execv(execute, variable_path);
    }

    else
    {
        ((wait(&status))>0);
        return; 
    } 
}

// Untuk melakukan slice pada ekstensi .jpg
char* cut_string_JPG (char*s)
{
    int x;
    int y;

    char* new;

    for (y = 0; s[y] != '\0'; y++);

    // panjang dari string
    x = y - 4 + 1;

    if (x < 1)
        return NULL;

    new = (char*) malloc (x * sizeof(char));

    for (y = 0; y < x - 1; y++)
        new[y] = s[y];

    new[y] = '\0';
    return new;
}

//2a
void Unzip_The_File()
{
    pid_t child_id;

    int status;

    char destination[100] = "/home/arvel/Documents/Praktikum2/Soal2/petshop";

    char source[100] = "/home/arvel/Downloads/pets.zip";

    child_id = fork();

    if (child_id < 0)
    {
        exit(EXIT_FAILURE);
    }

    if(child_id == 0)
    {
        // Membuat folder di lokasi baru
        // -p bertujuan agar tidak perlu melakukan mkdir berkali - kali, contohnya 
        // mkdir -p /home/arvel/Documents/Praktikum2/Soal2/petshop, maka folder praktikum2, soal2, dan petshop
        // akan langsung dibuat secara otomatis
        char *make_folder[] = {"mkdir","-p", destination, NULL};
        call_function("/bin/mkdir", make_folder);

        // Melakukan unzip pets.zip di lokasi folder yang baru
        // .jpg berfungsi untuk hanya meng-unzip file bertipe jpg dan mengabaikan file tipe jenis lain
        char *unzip_file[] = {"unzip", "-q", source, "-d", destination, "*.jpg", NULL};
        call_function("/bin/unzip", unzip_file);
    }

    else
    {
        while ((wait(&status)) > 0);
    }
}

// Fungsi ini untuk menghapus file JPG yng masih ada di folder petshop
// Setelah masing-masing jpg dipindahkan ke folder baru berdasarkan jenis hewannya
void RemoveFiles()
{
    int status;
    
    pid_t child_id;

    child_id = fork();
    
    if(child_id < 0)
    {
        exit(EXIT_FAILURE);
    }

    if(child_id == 0)
    {
        DIR *directory;
        char destination[100] = "/home/arvel/Documents/Praktikum2/Soal2/petshop";
        directory = opendir(destination);
        if(directory != NULL)
        {
            // Melihat isi di dalam folder
            struct dirent *dalam_folder;

            // Membaca directory selama return tidak NULL
            while((dalam_folder = readdir(directory))!=NULL)
            {
                // DT_REG berfungsi untuk mengecek file berdasarkan direktori / foldernya
                if(dalam_folder -> d_type == DT_REG)
                {
                    // Inisiasi source / lokasi yang akan dilakukan operasi remove
                    char source[100] = "/home/arvel/Documents/Praktikum2/Soal2/petshop/";

                    // Menggabungkan nama file di dalam folder dengan source
                    strcat(source, dalam_folder -> d_name);

                    char *remove_images[] = {"remove","-rf", source, NULL};
                    call_function("/bin/rm",remove_images);
                }
            }
        }
    }

    else 
    {
        ((wait(&status)) > 0);
    }
}

// 2B, 2C, 2D
void Make_Folder_And_Rename()
{
    char destination[100]="/home/arvel/Documents/Praktikum2/Soal2/petshop";

    int status;
    
    pid_t child_id;

    child_id = fork();
    
    if(child_id < 0)
    {
        exit(EXIT_FAILURE);
    }

    if(child_id == 0)
    {
        DIR *directory;
        directory=opendir(destination);
        if(directory!=NULL)
        {
            // Melihat isi di dalam folder
            struct dirent *dalam_folder;

            // Membaca directory selama return tidak NULL
            while((dalam_folder = readdir(directory)) != NULL)
            {
                // DT_REG berfungsi untuk mengecek file berdasarkan direktori / foldernya
                if(dalam_folder -> d_type == DT_REG)
                {
                    // Inisiasi Variable
                    int x; 
                    char *Token1, *Token2; 
                    char *Token3, *Token4;
                    char *Nama_File = dalam_folder -> d_name;
                    char *Nama_File_New = cut_string_JPG(Nama_File);

                    char result_1[100];
                    char result_2[100]; 
                    char result_3[100];
                    char variable_path2[100];
                    char variable_path3[100];
                    char Tipe_Hewan[50];
                    char Nama_Hewan[50];
                    char Umur_Hewan[50];

                    // Melakukan pengecekan
                    // Nama File berdasarkan tanda "_" dan ";"
                    for(Token1 = strtok_r(Nama_File_New, "_", &Token3); Token1!=NULL; Token1=strtok_r(NULL, "_", &Token3))
                    {
                        x = 0;
                        char variable_path[99]="/home/arvel/Documents/Praktikum2/Soal2/petshop/";
                        char txt_location[100]; 
                        char txt_path[100];
                        char Nama_Hewan_in_txt[100];
                        char data_txt[100];

                        strcpy(result_1, Nama_File);
                        strcpy(variable_path2, variable_path);
                        strcpy(variable_path3, variable_path);
                        strcpy(result_2, Nama_File);
                        strcpy(result_3, Nama_File);
                        for(Token2 = strtok_r(Token1, ";", &Token4); Token2 != NULL; Token2 = strtok_r(NULL, ";", &Token4))
                        {
                            if(x==0)strcpy(Tipe_Hewan, Token2);
                            if(x==1)strcpy(Nama_Hewan, Token2);
                            if(x==2)strcpy(Umur_Hewan, Token2);
                            x++;
                        }  

                        // 2B
                        // Membuat Folder berdasarkan jenis hewan
                        strcat(variable_path, Tipe_Hewan);
                        char *Make_Folder[] = {"mkdir", "-p", variable_path, NULL};
                        call_function("/bin/mkdir", Make_Folder);

                        // Melakukan copy variable path ke variable txt_path
                        strcpy(txt_path, variable_path);
                        
                        // Melakukan copy nama hewan ke variable 
                        strcpy(Nama_Hewan_in_txt, Nama_Hewan); 

                        // 2C
                        // Memindahkan (Mengcopy) file ke direktori baru
                        strcat(Nama_Hewan, ".jpg");
                        strcat(variable_path2, result_2);

                        char *Copy_Folder[] = {"cp", variable_path2, variable_path, NULL};
                        call_function("/bin/cp", Copy_Folder);

                        // Melakukan rename nama File dengan nama hewannya
                        strcpy(variable_path3, variable_path);
                        strcat(variable_path3, "/");

                        strcat(variable_path3, result_2);
                        strcat(variable_path, "/");
                        
                        strcat(variable_path, Nama_Hewan);

                        char *rename_image_file[] = {"rename_image_file", variable_path3, variable_path, NULL};
                        call_function("/bin/mv", rename_image_file);

                        // 2E 
                        // Membuat file keterangan.txt
                        // Membuat file keterangan.txt di lokasi variable_path yang sudah dicopy ke txt_path
                        strcat(txt_path, "/keterangan.txt"); 

                        // mengcopy "nama : " ke variable data_txt
                        strcpy(data_txt, "nama : ");

                        // menggabungkan data nama hewan dengan "nama : "
                        strcat(data_txt, Nama_Hewan_in_txt);

                        // menggabungkan ] "umur : " dengan ariable data_txt
                        strcat(data_txt, "\numur : ");

                        // menggabungkan data umur hewan dengan "umur : "
                        strcat(data_txt, Umur_Hewan);

                        // menambahkan kata tahun di belakang data umur
                        strcat(data_txt, "tahun\n\n");

                        FILE *make_txt = fopen(txt_path, "a");
                        fputs(data_txt, make_txt);
                        fclose(make_txt);
                    }
                }
            }
        }
    }

    else
    {
        ((wait(&status))>0);
    }
}

// void keterangantxt()
// {
//     char destination[100]="/home/arvel/Documents/Praktikum2/Soal2/petshop";

//     int status;
    
//     pid_t child_id;
//     child_id = fork();
    
//     if(child_id < 0)
//         {
//         exit(EXIT_FAILURE);
//         }

//     if(child_id == 0)
//     {
//         DIR *directory;
//         directory=opendir(destination);
//         if(directory!=NULL)
//         {
//             // Melihat isi di dalam folder
//             struct dirent *dalam_folder;
            
//             // Membaca directory selama return tidak NULL
//             while((dalam_folder=readdir(directory))!=NULL)
//             {
//                 // DT_REG berfungsi untuk mengecek file berdasarkan direktori / foldernya
//                 if(dalam_folder -> d_type == DT_REG)
//                 {
//                     int x; 
//                     char *Token1, *Token2, *Token3, *Token4;
//                     char *Nama_File = dalam_folder->d_name;
//                     char *Nama_File_New = cut_string_JPG(Nama_File);

//                     char result_1[100], result_2[100], result_3[100];
//                     char variable_path2[99], variable_path3[99];
//                     char Tipe_Hewan[30], Nama_Hewan[30], Umur_Hewan[30];

//                     for(Token1=strtok_r(Nama_File_New, "_", &Token3); Token1!=NULL; Token1=strtok_r(NULL, "_", &Token3))
//                     {
//                         x = 0;
//                         char variable_path[99]="/home/arvel/Documents/Praktikum2/Soal2/petshop/";
//                         strcpy(result_1, Nama_File);
//                         strcpy(variable_path2, variable_path);
//                         strcpy(variable_path3, variable_path);
//                         strcpy(result_2, Nama_File);
//                         strcpy(result_3, Nama_File);

//                         //2e keterangan.txt
//                         char  txt_location[99], txt_path[99];
//                         strcpy(txt_location, variable_path);
//                         stpcpy(txt_path, txt_location);

//                         char Nama_Hewan_in_txt[100], data_txt[100];
//                         strcpy(Nama_Hewan_in_txt,Nama_Hewan); 

//                         strcat(txt_path, "/keterangan.txt");
//                         strcpy(data_txt, "nama : ");
//                         strcat(data_txt, Nama_Hewan_in_txt);
//                         strcat(data_txt, "\numur : ");
//                         strcat(data_txt, Umur_Hewan);
//                         strcat(data_txt, "tahun\x\x");
                    
//                         FILE *source = fopen(txt_path, "a");
//                         fputs(data_txt, source);
//                         fclose(source);                        
//                     }                
//                 }
//             }
//             closedir(directory);
//         }
//     }

//     else
//     {
//         ((wait(&status))>0);
//     }
// }

int main()
{
    int status;
    pid_t child_id;
    child_id = fork();

    if(child_id < 0)
    {
        exit(EXIT_FAILURE);
    }

    if(child_id == 0)
    {
        Unzip_The_File();
        Make_Folder_And_Rename();
        RemoveFiles();
        // keterangantxt();
    }

    else 
    {
        ((wait(&status)) > 0);
    }
}
