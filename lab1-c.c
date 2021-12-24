#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>


// MERGE SORT //
void merge(int* vetor, int* vetoraux,int primeiro,int meio,int ultimo) {
    
    int i,j,n;
    i=primeiro;
    j=meio+1;
    n=0;
    while(i<=meio && j<=ultimo) ///compara se um dos lados ja acabou
    {
        if(vetor[i]>vetor[j])
        {
            vetoraux[n++]=vetor[j];
            j++;
        }
        else
        {
            vetoraux[n++]=vetor[i];
            i++;
        }
    }
    while(j<=ultimo) ///descarrega o vetor lado2
    {
        vetoraux[n]=vetor[j];
        j++;
        n++;
    }
    while(i<=meio) ///descarrega o vetor lado1
    {
        vetoraux[n]=vetor[i];
        i++;
        n++;
    }
	for(n=0;n<ultimo-primeiro+1;n++)
		vetor[n+primeiro]=vetoraux[n];
}
void mergesort(int* vetor, int* vetoraux,int primeiro,int ultimo) {
    if(ultimo>primeiro)
    {
        int meio;
        meio=(primeiro+ultimo)/2;
        mergesort(vetor, vetoraux,primeiro,meio);
        mergesort(vetor, vetoraux,meio+1,ultimo);
        merge(vetor, vetoraux,primeiro,meio,ultimo);
    }
}

// HEAP SORT //

void heapify(int *vetor, int n, int i)
{
    int maior = i, e=2*i + 1, d=2*i + 2;

    if (e < n && vetor[e] > vetor[maior])
        maior = e;

    if (d < n && vetor[d] > vetor[maior])
        maior = d;

    if (maior != i) ///verificar se o maior nao é a raiz
    {
        ///fazendo a troca
        int temporario;
        temporario = vetor[i];
        vetor[i]=vetor[maior];
        vetor[maior]=temporario;

        heapify(vetor, n, maior);
    }
}

void heap(int *vetor, int n)
{
    ///controi heap
    for (int i=n/(2-1); i>=0; i--)
        heapify(vetor, n, i);

    for (int i=n-1; i>=0; i--)
    {
        ///fazendo a troca
        int temporario;
        temporario = vetor[0];
        vetor[0]=vetor[i];
        vetor[i]=temporario;

        heapify(vetor, i, 0);
    }
}


// FUNCAO TEMPO //
long double getNow()
{
   struct timeval now;
   long double valor = 1000000;

   gettimeofday(&now,NULL);

   return ((long double)(now.tv_sec*valor)+(long double)(now.tv_usec));
}

void temp(int *vetor, int *vetoraux)
{
    long double t=0, ti, tf;
    int i=10;
    while(t<60)
    {
        vetor=(int *) malloc(i * sizeof (int));
	vetoraux=(int *) malloc(i * sizeof (int));
        for(int j=0;j<i;j++)
        {
            vetor[j]=rand()%100000000;
        }

        ti = getNow();
        
        /// COMENTE A CHAMADA DA FUNCAO QUE NAO DESEJA EXECUTAR A ORDENACAO
        heap(vetor, i);
        mergesort(vetor, vetoraux,0,i-1);

        tf = getNow();
        t=(tf-ti)/1000000;
	printf("\n %d elementos = %Lf segundos\n", i, t);
        //cout<<"\n"<<fixed<< i <<" elementos  = "<< t <<" segundos\n\n";
        i=i*2;
	free(vetor);
    }

}

int main()
{
    srand(time(NULL));
    int* vetor,*vetoraux;
    //int n;
    //Tamanho do vetor
    //scanf("%d", &n);


    temp(vetor, vetoraux);

    return 0;
}
