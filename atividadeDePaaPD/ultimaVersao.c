#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define TAMANHO_MAX 150
#define TEMPO_TOTAL 650

typedef struct brinquedo{
    unsigned int tempo;
    unsigned int pontos;
}Tbrinquedo;

unsigned int comparaBrinquedos(int*, int*, Tbrinquedo*, unsigned int*);

unsigned int max(unsigned int*, unsigned int);

void imprimeInstancia(int*, unsigned int*);

int main(int argc, char** argv){
    int quantidadeAtracoes = 1,
            limiteDeTempo = 1,
            instancia = 1;
    unsigned int resultado = 0, memoria[TEMPO_TOTAL];
    Tbrinquedo listaBrinquedos[TAMANHO_MAX];
    
    while(TRUE){
        scanf("%u %u", &quantidadeAtracoes, &limiteDeTempo);
        
        if(quantidadeAtracoes == 0){
            break;
        }
        
        for(int i = 0; i < limiteDeTempo; ++i){
            memoria[i] = 0;
        }
        
        for(int i = 0; i < quantidadeAtracoes; ++i){
            scanf("%u %u", &listaBrinquedos[i].tempo, &listaBrinquedos[i].pontos);
        }
        
        resultado = comparaBrinquedos(&quantidadeAtracoes, &limiteDeTempo, &listaBrinquedos, &memoria);
        imprimeInstancia(&instancia, &resultado);
        ++instancia;
    }
    
    return 0;
}

unsigned int comparaBrinquedos(int* quantidadeDeAtracoes, int* limiteDeTempo, Tbrinquedo* listaBrinquedos, unsigned int* memoria){
    unsigned int auxiliar = 0;
    
    for(int contadorDeTempo = 0; contadorDeTempo < 1 + (*limiteDeTempo); ++contadorDeTempo){
        for(int contadorDeAtracoes = 0; contadorDeAtracoes < *quantidadeDeAtracoes; ++contadorDeAtracoes){
            
            if(contadorDeTempo >= listaBrinquedos[contadorDeAtracoes].tempo){
                auxiliar = max(&auxiliar, memoria[contadorDeTempo - listaBrinquedos[contadorDeAtracoes].tempo] + listaBrinquedos[contadorDeAtracoes].pontos);
            
            }
        }
        
        memoria[contadorDeTempo] = auxiliar;
        auxiliar = 0;
    }
    
    return memoria[*limiteDeTempo];
}

unsigned int max(unsigned int* primeiro, unsigned int segundo){
    if(*primeiro > segundo){
        return *primeiro;
    }
    
    return segundo;
}

void imprimeInstancia(int* instancia, unsigned int* resultado){
    printf("Instancia %d\n%u\n\n", *instancia, *resultado);
    
    return;
}