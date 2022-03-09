#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main () {
 FILE* fp;
 fp = fopen("lotto.txt", "w+");
 int n, a[8] = {0}, k, c, num, tmp, repeat,i,j;
 char name[16];
 printf("歡迎光臨長庚樂透彩購買機台\n");
 printf("請問你要買幾組樂透彩：");
 scanf("%d", &num);
 for(int i=1,j=0;j==0;i++){
     sprintf(name, "lotto[%04d].txt",i);
     if(access(name,F_OK)!=0){
         fp=fopen(name,"w+");
         fprintf(fp, "======== lotto649 =========\n");
         fprintf(fp,"======+ No.%05d +======\n",i);
         j=1;
     };
 }
 srand(time(0));
 time_t curtime;
 time(&curtime);
 fprintf(fp, "= ");
 for (int g = 0; g <= 23; g++) {
     fprintf(fp, "%c", ctime(&curtime)[g]);
 }
 fprintf(fp, " =\n");
 for (k = 1; k <= num; k++) {
  fprintf(fp, "[%d]:", k);
  for (n = 0; n <= 5; n++) {
   do {
    a[n] = (rand() % 69) +1;
    repeat = 0;
    for (int b = 1; b <= n; b++) {
     if (a[n] == a[b-1]) {
      repeat = 1;
     }
    }
   } while (repeat == 1);
  }
  for (n = 0; n <= 5; n++) {
   for (int i=0; i<6; i++) {
             for (int j=0; j<6; j++) {
                 if (a[i] < a[j]) {
                  tmp = a[i];
                     a[i] = a[j];
                     a[j] = tmp;
     }
             }
         }
   fprintf(fp, "%d ", a[n]);
  }
  a[7] = (rand() % 10) +1;
  fprintf(fp, "%d", a[7]);
  fprintf(fp, "\n");
  if (k >= num) {
      k += 1;
      for (; k <= 5; k++) {
          fprintf(fp, "[%04d]: -- -- -- -- -- -- --\n", k);
      }
  }
 }
 fprintf(fp, "======== csie@CGU =========\n");
 fclose(fp);
 return 0;
}