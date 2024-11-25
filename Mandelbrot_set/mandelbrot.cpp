#include <string.h>
#include <stdio.h>
#include<stdint.h>
#include<math.h>
//#include<magick/MagickCore.h>
//#define N 600
//#define M 900
#define C 200
using namespace std;

int main(){
    int N=10000;
    int M=15000;
    double vertS=1,horI=-2,horS=1;
    FILE *g;
    //int imagen[N][M];
    int i,j,k;
    double long c1,c2,z1,z2,aux,f=fabs(horI-horS)/M;
    g=fopen("mb.txt","w");
    if (g==NULL){
        printf("ERROR");
    } else{
    for (i=0;i<N;i++){
            fprintf(g,"\n");
        for(j=0;j<M;j++){
            c2=vertS-i*f;
            c1=horI+j*f;
            z1=0;
            z2=0;
            k=0;
            while(sqrt(z1*z1+z2*z2)<2&&k<C){
                aux=z1;
                z1=z1*z1-z2*z2+c1;
                z2=2*aux*z2+c2;
                k++;
            }
            if(sqrt(z1*z1+z2*z2)<2){
                //imagen[i][j]=1;
                fprintf(g,"0\t");
            }else {
                //imagen[i][j]=0;
                if(k<30){
                    if(k<20){
                        if(k<10){
                            fprintf(g,"1\t");
                        }else fprintf(g,"0.75\t");
                    }else fprintf(g,"0.5\t");
                }else fprintf(g,"0.25\t");
                }
            //fprintf(g,"%d",imagen[i][j]);
            //printf("%d",imagen[i][j]);
        }
    }
    fclose(g);
    }
return 0;
}
