#include<stdio.h> 
#include<stdlib.h> 
  
 struct ogrenci{ 
       int no; 
       char ad[40]; 
       char bolum[40];         
 }; 
  
    typedef struct ogrenci ogrenci; 
  
    void verialma(FILE *myptr){ 
          char bugfix[2]; 
          ogrenci temp; 
          
          printf("\n"); 
          printf(" ogrenci no, ad, bolum giriniz : "); 
          scanf("%d %s %s",&temp.no, temp.ad, temp.bolum); 
          
         while(!feof(stdin)){ 
              fprintf(myptr,"%s %d %s \n",temp.ad, temp.no, temp.bolum); 
                  
              printf(" ogrenci no, ad, bolum giriniz : "); 
              scanf("%d %s %s",&temp.no, temp.ad, temp.bolum); 
                                  
         }
 } 
  
    void veriyazma(FILE *myptr){ 
         ogrenci temp; 
          
         fscanf(myptr,"%s %d %s",temp.ad, &temp.no, temp.bolum); 
          
         while(!feof(myptr)){ 
               printf("%d %s %s \n",temp.no,temp.ad,temp.bolum);                 
               fscanf(myptr,"%s %d %s",temp.ad,&temp.no,temp.bolum); 
                  
         }                 
 } 
  
 int isimarama(FILE *myptr, char name[]){ 
          
         ogrenci temp; 
         fscanf(myptr,"%s %d %s",temp.ad,&temp.no,temp.bolum); 
                  
         while(!feof(myptr)){ 
               if(strcmp(temp.ad,name)==0){ 
                  printf("\naradiginiz ogrenci ; \n"); 
                  printf("%d %s %s \n-------------\n",temp.no,temp.ad,temp.bolum); 
                  return 1; 
                          
              }else
                 fscanf(myptr,"%s %d %s",temp.ad,&temp.no,temp.bolum); 
                  
         } 
          
         printf("aradiginiz ogrenci bulunamadi."); 
         return 0; 
          
 }         
  
    int main(){ 
         FILE *myptr; 
          
         int kontrol; 
         char name[40]; 
         char bugfix[2]; 
          
         while(1){ 
              printf("1-Dosya olusturma\n 2-Listeleme\n  3-Yeni Kayit Ekleme\n  4-Isme gore arama\n  5-Cikis\nBir veri girisi gerceklestiriniz [1-5] : "); 
              scanf("%d",&kontrol); 
                 if(kontrol==5){ 
                    printf("cikis yapiliyor"); 
                          break; 
                          
                 } 
                  
                 switch(kontrol){ 
                  
                         case 1:  myptr=fopen("OgrenciVerileri.txt","w");                         
                                  if(myptr==NULL) printf("\nDosya acilamadi.\n"); 
                                     verialma(myptr); 
                                     fclose(myptr); 
                                     break; 
 
                  
                         case 2: myptr=fopen("OgrenciVerileri.txt","r"); 
                                 if(myptr==NULL) printf("\nDosya acilamadi.\n"); 
                                    veriyazma(myptr); 
                                    fclose(myptr); 
                                    break; 
 
                          
                         case 3: myptr=fopen("OgrenciVerileri.txt","a"); 
                                 if(myptr==NULL) printf("\nDosya acilamadi.\n"); 
                                    verialma(myptr); 
                                    fclose(myptr); 
                                    break; 
                          
                         case 4: myptr=fopen("OgrenciVerileri.txt","r"); 
                                 if(myptr==NULL) printf("\nDosya acilamadi.\n"); 
                                    printf("Aramak istediginiz ismi giriniz : "); 
                                    gets(bugfix); 
                                    gets(name); 
                                    isimarama(myptr,name); 
                                    fclose(myptr); 
                                    break; 
                          
                         case 5: printf("cikis yapiliyor"); 
                                 break; 
                          
                         default: printf("yanlis giris yaptiniz"); 
                                  break; 
      } 
   } 
                  
 return 0; 
 }
