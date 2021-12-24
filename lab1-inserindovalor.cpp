#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
//#include <bits/stdc++.h>
//using namespace std;



// MERGE SORT //
void merge(int* vetor, int* vetoraux,int primeiro,int meio,int ultimo) {
    //int lado1=meio-primeiro+1, lado2=ultimo-meio;

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
        //swap(vetor[0], vetor[i]);
        ///fazendo a troca
        int temporario;
        temporario = vetor[0];
        vetor[0]=vetor[i];
        vetor[i]=temporario;

        heapify(vetor, i, 0);
    }
}

void heap(int *vetor, int n)
{
    ///controi heap
    for (int i=n/(2-1); i>=0; i--)
        heapify(vetor, n, i);

    for (int i=n-1; i>=0; i--)
    {
        //swap(vetor[0], vetor[i]);
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

void temp(int *vetor, int n)
{
    long double ti, tf;
    ti = getNow();

    //heap(vetor, n);
    mergesort(vetor,0,n-1);

    tf = getNow();

    printf("\n %d elementos = %Lf segundos\n", n, t);
    free(vetor);
}

int main()
{
    srand(time(NULL));
    int* vetor;
    int n;
    //Tamanho do vetor
    scanf("%d", &n);
    vetor=(int *) malloc(n * sizeof (int));
    for(int i=0;i<n;i++)
    {
        vetor[i]=rand()%1000000;
    }

    temp(vetor,n);
    //printArray(vetor, n);

    return 0;
}
