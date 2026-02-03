# C-Banking-Simulation
# ATM Management System in C

## 🇹🇷 
Bu proje, C programlama dili ile geliştirilmiş, verileri `txt` dosyalarında saklayan bir ATM simülasyonudur.

### 🚀 Özellikler
* **Giriş Sistemi:** Hesap numarası ve şifre ile doğrulama.
* **İşlemler:** Para çekme (banknot kontrollü), yatırma, transfer ve şifre güncelleme.
* **Veri Yönetimi:** Kullanıcı bilgileri (`musteri.txt`) ve kasa durumu (`kasa.txt`) üzerinden anlık güncelleme.

### 📂 Dosya Yapısı
* **musteri.txt:** `İsim Soyisim;HesapNo;Şifre;Bakiye`
* **kasa.txt:** `50TL_Adedi;100TL_Adedi;200TL_Adedi`
* # C-Banking-Simulation
# ATM Management System in C

## 🛠️ Kurulum ve Çalıştırma

1. C derleyicinizin (GCC, MinGW vb.) kurulu olduğundan emin olun.
2. `musteri.txt` ve `kasa.txt` dosyalarının kod dosyasıyla aynı klasörde olduğunu kontrol edin.
3. Terminal veya IDE üzerinden projeyi derleyin ve çalıştırın:
   bash 
   gcc main.c -o atm_projesi
   ./atm_projesi

## 🇺🇸 
This project is an ATM simulation developed in C, utilizing `txt` files for data storage and management.

### 🚀 Features
* **Login System:** Secure authentication using account numbers and passwords.
* **Transactions:** Withdrawals (with banknote availability checks), deposits, transfers, and password updates.
* **Data Management:** Real-time synchronization of user data (`musteri.txt`) and ATM vault status (`kasa.txt`).

### 📂 File Structure
* **musteri.txt:** `Name Surname;AccountNo;Password;Balance`
* **kasa.txt:** `Count_50TL;Count_100TL;Count_200TL`

##🛠️ Setup and Execution | Kurulum ve Çalıştırma
Ensure a C compiler (GCC, MinGW, etc.) is installed on your system. 

Verify that musteri.txt and kasa.txt are in the same directory as the source code. 

Compile and run the project via terminal or IDE: 

bash
gcc main.c -o atm_system
./atm_system



