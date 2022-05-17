#include <stdio.h>
#include <stdlib.h>

int main()
{
    int oNo;
    char isim[30];
    char bolum[50];
    FILE *myPtr;
      myPtr = fopen("deneme.txt", "w");

        printf("Ogrenci no, isim, bolum giriniz.\n");

        scanf("%d  %s  %s", &oNo, isim, bolum);

        fprintf(myPtr, "%d  %s  %s", oNo, isim, bolum);



    return 0;
}
