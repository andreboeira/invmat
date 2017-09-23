#include <time.h>
#include <stdlib.h>

double timestamp(void){
    struct timeval tp;
    gettimeofday(&tp, NULL);
    return((double)(tp.tv_sec*1000.0 + tp.tv_usec/1000.0));
}

double *generateSquareRandomMatrix( unsigned int n )
{
  double *mat = NULL;

  /* return NULL if memory allocation fails */
  if ( ! (mat = (double *) malloc(n*n*sizeof(double))) )
    return (NULL);

  /* generate a randomly initialized matrix in row-major order */
  double *ptr = mat;
  double *end = mat + n*n;

  double invRandMax = 1.0/(double)RAND_MAX;

  while( ptr != end ) {
    *ptr++ = (double)rand() * invRandMax;
  }

  return (mat);
}

 void ler_sistema(double *A, FILE *arquivo_entrada, int n) {

  // ler matriz representada em uma dimensao
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      fscanf(arquivo_entrada, "%lf", &A[i*n+j]);
    }
  }
}

void eliminaGaussLU(double *A, int n)
{
	for(int i = 0; i < n; ++i){
		maior = A[i];
		
		for(int pivo = i+n; pivo < n*n; pivo+=n){
			if (A[pivo] > maior)
				maior = A[pivo];
		}
		if (A[maior] <> A[i])
			trocaLinhas(A, i, maior)	
		 
		for (int j = 0; j < n; ++j){
			
			
			
			}
		
		}
	
	}

int main(int argc, char *argv[])
{
      
    double *A = NULL;
    double *AI = NULL;
    double *b = NULL;
    FILE *arquivo_entrada, *arquivo_saida;
	
	int n;
	int max_iter;
	//double erros;
      
	for (int i = 1; i < argc; i += 2) {

		if (strcmp("-i",argv[i]) == 0) 
		{
		  arquivo_entrada = fopen(argv[i+1], "r");
			
		  if (arquivo_entrada != NULL)
		  {
			  fscanf(arquivo_entrada, "%d", &n);
			  if (n > 0 ) 
			  {
				A = (double *) malloc(n*n*sizeof(double));
				AI = (double *) malloc(n*n*sizeof(double));
				b = (double *) malloc(n*n*sizeof(double));
		  
				if (!A || !AI || !b) {
					fprintf(stderr, "\nProblemas ao alocar memória!\n");
					return ERRO;
				}	
				
				ler_sistema(A,arquivo_entrada,n);
			}
		  }
		}
			
		if (strcmp("-r", argv[i]) == 0) 
		{
			int aux;
			  
			aux = atoi(argv[i+1]);
			if (aux > 0 ) 
			{
				n = aux;
				A = (double *) malloc(n*n*sizeof(double));
				AI = (double *) malloc(n*n*sizeof(double));
				b = (double *) malloc(n*n*sizeof(double));
		  
				if (!A || !AI || !b) {
					fprintf(stderr, "\nProblemas ao alocar memória!\n");
					return ERRO;
				}	
			} 	
			else 
			{
				fprintf (stderr, "\nN deve ser maior que 0 \n");
				return ERRO;
			}
			A = generateSquareRandomMatrix(n);
		}
			
		if (strcmp("-k", argv[i]) == 0) 
		{
		  int aux;
		  aux = atoi(argv[i+1]);
		  
		  if (aux > 0 ) {
			max_iter = aux;
		  } 
		  else 
		  {
			fprintf (stderr, "\nMáximo de Iterações deve maior que 0 \n");
			return ERRO;
		  }	
		}	
	 
		if (strcmp("-o",argv[i]) == 0) 
		{
				(arquivo_saida = fopen(argv[i+1], "w")); 	
				if (arquivo_saida == NULL) 
				{
					fprintf (stderr,"\nErro no arquivo de saída!\n");
					return ERRO;  
				}
		}
	}	
	eliminaGaussLU(A);
	resolveSistema(A, AI, b);
	 
} 
