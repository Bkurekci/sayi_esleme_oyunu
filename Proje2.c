#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 15 // kullan�lacak max sayi

typedef struct t_ID{
    char username[MAX];
    int score;
}gamerID;

void readFromFile(int matris[][MAX], char *fileName)
{
    int i, j, temp;
    FILE *data = fopen(fileName, "r");
    if (!data)
    {
        printf("Dosya Acilamadi!");
        return;
    }
    while (!feof(data)) // matris duzenleme islemi burada yapiliyor
    {
        fscanf(data, "%d %d %d\n", &i, &j, &temp); // i j konum temp icerik
        matris[i][j] = temp;
    }
    fclose(data);
    // Buraya kadar olan bolumde dosyadan okuma yapiliyor. Kodu degistirmeyiniz.
}

/* Matrisi ekrana yazdirma fonksiyonu
 * Bu fonksiyonu yapiyi bozmayacak sekilde degistirebilirsiniz.
 */
void drawBoard(int matris[][MAX], int N)
{
    int i, j, k;
    for (i = 0; i < N; i++)
    {
        printf("\n");
        for (k = 0; k < N; k++)
            printf("-------");
        printf("\n");
        for (j = 0; j < N; j++)
            if (matris[i][j] != 0)
                printf("  %d   |", matris[i][j]);
            else
                printf("      |");// matris[i][j]);
    }
}
// txt olarak verilen matrisin buyuklugunu hesaplar
int filematris(char *file)
{
    FILE *dosya = fopen(file, "r");
    if (dosya == NULL) {
        printf("Dosya açma hatası!");
        return 0;
    }

    int enBuyuk = 0;
    int satir, sutun, sayi;

    while (fscanf(dosya, "%d %d %d", &satir, &sutun, &sayi) != EOF)
    {
        if (satir > enBuyuk)
            enBuyuk = satir;

        if (sutun > enBuyuk)
            enBuyuk = sutun;
    }
    fclose(dosya);
    return enBuyuk + 1;
}
// alinan N degerine gore matris olusturur

void dosyadanMatrisOlustur(int **tab)
{
    int secim;
    //dosyadan cekilip matris olusturuluyor sonrasinda oyun stiline gore matris o fonksiyona ataniyor oyun orada devam ediyor
    while(1)
    {
        printf("1. Manuel Modda Oyna:\n");
        printf("2. Otomatik Modda Oyna:\n");
        printf("3. Ana Menuye Don\n");
        printf("Seciminizi yapiniz: ");
        scanf("%d", &secim);

        switch(secim)
        {
            case 1:
                manuelmode();//koordinatlar elle girilecek o sekilde ilerleyecek
                break;
            case 2:
                automode();//otomatik pathfinder adim adim eslestirecek(sanirim)
                break;
            case 3:
                return;
                break;
            default:
                printf("Gecersiz kod!!\n");
                break;
        }
    }
}

void rastgeleMatrisOlustur()
{
    int secim;
    //rastgele matris olusturuluyor bastirilmadan once oyun modu seciliyor daha sonra oynama stili secimine gidiliyor
    while(1)
    {
        printf("1. Manuel Modda Oyna:\n");
        printf("2. Otomatik Modda Oyna:\n");
        printf("3. Ana Menuye Don\n");
        printf("Seciminizi yapiniz: ");
        scanf("%d", &secim);

        switch(secim)
        {
            case 1:
                manuelmode();//koordinatlar elle girilecek o sekilde ilerleyecek
                break;
            case 2:
                automode();//otomatik pathfinder adim adim eslestirecek(sanirim)
                break;
            case 3:
                return;
                break;
            default:
                printf("Gecersiz kod!!\n");
                break;
        }
    }
}

void skorlariGoster(gamerID *data, int pos)
{
    int i;
    i = -1;
    if(pos == 0)
    {
        printf("Mevcut oyuncunun skoru bulunmadigindan okunamiyor.\n");
        return;
    }
    while(++i < pos)
        printf(">>%s: %d\n", data->username, data->score);
    return;
}

void anaMenu(gamerID *data, int **tab, int pass) {
    int secim;
    int M;
    int i = 0;

    do {
        printf("Ana Menü\n");
        printf("1. Rastgele Matris Oluştur:\n");
        printf("2. Dosyadan Matris Oluştur:\n");
        printf("3. Kullanicilarin Skorlarini Goster:\n");
        printf("4. Cikis\n");
        printf("Seçiminizi yapiniz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                rastgeleMatrisOlustur();
                oyunMenu();
                break;
            case 2:
                dosyadanMatrisOlustur(tab);
                oyunMenu();
                break;
            case 3:
                skorlariGoster(data, pass);
                oyunMenu;
                break;
            case 4:
                printf("Cikis yapiliyor...\n");
                exit(0);
            default:
                printf("Gecersiz kod!!\n");
                break;
        }
        i++;
    } while (i);
}

void kullaniciGiris(gamerID *data, int **arr, int x)//x daha onceki oyuncularin skornu gormek icin
{
    do{
        printf("Kullanici adinizi giriniz(15 harf uzunlugunda olmalidir!):");
        scanf("%[^\n]s", data->username);
        anamenu(data ,arr, x);
    }while(1);
}

int main()
{
    int i, j, matris[MAX][MAX] = {{0}};
    int N;      // matris degeri
    int M;      // kullanici sayisi
    //char fileName[20];
    //char choice[20];
    printf("Kac oyuncu oynayacak?");
    scanf("%d", &M);
    gamerID data[M];

    /* buradan itibaren menu vb kodlari olmalidir. dosya okumak icin asagidaki kod verilmistir */
    while(M > 0)
    {
        kullaniciGiris(&data[i], matris, i);
        M--;
    }
    /*
     * matrisi manuel doldurmak veya Oyunu oynamak icin yazilacak kodlarin
     * fonksiyon cagrilari buradan  baslamalidir
     */

    return 0;
}