# soal-shift-sisop-modul-2-B06-2021
Laporan Penyelesaian Pengerjaan Soal Praktikum SISOP Modul 1 - Kelompok B06

# Anggota Kelompok
Anggota  | NRP
---------|-------
Faisal Reza Maulana | 05111940000009
Arvel Gavrilla R. | 05111940000040
Bayu Adjie Sidharta | 05111940000172

## Link-link
- [Soal](https://docs.google.com/document/d/121ZqwL7KXiKy3YpQgP6INuYlb4969WOj1GlZ9umO65w/edit)
- [Jawaban Soal 1](https://github.com/LevraGav/soal-shift-sisop-modul-2-B06-2021/tree/main/Soal1)
- [Jawaban Soal 2](https://github.com/LevraGav/soal-shift-sisop-modul-2-B06-2021/tree/main/Soal2)
- [Jawaban Soal 3](https://github.com/LevraGav/soal-shift-sisop-modul-2-B06-2021/tree/main/Soal3)

# --- No 1 ---
Pada suatu masa, hiduplah seorang Steven yang hidupnya pas-pasan. Steven punya pacar, namun sudah putus sebelum pacaran. Ketika dia galau memikirkan mantan, ia selalu menonton https://www.youtube.com/watch?v=568DH_9CMKI untuk menghilangkan kesedihannya. 

Di lain hal Steven anak yang tidak amat sangat super membenci matkul sisop, beberapa jam setelah diputus oleh pacarnya dia menemukan wanita lain bernama Stevany, namun Stevany berkebalikan dengan Steven karena menyukai sisop. Steven ingin terlihat jago matkul sisop demi menarik perhatian Stevany.

### Pendahuluan
Kami membuat sebuah fungsi untuk mengeksekusi command agar tidak perlu menulis fungsi berkali-kali.

```c
void execute(char **args){
    int pid = fork();
    int status;
    if(pid == 0){
        execvp(args[0], args);
    }

    while(wait(&status) > 0);
}
```

## 1A
Dikarenakan Stevany sangat menyukai huruf Y, Steven ingin nama folder-foldernya adalah Musyik untuk mp3, Fylm untuk mp4, dan Pyoto untuk jpg

### Pengerjaan
```c
char *foldery[3] = {"Musyik/", "Pyoto/", "Fylm/"};
for(int i=0; i<3; i++){
    char *args[] = {"mkdir", foldery[i], NULL};
    execute(args);
}
```
### Penjelasan
Deklarasikan nama-nama folder yang akan dibuat ke sebuah array. Lalu buat sebuah loop. Dalam loop tersebut ada variabel yang berisi argumen-argumen yang akan diberikan ke fungsi execute. Argumen tersebut adalah "mkdir" untuk membuat folder, nama folder yang akan dibuat, dan NULL.

## 1B
untuk musik Steven mendownloadnya dari link di bawah, film dari link di bawah lagi, dan foto dari link dibawah juga :)

### Pengerjaan
```c
char *link[3] = {"https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download", "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download"};
    char *nama_terunduh[3] = {"Musik_for_Stevany.zip","Film_for_Stevany.zip","Foto_for_Stevany.zip"};
for(int i=0; i<3; i++){
    if(fork() == 0){
        char *argv[] = {"wget", "-q","--no-check-certificate", link[i], "-O", nama_terunduh[i], NULL};
        execv("/usr/bin/wget", argv);
    }
}
```

### Penjelasan
Deklarasikan link file-file yang akan diunduh dan nama file yang diinginkan ke dua buah array. Lalu buat sebuah loop. Dalam loop tersebut ada variabel yang berisi argumen-argumen yang akan diberikan ke fungsi execv. Argumen tersebut adalah "wget" untuk mengunduh file, parameter-parameter sesuai dengan soal agar bisa mengunduh dari GDrive, link file, nama yang diinginkan, dan NULL.

## 1C
Steven tidak ingin isi folder yang dibuatnya berisikan zip, sehingga perlu meng-extract-nya setelah didownload serta 

### Pengerjaan
```c
for(int i=0; i<3; i++){
    int status;
    pid_t pid = wait(&status);
    waitpid(pid, &status, WUNTRACED);
}

for(int i=0; i<3; i++){
    if(fork() == 0){
        char *argv[] = {"unzip", "-q", nama_terunduh[i], "-d", "", NULL};
        execv("/usr/bin/unzip", argv);
    }
}
```

### Penjelasan
Buat sebuah for loop yang akan menunggu setiap fork dari fungsi nomor sebelumnya selesai. Lalu jika sudah selesai, buat sebuah loop yang akan mengunzip tiga file yang sudah terunduh dengan cara yang sama seperti nomor sebelumnya.

## 1D
memindahkannya ke dalam folder yang telah dibuat (hanya file yang dimasukkan).

### Pengerjaan
```c
char working_dir[] = "/home/nor/sisop/shift2/";

for(int i=0; i<3; i++){
    int status;
    pid_t pid = wait(&status);
    waitpid(pid, &status, WUNTRACED);
}

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
```

### Penjelasan
Buat variabel working_dir tempat script berada. Buat sebuah for loop yang akan menunggu setiap fork dari fungsi nomor sebelumnya selesai. Lalu jika sudah selesai, buat for loop untuk setiap nama folder. Di dalamnya ada while loop yang mengecek isi folder, selama belum kosong, dia akan mengambil nama file yang akan dipindahkan, dan direktori di mana file tersebut ingin dipindahkan, lalu dimasukkan ke argumen bersama dengan command "mv". Argumen tersebut lalu diberikan ke fungsi execute.

## 1E
Untuk memudahkan Steven, ia ingin semua hal di atas berjalan otomatis 6 jam sebelum waktu ulang tahun Stevany)

### Pengerjaan
```c
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

int terunduh=0, terzip=0;

while(1){
	if(cektanggal(1) && terunduh==0){
		//soal a-e
		terunduh=1;
	}
	
	sleep(1);
}
```

### Penjelasan
Dibuat fungsi cek tanggal untuk mengecek tanggal dan jam. Fungsi tersebut menerima input persiapan, jika persiapan = 1, maka jam yang akan dicek adalam jam 16. Lalu waktu komputer dimasukkan ke variabel timeinfo. Lalu tanggal, bulan (+1 karena bulan mulai dari 0), jam, menit diekstrak dari timeinfo lalu dicek dengan tanggal ultah Stevany, jika sama, maka fungsi akan me-return nilai 1. Jika tidak maka akan mereturn 0.

Dibuat variabel terunduh dan terzip, lalu dibuat while true loop yang didalamnya ada if yang akan mengecek jika tanggal sudah benar dan file belum terunduh. Jika kondisi memenuhi, soal a-e akan dijalankan, lalu variable terunduh di-set jadi 1 agar file tidak terunduh lagi. Lalu juga ada fungsi sleep yang membuat pengecekan dilakukan tiap detik.

### Output (kondisi awal/ kondisi akhir)
![ss479 2021 04 23 6685](https://user-images.githubusercontent.com/11045113/115997974-4eb2e800-a60f-11eb-95f3-f69e57902587.png)
![ss479 2021 04 23 6686](https://user-images.githubusercontent.com/11045113/115997959-465aad00-a60f-11eb-9dc3-15724a59f41b.png)

## 1F
Setelah itu pada waktu ulang tahunnya Stevany, semua folder akan di zip dengan nama Lopyu_Stevany.zip dan semua folder akan di delete(sehingga hanya menyisakan .zip).

### Pengerjaan
```c
if(cektanggal(0) && terzip==0){
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
```

### Penjelasan
Dalam while true loop yang sama, ada fungsi yang menjalankan nomor f. Jika kondisi sudah memenuhi, akan dijalankan perintah untuk men-zip tiga foldery ke dalam zip Lopyu_Stevany, lalu meremove tiga foldery dan tiga folderbold, lalu mengubah variabel terzip jadi 1.

Lalu ada if lagi yang mengecek apakah terunduh dan terzip sudah 1, jika ya, maka while true loop akan keluar dan process akan mati.

### Output
![ss479 2021 04 23 6687](https://user-images.githubusercontent.com/11045113/115997939-30e58300-a60f-11eb-9de4-4ff3f4ad6b9b.png)

## Kendala
- wget awalnya tidak bisa jalan karena dikira pathnya ada di /bin/wget/ padahal sebenarnya di /usr/bin/wget/

# --- No 2 ---
Loba bekerja di sebuah petshop terkenal, suatu saat dia mendapatkan zip yang berisi banyak sekali foto peliharaan dan Ia diperintahkan untuk mengkategorikan foto-foto peliharaan tersebut. Loba merasa kesusahan melakukan pekerjaanya secara manual, apalagi ada kemungkinan ia akan diperintahkan untuk melakukan hal yang sama. Kamu adalah teman baik Loba dan Ia meminta bantuanmu untuk membantu pekerjaannya.

Loba sangat mengapresiasi bantuanmu, minggu depan ia akan mentraktir makan malam!

### Note
- Setiap data peliharaan disimpan sebagai nama foto dengan format [jenis peliharaan]:[nama peliharaan]:[umur peliharaan dalam tahun]. Jika terdapat lebih dari satu peliharaan, data dipisahkan menggunakan underscore(_).
- Tidak boleh menggunakan fungsi system(), mkdir(), dan rename().
- Menggunakan fork dan exec.

### Pendahuluan
Pertama - tama kami membuat sebuah fungsi terlebih dahulu, dimana fungsi ini sendiri berfungsi agar setiap kami melakukan eksekusi program dengan execv maka kami tidak perlu melakukan deklarasi ```fork()``` berulang kali. Hal ini juga bertujuan untuk membuat kodingan lebih rapi dan bersih.
```bash
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
```

### Source File (ZIP)
![Source File](https://user-images.githubusercontent.com/72689610/115994283-86fefa00-a600-11eb-903d-90302eec56d3.png)

## 2A
Pertama-tama program perlu mengextract zip yang diberikan ke dalam folder ???/home/[user]/modul2/petshop???. Karena bos Loba teledor, dalam zip tersebut bisa berisi folder-folder yang tidak penting, maka program harus bisa membedakan file dan folder sehingga dapat memproses file yang seharusnya dikerjakan dan menghapus folder-folder yang tidak dibutuhkan.

### Pengerjaan
```bash
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
```

### Penjelasan
```bash
// Membuat folder di lokasi baru
        // -p bertujuan agar tidak perlu melakukan mkdir berkali - kali, contohnya 
        // mkdir -p /home/arvel/Documents/Praktikum2/Soal2/petshop, maka folder praktikum2, soal2, dan petshop
        // akan langsung dibuat secara otomatis
        char *make_folder[] = {"mkdir","-p", destination, NULL};
        call_function("/bin/mkdir", make_folder);
```
Fungsi diatas berfungsi untuk membuat sebuah folder di lokasi / direktori baru, pertama - tama kami menggunakan sebuah variable pointer untuk menampung data - data di dalam sebuah array, yaitu berupa ```mkdir``` (penamaan perintah), penggunaan ```-p``` (parent) untuk membuat parent directory jika dibutuhkan, dan ```destination``` (deklarasi lokasi pembuatan folder dan nama folder). Kemudian semua data di dalam array tadi akan dieksekusi dengan menggunakan fungsi ```call_function``` yang sudah di deklarasikan di awal kodingan.

```bash
// Melakukan unzip pets.zip di lokasi folder yang baru
        // .jpg berfungsi untuk hanya meng-unzip file bertipe jpg dan mengabaikan file tipe jenis lain
        char *unzip_file[] = {"unzip", "-q", source, "-d", destination, "*.jpg", NULL};
        call_function("/bin/unzip", unzip_file);
```
Hampir sama dengan fungsi sebelumnya. Fungsi diatas bertujuan untuk melakukan ekstrak terhadap sebuah file bertipe zip di sebuah direktori untuk kemudian hasil ekstraknya akan disimpan di direktori tertentu. Dengan menggunakan variable pointer untuk menyimpan data - data di dalam sebuah array, yaitu berupa ```unzip``` (penamaan perintah), penggunaan ```-q``` (agar saat program dieksekusi tidak memenuhi terminal), ```source``` (sumber atau lokasi tempat file zip yang akan diekstrak), penggunaan ```-d``` (untuk merujuk ke direktori tertentu), ```destination``` (deklarasi direktori / lokasi tempat hasil ekstrak akan disimpan), dan penggunaan ```.jpg``` (agar file yang diekstrak hanya file yang bertipe JPG). Kemudian semua data di dalam array tadi akan dieksekusi dengan menggunakan fungsi ```call_function``` yang sudah di deklarasikan di awal kodingan.

### Output
![Output No 2A 1](https://user-images.githubusercontent.com/72689610/115994224-456e4f00-a600-11eb-85bd-e2dd56240d5c.png)
![Output Soal 2A](https://user-images.githubusercontent.com/72689610/115994122-e14b8b00-a5ff-11eb-8d7a-065078b58ca3.png)

### Pendahuluan 2B, 2C, dan 2D
Fungsi di bawah ini berfungsi untuk melakukan pemotongan (menghilangkan) ekstensi .jpg dari setiap nama file yang ada di dalam folder
```bash
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
```
Melakukan pemisahan nama file hewan berdasarkan ```_``` (jika 1 nama file mengandung 2 hewan) dan ```;``` (berdasarkan atribut hewan mulai dari jenis, nama, dan umurnya). Dengan menggunakan ```strtok_r``` maka looping pertama berfungsi untuk melakukan pemisahan string nama file berdasarkan ```_```, kemudian pada looping kedua untuk setiap iterasi pembacaan string nama file berdasarkan ```;``` maka akan dilakukan penyimpanan data atribut hewan ke dalam array tertentu.
```bash
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
```
String nama file terdiri dari 3 komponen, yaitu jenis, nama, dan umur hewan.
- Untuk ```x==0``` maka data jenis hewan akan disimpan di dalam array Tipe_Hewan
- Untuk ```x==1``` maka data nama hewan akan disimpan di dalam array Nama_Hewan
- Untuk ```x==2``` maka data umur hewan akan disimpan di dalam array Umur_Hewan

```bash
for(Token2 = strtok_r(Token1, ";", &Token4); Token2 != NULL; Token2 = strtok_r(NULL, ";", &Token4))
{
  if(x==0)strcpy(Tipe_Hewan, Token2);
  if(x==1)strcpy(Nama_Hewan, Token2);
  if(x==2)strcpy(Umur_Hewan, Token2);
  x++;
}  
```

## 2B
Foto peliharaan perlu dikategorikan sesuai jenis peliharaan, maka kamu harus membuat folder untuk setiap jenis peliharaan yang ada dalam zip. Karena kamu tidak mungkin memeriksa satu-persatu, maka program harus membuatkan folder-folder yang dibutuhkan sesuai dengan isi zip.
Contoh: Jenis peliharaan kucing akan disimpan dalam ```/petshop/cat```, jenis peliharaan kura-kura akan disimpan dalam ```/petshop/turtle```.

### Pengerjaan
```bash
 // 2B
// Membuat Folder berdasarkan jenis hewan
strcat(variable_path, Tipe_Hewan);
char *Make_Folder[] = {"mkdir", "-p", variable_path, NULL};
call_function("/bin/mkdir", Make_Folder);
```

### Penjelasan
```bash
strcat(variable_path, Tipe_Hewan);
```
Setelah melakukan pemisahan string nama file, maka data jenis hewan yang disimpan di dalam array ```Tipe_Hewan``` bisa digunakan untuk membuat folder / directory baru. Caranya adalah dengan menambahkan data jenis hewan di dalam array ```Tipe_Hewan``` ke dalam array ```variable_path``` yang berisi data path folder ```petshop``` yang sudah dibuat di soal 2A.  

```bash
char *Make_Folder[] = {"mkdir", "-p", variable_path, NULL};
call_function("/bin/mkdir", Make_Folder);
```
Dengan sebuah variable pointer untuk menampung data - data di dalam sebuah array, yaitu berupa ```mkdir``` (penamaan perintah), penggunaan ```-p``` (parent) untuk membuat parent directory jika dibutuhkan, dan ```variable_path``` (deklarasi path folder petshop). Kemudian semua data di dalam array tadi akan dieksekusi dengan menggunakan fungsi ```call_function``` yang sudah di deklarasikan di awal kodingan.

### Output
![Output Soal 2C](https://user-images.githubusercontent.com/72689610/115994329-c62d4b00-a600-11eb-89b0-9baa4d75c321.png)

## 2C dan 2D
Setelah folder kategori berhasil dibuat, programmu akan memindahkan foto ke folder dengan kategori yang sesuai dan di rename dengan nama peliharaan.
Contoh: ```/petshop/cat/joni.jpg```. 

Karena dalam satu foto bisa terdapat lebih dari satu peliharaan maka foto harus di pindah ke masing-masing kategori yang sesuai. Contoh: foto dengan nama ```dog;baro;1_cat;joni;2.jpg``` dipindah ke folder ```/petshop/cat/joni.jpg??? dan ???/petshop/dog/baro.jpg```.

### Pengerjaan
```bash
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
```

### Penjelasan
Untuk memindahkan file foto ke dalam masing - masing folder sesuai dengan kategori jenis hewannya, kami menggunakan fungsi ```cp``` untuk menyalin file ke destination baru. Disini variable ```result_2``` berisi data nama tiap file yang kemudian akan digabungkan dengan variable ```variable_path2``` yang berisi path folder petshop agar setiap file bisa dilakukan ```copy``` menuju path setiap folder.
```bash
strcat(variable_path2, result_2);

char *Copy_Folder[] = {"cp", variable_path2, variable_path, NULL};
call_function("/bin/cp", Copy_Folder);
```
Fungsi bagian di bawah ini adalah melakukan rename nama setiap file. Karena array ```Nama_Hewan``` berisi data nama hewan maka nantinya setiap data ini akan digabungkan dengan ekstensi ```.jpg``` dan dijadikan sebagai path baru untuk file sebelumnya yang akan dipindah.
```bash
// Melakukan rename nama File dengan nama hewannya
strcat(Nama_Hewan, ".jpg");
strcpy(variable_path3, variable_path);
strcat(variable_path3, "/");

strcat(variable_path3, result_2);
strcat(variable_path, "/");
                        
strcat(variable_path, Nama_Hewan);

char *rename_image_file[] = {"rename_image_file", variable_path3, variable_path, NULL};
call_function("/bin/mv", rename_image_file);
```
Karena kami menggunakan fungsi ```cp``` atau copy, maka tentu akan ada file duplikat yang tertinggal di folder petshop utama. Untuk menghilangkan file duplikat tersebut maka kami menggunakan fungsi dibawah ini :
```bash
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
```

### Output
![Output Soal 2D](https://user-images.githubusercontent.com/72689610/115994334-c9283b80-a600-11eb-981c-70b7bc4190e6.png)

## 2E
Di setiap folder buatlah sebuah file ```keterangan.txt``` yang berisi <b>nama</b> dan <b>umur semua peliharaan</b> dalam folder tersebut. Format harus sesuai contoh.
```
nama : joni
umur  : 3 tahun

nama : miko
umur  : 2 tahun
```
### Pengerjaan
```bash
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
```

### Penjelasan
Pertama kami membuat sebuah path baru dengan nama ```/keterangan.txt```, kemudian digabungkan ke dalam variable ```txt_path``` yang berisi data path folder petshop. Kemudian kami menggunakan kombinasi antara ```strcpy``` dan ```strcat``` untuk memasukkan data ke dalam ```keterangan.txt``` agar sesuai dengan format soal. Dengan menggunakan variable pointer ```*make_txt``` untuk membuka dan melakukan ```append``` isi data dari variable ```data_txt``` ke dalam ```txt_path```. Jika semua data sudah di ```append```, maka file akan ditutup kembali.

### Output
![Output Soal No 2E](https://user-images.githubusercontent.com/72689610/115994393-f96fda00-a600-11eb-9bb7-6838a7652258.png)

## Kendala
Tidak ada kendala dalam pengerjaan soal ini

# --- No 3 ---
Ranora adalah mahasiswa Teknik Informatika yang saat ini sedang menjalani magang di perusahan ternama yang bernama ???FakeKos Corp.???, perusahaan yang bergerak dibidang keamanan data. Karena Ranora masih magang, maka beban tugasnya tidak sebesar beban tugas pekerja tetap perusahaan. Di hari pertama Ranora bekerja, pembimbing magang Ranora memberi tugas pertamanya untuk membuat sebuah program.

Ranora meminta bantuanmu untuk membantunya dalam membuat program tersebut. Karena kamu anak baik dan rajin menabung, bantulah Ranora dalam membuat program tersebut!

### Note
- Tidak boleh menggunakan system() dan mkdir()
- <b>Program utama</b> merupakan <b>SEBUAH PROGRAM C</b>
- <b>Wajib</b> memuat algoritma Caesar Cipher pada program utama yang dibuat

## 3A
Ranora harus membuat sebuah program C yang dimana setiap 40 detik membuat sebuah direktori dengan nama sesuai timestamp [YYYY-mm-dd_HH:ii:ss].

### Pengerjaan
```bash
while(signals) {
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
  if(fork()==0) {
  ...
  }
  sleep(39);
}
```
### Penjelasan
Setelah pembuatan daemon, kita mengambil waktu sekarang dengan fungsi time(), lalu diconvert ke local time dan diparse menjadi suatu string menggunaakn function strftime.
String tersebut lalu dipass ke array of char untuk dijadikan argument. Lalu kita dapat menggunakan fork dan execv untuk memanggil function mkdir dan mempassing argumen tersebut agar file terbuat dengan baik.
![image](https://user-images.githubusercontent.com/31591861/115103061-0fcec380-9f79-11eb-951a-c2b1bc570d1c.png)

## 3B
Setiap direktori yang sudah dibuat diisi dengan 10 gambar yang didownload dari ```https://picsum.photos/```, dimana setiap gambar akan didownload setiap 5 detik. Setiap gambar yang didownload akan diberi nama dengan format timestamp ```[YYYY-mm-dd_HH:ii:ss]``` dan gambar tersebut berbentuk persegi dengan ukuran (n%1000) + 50 pixel dimana n adalah detik Epoch Unix.

### Pengerjaan
```bash
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
```
### Penjelasan
Pertama-tama, menggunakan metode yang sama seperti yang diatas, kita mengambil waktu untuk dijadikan nama file, lalu mengambil epoch saat itu dan ditambah 50 untuk dijadikan resolusi file tersebut. Untuk mendownload file tersebut, kita membutuhkan link untuk download sendiri. Hal ini dapat didapatkan dengan menaruh epoch tadi ke belakang "https://picsum.photos/" dengan menggunakan sprintf(). Lalu kita fork agar menjadi proses baru lalu lakukan wget dengan argumen link yang tadi sudah dibuat dan -O agar ter-rename ke nama file yang baru dibuat.

![image](https://user-images.githubusercontent.com/31591861/115103399-c3d14e00-9f7b-11eb-96fc-6ab35a7e9b02.png)

## 3C
Setelah direktori telah terisi dengan 10 gambar, program tersebut akan membuat sebuah file ```status.txt```, dimana didalamnya berisi pesan ```Download Success``` yang terenkripsi dengan teknik Caesar Cipher dan dengan shift 5. Caesar Cipher adalah Teknik enkripsi sederhana yang dimana dapat melakukan enkripsi string sesuai dengan shift/key yang kita tentukan. Misal huruf ???A??? akan dienkripsi dengan shift 4 maka akan menjadi ???E???. Karena Ranora orangnya perfeksionis dan rapi, dia ingin setelah file tersebut dibuat, direktori akan di zip dan direktori akan didelete, sehingga menyisakan hanya file zip saja.

### Pengerjaan
 ```bash
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
  char abc[30];
  strcpy(abc, StrTime);
  strcat(abc, ".zip");
  //printf("%s\n%s\n\n",StrTime,abc);
  char *arg[] = {"zip", abc, "-rm", StrTime, NULL};
  execv("/usr/bin/zip", arg);
 }
 ```
### Penjelasan
Lalu setelah mendownload, kita lakukan wait agar yakin program telah sepenuhnya selesai. karena kita perlu membuat sebuah file yang bernama "status.txt", sebelumnya kita perlu tahu cara membuat caesar cipher. Cara gampang membuat caesar cipher hanyalah menambah ascii dari alphabet dan jika terlewat dari alphabet, kita wrap around awal lagi
setelah itu, kita dapat membuat status.txt via fopen(), lalu write cipher tadi menggunakan fputs() lalu close file tersebut agar terwrite.
![image](https://user-images.githubusercontent.com/31591861/115103813-f3358a00-9f7e-11eb-966b-a4117700336f.png)
lalu kita change directory keluar folder tersebut lalu dengan execv menzip dengan nama folder yang sama. Lalu kita wait agar kita yakin selesai lalu dapat di RM -r folder lama tersebut.

![image](https://user-images.githubusercontent.com/31591861/115105162-55928880-9f87-11eb-82b7-3e91b59f27a5.png)

![image](https://user-images.githubusercontent.com/31591861/115105166-5f1bf080-9f87-11eb-9dbc-5b4efbe367a3.png)


## 3D
Untuk mempermudah pengendalian program, pembimbing magang Ranora ingin program tersebut akan men-generate sebuah program ???Killer??? yang executable, dimana program tersebut akan menterminasi semua proses program yang sedang berjalan dan akan menghapus dirinya sendiri setelah program dijalankan. Karena Ranora menyukai sesuatu hal yang baru, maka Ranora memiliki ide untuk program ???Killer??? yang dibuat nantinya harus merupakan <b>program bash</b>.

### Pengerjaan
```bash
FILE *ptr2 = NULL;
      ptr2 = fopen("Killer.sh", "w");
      fputs("#!/bin/bash\nkillall soal3\n rm Killer.sh", ptr2);
      fclose(ptr2);
```

### Penjelasan
Setelah semua selesai dilakukan, program akan membuat sebuah bash script untuk membunuh daemon, hal tersebut dapat dilakukan dengan menggunakan killall karena kita tau nama process tersebut.
![image](https://user-images.githubusercontent.com/31591861/115952054-3a3af680-a50e-11eb-8b48-b9fd9a677f77.png)


## 3E
Pembimbing magang Ranora juga ingin nantinya program utama yang dibuat Ranora dapat dijalankan di dalam dua mode. Untuk mengaktifkan mode pertama, program harus dijalankan dengan argumen -z, dan Ketika dijalankan dalam mode pertama, program utama akan langsung menghentikan semua operasinya Ketika program Killer dijalankan. Sedangkan untuk mengaktifkan mode kedua, program harus dijalankan dengan argumen -x, dan Ketika dijalankan dalam mode kedua, program utama akan berhenti namun membiarkan proses di setiap direktori yang masih berjalan hingga selesai (Direktori yang sudah dibuat akan mendownload gambar sampai selesai dan membuat file txt, lalu zip dan delete direktori).

### Pengerjaan
```bash
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
```
### Penjelasan
Kita akan mengcompare argumen yang dimasukan ke dalam untuk mengetahui tipe killer yang mana yang dibuat. Jika -z, kita akan menggunakan killer yang lama (soal 3d) dan jika argumen yang diterima adalah -x, kita akan memberikan sinyal sigterm dalam killall. Jika program mendengar sinyal sigterm, while loop nya akan dijadikan 0 agar menahan kasus dimana sigterm sendiri tidak berhasil untuk menghentikan process.

![image](https://user-images.githubusercontent.com/31591861/115952055-3c9d5080-a50e-11eb-87fc-87d8f8c911fe.png)
![image](https://user-images.githubusercontent.com/31591861/115952079-59398880-a50e-11eb-995a-27b906cc0e9a.png)


