import java.util.Scanner;
import java.io.IOException;

public class Main{
	public static void limparBuffer(Scanner buffer){
		if(buffer.hasNextLine()){
			buffer.nextLine();
		}
	}
	
	public static void main(String[] args) throws IOException{
        Scanner leitura = new Scanner(System.in);
        int numeroDeAlunos = 0;
        Mergesort trocas;
        String cadeiaDeCaracteres[];
        
        //while(leitura.hasNextLine()){
            numeroDeAlunos = leitura.nextInt();
            cadeiaDeCaracteres = new String[numeroDeAlunos];
            limparBuffer(leitura);

            for(int i = 0; i < numeroDeAlunos; ++i){
                cadeiaDeCaracteres[i] = leitura.nextLine();
            }

            trocas = new Mergesort(cadeiaDeCaracteres);
            System.out.println(trocas.getContadorDeTrocas() + "\n");
        //}
        
        leitura.close();
    }
}

class Mergesort {
	private String[] vetorDeCaracteres;
	private String[] auxiliar;
	private int tamanho;
	private long quantidadeDeTrocas = 0;
	
	/* Construtor vazio da classe */
	public Mergesort(){}

	/* Contrutor da classe com parâmetros */
	public Mergesort(String[] vetorDeCaracteres){
		this.vetorDeCaracteres = vetorDeCaracteres;
		this.tamanho = vetorDeCaracteres.length;
		this.auxiliar = new String[tamanho];
		mergeSort(0, (tamanho - 1));
	}
	
	public long getContadorDeTrocas(){
		return this.quantidadeDeTrocas;
	}

	public void mergeSort(int ptrInicio, int ptrFim){ 
		int ptrMeio = 0;
		
		if (ptrInicio < ptrFim){
			ptrMeio = (int) Math.floor( (ptrFim + ptrInicio) / 2 );

			mergeSort(ptrInicio, ptrMeio);
			mergeSort(ptrMeio + 1, ptrFim);
			intercala(ptrInicio, ptrMeio, ptrFim);
		}
	}

	public void intercala(int ptrInicio, int ptrMeio, int ptrFim){
		int ptrEsquerdo = 0,
			ptrDireito = 0,
			ptrProximaPosicaoLivre = 0;
		
		for (int i = ptrInicio; i < 1 + ptrFim; ++i){
			this.auxiliar[i] = this.vetorDeCaracteres[i];
		}

		ptrEsquerdo = ptrInicio;
		ptrDireito = (1 + ptrMeio);
		ptrProximaPosicaoLivre = ptrInicio;

		/* Laço que realiza as trocas */
		while(ptrEsquerdo < 1 + ptrMeio && ptrDireito < 1 + ptrFim){
			if(this.auxiliar[ptrEsquerdo].compareTo(this.auxiliar[ptrDireito]) < 1){
				this.vetorDeCaracteres[ptrProximaPosicaoLivre] = this.auxiliar[ptrEsquerdo];
				++ptrEsquerdo;
		  	}
		  	
		  	/* A contabilização das troas ocorrem nessa condição */
		  	else{
				this.vetorDeCaracteres[ptrProximaPosicaoLivre] = this.auxiliar[ptrDireito];
				this.quantidadeDeTrocas += (ptrDireito - ptrProximaPosicaoLivre);
				++ptrDireito;
		  	}
		  
			++ptrProximaPosicaoLivre;
		}
		
		/* Este laço apenas copia para o vetor os valores que sobraram */
		while(ptrEsquerdo < 1 + ptrMeio){
		  this.vetorDeCaracteres[ptrProximaPosicaoLivre] = this.auxiliar[ptrEsquerdo];
		  ++ptrProximaPosicaoLivre;
		  ++ptrEsquerdo;
		}
	}
}
