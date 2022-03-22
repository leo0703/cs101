#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct lotto_record{
    int lotto_no;
    int lotto_receipt;
    int emp_id;
    char lotto_date[10];
    char lotto_time[20];
}lotto_record_t;



int main(){
    int a[7]={0},tmp=0,counter,n,o;
 
    char lotto[50]="lotto[0000";
    char last[50]="0].txt";
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
    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("輸入操作人員ID(0~5):");
    scanf("%d",&o);
    printf("請問你要買幾組樂透彩(1~5): ");
    scanf("%d",&n);
    printf("已為您購買的%d組樂透組合輸出至 lotto.txt\n",n);
    fprintf(fp,"======== lotto649 =========\n");
    fprintf(fp,"=======+ No.%05d +========\n",counter);
    time_t curtime;
    lotto_record_t g;//struct
    char szbuff[32];//time
    char sbuff[32];
   time_t now=time(0);
    strftime(szbuff,100,"%Y%m%d-%H:%M:%S",localtime(&now));//
    strftime(sbuff,100,"%H:%M:%S",localtime(&now));//
    g.lotto_no=counter;
    g.lotto_receipt=counter*50*1.1;
    g.emp_id=o;
    strcpy(g.lotto_date,szbuff);
    strcpy(g.lotto_time,sbuff);
     
    
    
    FILE *fp4=fopen("records.bin","ab");
    fwrite(&g.lotto_no,sizeof(int),1,fp4);
    fwrite(&g.lotto_receipt,sizeof(int),1,fp4);
    fwrite(&g.emp_id,sizeof(int),1,fp4);
    fwrite(g.lotto_date,sizeof(char),8,fp4);
    fwrite(g.lotto_time,sizeof(char),sizeof(g.lotto_time),fp4);
    fclose(fp4);
    
    
    
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
        }     tmp=0;
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
}  