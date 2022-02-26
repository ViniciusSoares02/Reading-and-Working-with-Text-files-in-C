#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

FILE *abre_arquivo(const char *arquivo){

    if (!arquivo){
        return NULL;

    }else{
    FILE *ptr;

    ptr = fopen(arquivo, "r");

    return ptr;
    }
}

int fecha_arquivo(FILE *arq){
    if (!arq){
        return 1;
    }else{
    fclose(arq);

    return 0;
    }
}

double *le_valores(const char *arquivo, unsigned int *qtd_numeros){
    
    if (!qtd_numeros){
        return NULL;    
    }else if (!arquivo){
        *qtd_numeros=0;
        return NULL;
    }else{
        FILE *ptr;
        ptr = fopen( arquivo, "r");
        int tam=0 ,i=0;
        double valor;

        fscanf(ptr, "%lf", &valor);
        while (!feof(ptr)){
            tam = tam + 1;
            fscanf(ptr, "%lf", &valor);
        }
        rewind (ptr);
        double *p;        
        p = (double*)malloc(sizeof(double)*(tam+1));
        
        for(i=0; i<tam; i++){
            fscanf(ptr, "%lf", &valor);
            p[i]= valor;
        }        
        fclose(ptr);
        *qtd_numeros = tam;
        return p;
    }
}


double maior(double *valores, unsigned int qtd_numeros){
    
    if (!valores || (qtd_numeros == 0)){
        return HUGE_VAL;
    }else {
        unsigned int i;
        double a;
        a = valores[0];
        for (i=0; i<qtd_numeros; i++){
            if (valores[i]>a){
                a = valores[i];
            }
        }
        return a;
    }
}

double menor(double* valores, unsigned int qtd_numeros){
    if (!valores || (qtd_numeros == 0)){
        return HUGE_VAL;
    }else {
        unsigned int i;
        double a;
        a = valores[0];
        for (i=0; i<qtd_numeros; i++){
            if (valores[i]<a){
                a = valores[i];
        }
    }
    return a;
    }

}

double media(double* valores, unsigned int qtd_numeros){
    if (!valores || (qtd_numeros == 0)){
        return HUGE_VAL;
    }else{
        unsigned int i;
        double val=0.0, media; 
        for (i=0; i<qtd_numeros; i++){
            val= val + valores[i];
        }
        media = val/qtd_numeros;
        return media;
    }
}

double desvio(double* valores, unsigned int qtd_numeros){
    
    if(!valores || (qtd_numeros == 0)){
        return HUGE_VAL;
    }else{
        unsigned int i;
        double med, desviosoma=0.0, desviotot=0.0, x, val=0.0;             
        
        for (i=0; i<qtd_numeros; i++){
            val = val + valores[i];
        }
        med = val/qtd_numeros;
        int d;
        d = qtd_numeros - 1;
    
        for(i=0; i<qtd_numeros; i++){
            x = valores[i]-med;
            desviosoma = desviosoma + x*x;
        }
        desviotot = sqrt(desviosoma/d);
        return desviotot;
    }
}
double amplitude(double* valores, unsigned int qtd_numeros){
    
    if(!valores || (qtd_numeros == 0)){
        return HUGE_VAL;
    }else{
        double menorv = valores[0], maiorv = valores[0];
        unsigned int i;
    
        for (i=0; i < qtd_numeros; i++){
            if (valores[i]<menorv){
                menorv = valores[i];
            }
            else if (valores[i]>maiorv){
                maiorv = valores[i];
            }

        }
        
        double amplitude = maiorv - menorv;

        return amplitude;
    }
}

double valor(double* valores, unsigned int qtd_numeros, unsigned int posicao){

    if(!valores || (posicao >= qtd_numeros) || (qtd_numeros == 0)){
        return HUGE_VAL;
    }else{
        return valores[posicao];
    }
}

double repetido(double* valores, unsigned int qtd_numeros, unsigned int *qtd_repeticao){
    if (!qtd_repeticao){
        return HUGE_VAL;
    }else if(!valores || (qtd_numeros == 0)){
        *qtd_repeticao = 0;
        return HUGE_VAL;
    }else{
        unsigned int i, j;
        int a=0,cont=0;
        double x;
        for (i=0; i<qtd_numeros; i++){
            cont = 1;
            for(j=i+1; j<qtd_numeros; j++){
                if (valores[j] == valores[i]){
                    cont = cont + 1;
                }
            }
            if (cont > a){
                a = cont;
                x = valores[i];
            }
        }
        *qtd_repeticao = a;
        return x;
    }
    
}

int main(){

    double vet[5]={5,2,5,6,5};
    double i;
    unsigned int x = 5, *p;
    i = repetido(vet, x, p);
    printf("%lf %i",i, *p);
   
    return 0;
}