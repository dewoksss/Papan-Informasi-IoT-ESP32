Papan Informasi Otomatis Berbasis LCD dan Blynk
Proyek ini adalah sistem papan informasi digital yang memungkinkan pengiriman pesan teks secara real-time dari aplikasi smartphone ke layar LCD melalui platform IoT Blynk. Sistem ini dirancang sebagai solusi efisien untuk penyampaian informasi di lingkungan kampus atau perkantoran.

Fitur Utama
Konektivitas IoT: Menggunakan ESP32 untuk komunikasi data via Wi-Fi dengan server Blynk.

Tampilan Dual-Mode:

> Mode Standby: Menampilkan jam digital real-time yang disinkronkan dengan modul RTC DS1307.

> Mode Informasi: Menampilkan pesan teks yang dikirim oleh pengguna melalui aplikasi Blynk.

> Animasi Scrolling: Pesan panjang otomatis berjalan (scrolling) di layar LCD agar seluruh informasi dapat terbaca.

> Manajemen Otomatis: Pesan akan muncul selama 30 detik sebelum sistem secara otomatis kembali ke tampilan jam (kembali ke mode standby).

Komponen yang Digunakan
Mikrokontroler ESP32 DevKit V1

1. LCD 16x2 dengan Modul I2C

2. Modul RTC DS1307

3. Platform Blynk IoT

Cara Penggunaan
Pastikan ESP32 terhubung ke jaringan Wi-Fi yang aktif.

1. Buka aplikasi Blynk di smartphone dan kirim pesan melalui DataStream yang sesuai (V0).

2. Pesan akan langsung muncul dan tampil di baris kedua LCD.

3. Setelah 3 Menit, LCD akan otomatis kembali menampilkan jam.
