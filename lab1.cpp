#include <stdio.h>
#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <bits/stdc++.h>
using namespace std;


// MERGE SORT //
void merge(int* vetor,int p,int q,int r) {
    int lado1=q-p+1, lado2=r-q, e[lado1+1], d[lado2+1];

    for(int i=0; i<lado1; i++)
        e[i]=vetor[p+i];
    for(int j=0; j<lado2; j++)
        d[j]=vetor[q+1+j];

    int i,j,n;
    i=0;
    j=0;
    n=0;
    while(i!=lado1 && j!=lado2) ///compara os dois lados
    {
        if(e[i]>d[j])
        {
            vetor[p+n]=d[j];
            j++;
        }
        else
        {
            vetor[p+n]=e[i];
            i++;
        }
        n++;
    }
    while(j!=lado2) ///descarrega o vetor lado2
    {
        vetor[p+n]=d[j];
        j++;
        n++;
    }
    while(i!=lado1) ///descarrega o vetor lado1
    {
        vetor[p+n]=e[i];
        i++;
        n++;
    }
}
void mergesort(int* vetor,int p,int r) {
    if(r>p)
    {
        int q;
        q=(p+r)/2;
        mergesort(vetor,p,q);
        mergesort(vetor,q+1,r);
        merge(vetor,p,q,r);
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


// FUNCAO TEMPO //
long double getNow()
{
   struct timeval now;
   long double valor = 1000000;

   gettimeofday(&now,NULL);

   return ((long double)(now.tv_sec*valor)+(long double)(now.tv_usec));
}

void temp(int *vetor)
{
    long double t=0, ti, tf;
    int i=10;
    while(t<60)
    {
        vetor=(int *) malloc(i * sizeof (int));
        for(int j=0;j<i;j++)
        {
            vetor[j]=rand()%100000000;
        }

        ti = getNow();

        //heap(vetor, i);
        mergesort(vetor,0,i-1);

        tf = getNow();
        t=(tf-ti)/1000000;
        cout<<"\n"<<fixed<< i <<" elementos  = "<< t <<" segundos\n\n";
        i=i*2;

    }

}

int main()
{
    srand(time(NULL));
    int* vetor;
    //int n;
    //Tamanho do vetor
    //scanf("%d", &n);


    temp(vetor);

    return 0;
}
