#include <stdio.h>

int main() {
    int dizi[] = { 10, 20, 20 ,10 ,10 ,20 ,5 ,20 };
    int n = sizeof(dizi) / sizeof(dizi[0]);

    int elemanlar[10];
    int adet[10];
    int sayac = 0;
    for (int i = 0; i < n; i++) {
        int eleman = dizi[i];
        int j;
        for (j = 0; j < sayac; j++) {
            if (elemanlar[j] == eleman) {
                adet[j]++;
                break;
            }
        }
        if (j == sayac) {
            elemanlar[sayac] = eleman;
            adet[sayac] = 1;
            sayac++;
        }
    }

    for (int i = 0; i < sayac; i++) {
        printf("%d -> %d\n", elemanlar[i], adet[i]);
    }

    return 0;
}
