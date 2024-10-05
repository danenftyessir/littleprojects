#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    int num_heroes, i, j, valid_input;
    int total_matches[5], wins_needed[5], total_after[5];
    float current_winrate[5], target_winrate[5], current_wins[5];
    char hero_name[5][50], input_buffer[50];
    printf("============================================================\n");
    printf("|        KALKULATOR WIN RATE HERO MOBILE LEGENDS            |\n");
    printf("============================================================\n");
    printf("|              Hitung jumlah pertandingan untuk             |\n");
    printf("|                  mencapai target win rate                 |\n");
    printf("============================================================\n");
    printf("| Jumlah hero yang akan dihitung (1-5): ");
    scanf("%d", &num_heroes);
    getchar(); 
    if (num_heroes < 1 || num_heroes > 5) num_heroes = 1;
    for (i = 0; i < num_heroes; i++) {
        printf("------------------------------------------------------------\n");
        do {
            printf("| Nama Hero %d                    : ", i + 1);
            fgets(input_buffer, sizeof(input_buffer), stdin);
            input_buffer[strcspn(input_buffer, "\n")] = 0; 
            if (strlen(input_buffer) == 0) {
                printf("| Input tidak boleh kosong. Silakan coba lagi.         |\n");
                continue;
            }
            valid_input = 1;
            for (j = 0; j < i; j++) {
                if (strcmp(input_buffer, hero_name[j]) == 0) {
                    printf("| Hero sudah ada. Masukkan nama hero yang berbeda.    |\n");
                    valid_input = 0;
                    break;
                }
            }
        } while (!valid_input);
        strcpy(hero_name[i], input_buffer);
        do {
            printf("| Total Pertandingan Hero %d      : ", i + 1);
            if (scanf("%d", &total_matches[i]) != 1 || total_matches[i] < 0) {
                printf("| Input tidak valid. Masukkan angka non-negatif.       |\n");
                while (getchar() != '\n'); 
                continue;
            }
            break;
        } while (1);

        do {
            printf("| Win Rate Saat Ini Hero %d (%%)    : ", i + 1);
            if (scanf("%f", &current_winrate[i]) != 1 || current_winrate[i] < 0 || current_winrate[i] > 100) {
                printf("| Input tidak valid. Masukkan angka antara 0 dan 100.  |\n");
                while (getchar() != '\n'); 
                continue;
            }
            break;
        } while (1);
        do {
            printf("| Target Win Rate Hero %d (%%)      : ", i + 1);
            if (scanf("%f", &target_winrate[i]) != 1 || target_winrate[i] < 0 || target_winrate[i] > 100) {
                printf("| Input tidak valid. Masukkan angka antara 0 dan 100.  |\n");
                while (getchar() != '\n');
                continue;
            }
            break;
        } while (1);
        getchar();
    }
    printf("============================================================\n");
    printf("|                     HASIL PERHITUNGAN                     |\n");
    printf("============================================================\n");
    for (i = 0; i < num_heroes; i++) {
        printf("| Hero: %-52s |\n", hero_name[i]);
        if (target_winrate[i] <= 0 || target_winrate[i] > 100) {
            printf("| Target win rate tidak valid. Harus di antara 0%% dan 100%%. |\n");
        } else if (current_winrate[i] > target_winrate[i]) {
            printf("| Anda sudah mencapai target win rate.                    |\n");
            printf("| Win rate saat ini: %.2f%%                                |\n", current_winrate[i]);
        } else if (total_matches[i] == 0 && current_winrate[i] == 0 && target_winrate[i] > 0) {
            printf("| Anda perlu memenangkan 1 pertandingan untuk mencapai    |\n");
            printf("| win rate %.2f%%.                                         |\n", target_winrate[i]);
        } else {
            current_wins[i] = current_winrate[i] * total_matches[i] / 100;
            wins_needed[i] = ceil((target_winrate[i] * (total_matches[i] + 1) - 100 * current_wins[i]) / (100 - target_winrate[i])) - 1;
            total_after[i] = total_matches[i] + wins_needed[i];
            if (wins_needed[i] < 0) {
                printf("| Anda sudah mencapai target win rate.                    |\n");
                printf("| Win rate saat ini: %.2f%%                                |\n", current_winrate[i]);
            } else {
                printf("| Anda perlu menang %d pertandingan lagi Tanpa KEKALAHAN! |\n", wins_needed[i]);
                printf("| Total pertandingan: %-39d |\n", total_after[i]);
            }
        }
        printf("------------------------------------------------------------\n");
    }
    return 0;
}