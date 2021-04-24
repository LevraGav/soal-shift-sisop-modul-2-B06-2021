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
- [Jawaban Soal 1]()
- [Jawaban Soal 2](https://github.com/LevraGav/soal-shift-sisop-modul-2-B06-2021/tree/main/Soal2)
- [Jawaban Soal 3](https://github.com/LevraGav/soal-shift-sisop-modul-2-B06-2021/tree/main/Soal3)

# --- No 1 ---
Pada suatu masa, hiduplah seorang Steven yang hidupnya pas-pasan. Steven punya pacar, namun sudah putus sebelum pacaran. Ketika dia galau memikirkan mantan, ia selalu menonton https://www.youtube.com/watch?v=568DH_9CMKI untuk menghilangkan kesedihannya. 

Di lain hal Steven anak yang tidak amat sangat super membenci matkul sisop, beberapa jam setelah diputus oleh pacarnya dia menemukan wanita lain bernama Stevany, namun Stevany berkebalikan dengan Steven karena menyukai sisop. Steven ingin terlihat jago matkul sisop demi menarik perhatian Stevany.

Pada hari ulang tahun Stevany, Steven ingin memberikan Stevany zip berisikan hal-hal yang disukai Stevany. Steven ingin isi zipnya menjadi rapi dengan membuat folder masing-masing sesuai extensi. (a) Dikarenakan Stevany sangat menyukai huruf Y, Steven ingin nama folder-foldernya adalah Musyik untuk mp3, Fylm untuk mp4, dan Pyoto untuk jpg (b) untuk musik Steven mendownloadnya dari link di bawah, film dari link di bawah lagi, dan foto dari link dibawah juga :). (c) Steven tidak ingin isi folder yang dibuatnya berisikan zip, sehingga perlu meng-extract-nya setelah didownload serta (d) memindahkannya ke dalam folder yang telah dibuat (hanya file yang dimasukkan).

(e) Untuk memudahkan Steven, ia ingin semua hal di atas berjalan otomatis 6 jam sebelum waktu ulang tahun Stevany). (f) Setelah itu pada waktu ulang tahunnya Stevany, semua folder akan di zip dengan nama Lopyu_Stevany.zip dan semua folder akan di delete(sehingga hanya menyisakan .zip).
Kemudian Steven meminta bantuanmu yang memang sudah jago sisop untuk membantunya mendapatkan hati Stevany. Bantu Woy!!

### Note
- Ulang Tahun Stevany : 09 April Pukul 22.22 WIB
- Semua poin dijalankan oleh 1 script di latar belakang, termasuk mendownload file zip-nya. Jadi cukup jalankan script 1x serta ubah time dan date untuk check hasilnya.
```
Preview :
https://drive.google.com/drive/folders/1NzRiPPoVlR_H8P51cxN4jaceeFQGk4un
*tontonnya 720p biar jelas.. ಠ‿ಠ
```
- <b>Tidak boleh</b> menggunakan fungsi system(), mkdir(), dan rename() (Yang di bahasa C) .... FORBIDDENNN!!
- <b>Tidak boleh</b> pake <b>cron</b> !!!
- Menggunakan fork dan exec.
- Link
```
Foto :
https://drive.google.com/file/d/1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD/view
Musik :
https://drive.google.com/file/d/1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J/view
Film : 
https://drive.google.com/file/d/1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp/view
```
### Tips
- Gunakan fungsi wait() dan sleep() untuk memperlancarrr..
- untuk mendownload zip yang dibutuhkan bisa menggunakan command :
```
wget --no-check-certificate "https://drive.google.com/uc?id=ID-FILE&export=download" -O Nama_untuk_filenya.ext
```
- contoh
```
Wget --no-check-certificate "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download" -O Musik_for_Stevany.zip
```
## Pengerjaan

## Penjelasan

## Permasalahan

# --- No 2 ---
Loba bekerja di sebuah petshop terkenal, suatu saat dia mendapatkan zip yang berisi banyak sekali foto peliharaan dan Ia diperintahkan untuk mengkategorikan foto-foto peliharaan tersebut. Loba merasa kesusahan melakukan pekerjaanya secara manual, apalagi ada kemungkinan ia akan diperintahkan untuk melakukan hal yang sama. Kamu adalah teman baik Loba dan Ia meminta bantuanmu untuk membantu pekerjaannya.

