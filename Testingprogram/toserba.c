#include <stdio.h>

int main() {
    int pilihan, jumlah;
    float total, diskon = 0.0;
    printf("=====================================\n");
    printf("||       Selamat Datang di         ||\n");
    printf("||          Toko Serba Ada         ||\n");
    printf("=====================================\n\n");
    
    // Daftar Produk
    printf("Silakan pilih produk yang ingin Anda beli:\n");
    printf("1. Buku     - Rp 25.000\n");
    printf("2. Pensil   - Rp 3.000\n");
    printf("3. Penghapus- Rp 2.000\n");
    printf("4. Pulpen   - Rp 5.000\n");
    printf("-------------------------------------\n");
    printf("Masukkan nomor produk pilihan Anda (1-4): ");
    scanf("%d", &pilihan);    
    printf("Masukkan jumlah barang yang ingin dibeli: ");
    scanf("%d", &jumlah);
    if (pilihan == 1) {
        total = 25000 * jumlah;
        printf("\nAnda memilih Buku, total harga: Rp %.2f\n", total);
        if (jumlah >= 10) {
            diskon = total * 0.1;  // Diskon 10% jika beli >= 10 buku
        }
    } else if (pilihan == 2) {
        total = 3000 * jumlah;
        printf("\nAnda memilih Pensil, total harga: Rp %.2f\n", total);
        if (jumlah >= 20) {
            diskon = total * 0.15;  // Diskon 15% jika beli >= 20 pensil
        }
    } else if (pilihan == 3) {
        total = 2000 * jumlah;
        printf("\nAnda memilih Penghapus, total harga: Rp %.2f\n", total);
        if (jumlah >= 15) {
            diskon = total * 0.1;  // Diskon 10% jika beli >= 15 penghapus
        }
    } else if (pilihan == 4) {
        total = 5000 * jumlah;
        printf("\nAnda memilih Pulpen, total harga: Rp %.2f\n", total);
        if (jumlah >= 5) {
            diskon = total * 0.05;  // Diskon 5% jika beli >= 5 pulpen
        }
    } else {
        printf("\nPilihan tidak valid. Silakan jalankan program lagi.\n");
        return 0;
    }

    if (diskon > 0) {
        printf("Selamat! Anda mendapatkan diskon sebesar Rp %.2f\n", diskon);
    }
    
    total = total - diskon;
    printf("-------------------------------------\n");
    printf("Total yang harus dibayar: Rp %.2f\n", total);
    printf("=====================================\n");
    printf("||  Terima kasih telah berbelanja!  ||\n");
    printf("||      Sampai jumpa kembali!       ||\n");
    printf("=====================================\n");
    
    return 0;
}
