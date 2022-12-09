#define MAXTAM 10000

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

typedef struct queijo{
    unsigned long int volume;
    unsigned long int preco;

}Tqueijo;


/* cabecalho das funcoes */
// int maximo(const void*, const void*); /* funcao auxiliar para o qsort nativo */ 

bool maxFraco(Tqueijo, Tqueijo); /* funcao auxiliar para o sort nativo */

/* void imprimirQuantidadeBase(unsigned long int); */

float solucaoPA(float);

unsigned long int basePiramide(Tqueijo*, unsigned long int, unsigned long int);



int main(int argc, char** argv){
    unsigned long int nroPecasQueijo = 0, solucao = 0,
            tamanho = 0; /* auxiliar para a funcao sort() */
    unsigned long int orcamento = 0;
    //Tqueijo queijos[MAXTAM];
    

    //cout << "Digite o numero de pecas e o orcamento:\n"; 
    cin >> nroPecasQueijo >> orcamento;
    
    Tqueijo queijos[nroPecasQueijo];
    
    for(unsigned long int i = 0; i < nroPecasQueijo; ++i){ /* recebe os volumes */
        cin >> queijos[i].volume;
    }

    for(unsigned long int j = 0; j < nroPecasQueijo; ++j){ /* recebe os precos */
        cin >> queijos[j].preco;
    }
    
    tamanho = sizeof(queijos) / sizeof(queijos[0]);
    
    /* qsort(queijos, nroPecasQueijo, sizeof(Tqueijo), maximo); */
    sort(queijos, (queijos + tamanho), maxFraco);

    solucao = basePiramide(queijos, nroPecasQueijo, orcamento);
    /* imprimirQuantidadeBase(&solucao); */
    cout << solucao << "\n";
    
    return 0;
}



/* implementacao das funcoes */
/*int maximo(const void* ptrA, const void* ptrB){
    const unsigned long int *ptrPrimeiro = (unsigned long int*) ptrA, *ptrSegundo = (unsigned long int*) ptrB;
    
    if(*ptrPrimeiro < *ptrSegundo){
        return -1;
    }
    
    else if(*ptrPrimeiro > *ptrSegundo){
        return 1;
    }
    
    return 0;
}*/


bool maxFraco(Tqueijo ptrA, Tqueijo ptrB){
    float esquerdo = (float) ptrA.volume / ptrA.preco,
            direito = (float) ptrB.volume / ptrB.preco;
    
    return esquerdo > direito;
}

/*void imprimirQuantidadeBase(unsigned long int* ptrSolucao){
    cout << *ptrSolucao << "\n";
    
    return;
}*/

float solucaoPA(float n){
     float auxiliar = sqrt( 1 + (8 * n) );
    
    return ( (-1 + auxiliar) / 2 ) ;
}

unsigned long int basePiramide(Tqueijo* ptrQueijos, unsigned long int nroPecas, unsigned long int orcamento){
    float auxiliar = 0;
    
    for(unsigned long int i = 0; i < nroPecas; ++i){        
        /* verifica se o preco do queijo condiz com o orcamento */
        if(orcamento >= ptrQueijos[i].preco){
            auxiliar += (float) ptrQueijos[i].volume;
            orcamento -= ptrQueijos[i].preco;
        }
        
        /* se nao condiz com o orcamento, entao */
        else{
            /* pega apenas uma porcentagem da peca */
            auxiliar += (float) (ptrQueijos[i].volume * (float) (orcamento) / (float) ptrQueijos[i].preco);
            break; /* assume-se que a porcentagem da peca ira esgotar o orcamento */
        }
    }
    
    return solucaoPA(auxiliar);
}
/*
 * Nao e possivel fazer com menos de 3
 * Se eu possuo  3 pecas, 2 delas vao para a base
 * Se eu possuo  6 pecas, 3 delas vao para a base
 * Se eu possuo 10 pecas, 4 delas vao para a base
 * Se eu possuo 15 pecas, 5 delas vao para a base
 * A norma aqui e o somatorio de 1 ate n !!!
 * Formula fechada para o somatorio:
 * S(n) = 1/2 (n² + 3n + 2)
 */