Loba sangat mengapresiasi bantuanmu, minggu depan ia akan mentraktir makan malam!

### Note
- Setiap data peliharaan disimpan sebagai nama foto dengan format [jenis peliharaan]:[nama peliharaan]:[umur peliharaan dalam tahun]. Jika terdapat lebih dari satu peliharaan, data dipisahkan menggunakan underscore(_).
- Tidak boleh menggunakan fungsi system(), mkdir(), dan rename().
- Menggunakan fork dan exec.

## 2A
Pertama-tama program perlu mengextract zip yang diberikan ke dalam folder “/home/[user]/modul2/petshop”. Karena bos Loba teledor, dalam zip tersebut bisa berisi folder-folder yang tidak penting, maka program harus bisa membedakan file dan folder sehingga dapat memproses file yang seharusnya dikerjakan dan menghapus folder-folder yang tidak dibutuhkan.

### Pengerjaan

### Penjelasan

## 2B
Foto peliharaan perlu dikategorikan sesuai jenis peliharaan, maka kamu harus membuat folder untuk setiap jenis peliharaan yang ada dalam zip. Karena kamu tidak mungkin memeriksa satu-persatu, maka program harus membuatkan folder-folder yang dibutuhkan sesuai dengan isi zip.
Contoh: Jenis peliharaan kucing akan disimpan dalam ```/petshop/cat```, jenis peliharaan kura-kura akan disimpan dalam ```/petshop/turtle```.

### Pengerjaan

### Penjelasan

## 2C
Setelah folder kategori berhasil dibuat, programmu akan memindahkan foto ke folder dengan kategori yang sesuai dan di rename dengan nama peliharaan.
Contoh: ```/petshop/cat/joni.jpg```. 

### Pengerjaan

### Penjelasan

## 2D
Karena dalam satu foto bisa terdapat lebih dari satu peliharaan maka foto harus di pindah ke masing-masing kategori yang sesuai. Contoh: foto dengan nama ```dog;baro;1_cat;joni;2.jpg``` dipindah ke folder ```/petshop/cat/joni.jpg” dan “/petshop/dog/baro.jpg```.

### Pengerjaan

### Penjelasan

## 2E
Di setiap folder buatlah sebuah file ```keterangan.txt``` yang berisi <b>nama</b> dan <b>umur semua peliharaan</b> dalam folder tersebut. Format harus sesuai contoh.
```
nama : joni
umur  : 3 tahun

nama : miko
umur  : 2 tahun
```
### Pengerjaan

### Penjelasan

# --- No 3 ---
Ranora adalah mahasiswa Teknik Informatika yang saat ini sedang menjalani magang di perusahan ternama yang bernama “FakeKos Corp.”, perusahaan yang bergerak dibidang keamanan data. Karena Ranora masih magang, maka beban tugasnya tidak sebesar beban tugas pekerja tetap perusahaan. Di hari pertama Ranora bekerja, pembimbing magang Ranora memberi tugas pertamanya untuk membuat sebuah program.

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
Setelah direktori telah terisi dengan 10 gambar, program tersebut akan membuat sebuah file ```status.txt```, dimana didalamnya berisi pesan ```Download Success``` yang terenkripsi dengan teknik Caesar Cipher dan dengan shift 5. Caesar Cipher adalah Teknik enkripsi sederhana yang dimana dapat melakukan enkripsi string sesuai dengan shift/key yang kita tentukan. Misal huruf “A” akan dienkripsi dengan shift 4 maka akan menjadi “E”. Karena Ranora orangnya perfeksionis dan rapi, dia ingin setelah file tersebut dibuat, direktori akan di zip dan direktori akan didelete, sehingga menyisakan hanya file zip saja.

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
Untuk mempermudah pengendalian program, pembimbing magang Ranora ingin program tersebut akan men-generate sebuah program “Killer” yang executable, dimana program tersebut akan menterminasi semua proses program yang sedang berjalan dan akan menghapus dirinya sendiri setelah program dijalankan. Karena Ranora menyukai sesuatu hal yang baru, maka Ranora memiliki ide untuk program “Killer” yang dibuat nantinya harus merupakan <b>program bash</b>.

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


