# 📒 Phonebook GUI App (C++)

## 📌 Deskripsi Aplikasi
Judul Projek: Aplikasi Phonebook Manager Berbasis GUI Menggunakan Konsep Pemrograman Berorientasi Objek (OOP) dalam C++ 

Aplikasi ini adalah Phonebook berbasis GUI yang memungkinkan pengguna untuk:
- Menambahkan kontak baru
- Mengedit kontak
- Menghapus kontak
- Melihat semua kontak
- Mencari kontak berdasarkan nama
- Menyimpan kontak ke file
- Memuat kontak dari file

Format file input:
```
Nama Panjang
Nama Panggilan
Nomor Telepon
Email
Alamat

```

Contoh:
```
Budi Santoso
Budi
081234567890
budi.santoso@example.com
Jl. Malioboro No. 1, Yogyakarta
```

---

## 👥 Anggota Project (NIM | Nama)
- 25/556848/TK/62818 | Kayyisa Nur Lathifa
- 25/557140/TK/62874 | Muhammad Yusuf Akbar 
- 25/562156/TK/63542 | Nida Nur Hafizhah


---

## ▶️ Cara Menjalankan Project
1. Pastikan Anda memiliki compiler C++ (contoh: `g++`) dan berada dalam folder PhonebokAppTrial (ketik `cd PhonebookAppTrial` pada terminal) 
2. Compile program:
   ```bash
   g++ main.cpp Person.cpp PhonebookManager.cpp imgui/imgui.cpp imgui/imgui_draw.cpp imgui/imgui_tables.cpp       imgui/imgui_widgets.cpp imgui/backends/imgui_impl_glfw.cpp imgui/backends/imgui_impl_opengl3.cpp -Iimgui -Iimgui/backends -Iglfw/include -Lglfw/lib -lglfw3 -lopengl32 -lgdi32 -o PhonebookManager.exe
   ```
3. Jalankan program:
   ```bash
   ./PhonebookManager.exe
   ```
4. Pastikan file `input.txt` tersedia untuk fitur Load from File.
5. File `output.txt` terupdate setelah menggunakan fitur  Save to a File
6. Untuk penggunaan selanjutnya, pastikan copy-paste kontak dari `output.txt` ke `input.txt` agar data terbaru dapat digunakan kembali.

---

## 💾 File Pendukung
- `input.txt` → berisi data kontak awal
- `output.txt` → file untuk menyimpan kontak setelah dijalankan

---
