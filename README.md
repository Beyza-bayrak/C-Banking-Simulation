# C-Banking-Simulation
# ATM Management System in C

## 🇹🇷 Türkçe Sürüm

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

## 🇺🇸 English Version

This project is an ATM simulation developed in C, utilizing `txt` files for data storage and management.

### 🚀 Features
* **Login System:** Secure authentication using account numbers and passwords.
* **Transactions:** Withdrawals (with banknote availability checks), deposits, transfers, and password updates.
* **Data Management:** Real-time synchronization of user data (`musteri.txt`) and ATM vault status (`kasa.txt`).

### 📂 File Structure
* **musteri.txt:** `Name Surname;AccountNo;Password;Balance`
* **kasa.txt:** `Count_50TL;Count_100TL;Count_200TL`



### 🛠️ Kurulum /installation
```bash
gcc main.c -o atm_project
./atm_project




