#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct emp_record{
    int emp_id;
    char emp_name[10];
    int emp_salary;
}emp_record_t;



int main(){
    int a[7]={0},tmp=0,counter,n,o,id,salary;
 
    char lotto[50]="lotto[0000";
    char last[50]="0].txt";
    char opname[10];
    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("輸入操作人員ID(0~5):");
    scanf("%d",&o);
    if (o!=0) { 
        FILE* fp1;
      fp1=fopen("counter.bin","r");

        int arr_write[1]={0};
    
     if(fp1==NULL){
        FILE* fptmp= fopen("counter.bin","wb+");
         fwrite(arr_write,sizeof(int),1,fptmp);
        fclose(fptmp);
        }else{
        fclose(fp1);
     }
        int arr_read[1];
       FILE *fptmp1=fopen("counter.bin","rb");
       fread(arr_read,sizeof(int),1,fptmp1);
       counter=arr_read[0];
       fclose(fptmp1);
       last[0]=counter+49;
       strcat(lotto,last);   
        ++counter;
        FILE *fp;
        fp=fopen(lotto,"w+");
        printf("請問你要買幾組樂透彩(1~5): ");
        scanf("%d",&n);
        printf("已為您購買的%d組樂透組合輸出至 lotto.txt\n",n);
        fprintf(fp,"======== lotto649 =========\n");
        fprintf(fp,"=======+ No.%05d +========\n",counter);
        time_t curtime;
         time(&curtime);
        fprintf(fp,"= %.24s=\n",ctime(&curtime));

        for (int i=0;i<5;i++) {
            fprintf(fp,"[%d]: ",i+1);
            if (i<=(n-1)) {
             for (int i=0;i<6;i++) {
                a[i]=rand()%69+1;
             }
             a[6]=rand()%9+1;
                for (int i=0;i<6;i++) {
                 for (int j=i+1;j<6;j++) {
                    if (a[i]==a[j]) {
                    a[j]=rand()%69+1;
                  }
                 }
              }
         for (int j=5;j>0;j--) {
         for (int k=0;k<=j-1;k++) {
             if (a[k]>a[k+1]) {
                tmp=a[k];
                a[k]=a[k+1];
                a[k+1]=tmp;
             }
            }
         }
         for (int i=0;i<7;i++) {
             if (a[i]<10) {
                 fprintf(fp,"0%d ",a[i]);
             } else {fprintf(fp,"%d ",a[i]);
             }
             }
         fprintf(fp,"\n");
         } else {
         for (int i=0;i<7;i++) {
               fprintf(fp,"-- ");
          }
                  fprintf(fp,"\n");
            }        tmp=0;
                  for (int i=0;i<7;i++) {
                      a[i]=0;
                 }
              
            } 
         fprintf(fp,"========* Op.0000%d *=======\n",o);
         fprintf(fp,"======== csie@CGU =========\n");
         fclose(fp);
     FILE* fp3=fopen("operator_id.bin","wb");  
     fwrite(&o,sizeof(int),1,fp3);
     fclose(fp3);  
    
     arr_write[0]=counter;
     FILE* fp2=fopen("counter.bin","wb");
     fwrite(arr_write,sizeof(int),1,fp2);
     fclose(fp2);
    }else{
    
    printf("請輸入要新增操作人員 ID(1-99 :");
    scanf("%d",&id);
    printf("請輸入要新增操作人員 Name:");
    scanf("%s",opname);
    printf("請輸入要新增操作人員 Salary:");
    scanf("%d",&salary);
    printf("輸入完成");
    emp_record_t g;
    g.emp_id=id;
    strcpy(g.emp_name,opname);
    g.emp_salary=salary;
    FILE *fp5=fopen("operator_id.bin","ab");
    fwrite(&g.emp_id,sizeof(int),1,fp5);
    fwrite(g.emp_name,1,sizeof(g.emp_name),fp5);
    fwrite(&g.emp_salary,sizeof(int),1,fp5);
    fclose(fp5);

   }
}