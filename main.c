#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 1000
int n=N;
int A[N];

int lSearch(int [],int,int); //lSearch(VectorD,tamaño,valor buscado)
int bSearch(int[],int,int,int); //bSearch(VectorO,inicio,fin,valor buscado)
void burbujaS(int [],int);
int iSearch(int[],int,int); //iSearch(VectorO,tamaño,valor buscado)
//int inpSearch(int[],int,int,int); //inpSearch(VectorO,inicio,fin,valor buscado)

int vs=3; //valor searched

int main(){
    srand(time(NULL));
    for(int i=0;i<N;i++)
    {
        A[i]=rand()%11;
        printf("%d ",A[i]);
    }
    //int indice= lSearch(A,n,vs);

    burbujaS(A,n);
    printf("\n");
    for(int i=0;i<N;i++)
        printf("%d ",A[i]);
    int indice= iSearch(A,n,vs);
    if(indice!=-1)
        printf("\nEl valor se encuentra en el indice : %d",indice);
    else
        printf("\nNo se encontro el valor");

    return 0;
}

int lSearch(int A[],int n,int vs)
{
    for(int i=0;i<n;i++)
        if(A[i]==vs)
            return i;
    return -1;
}

void burbujaS(int A[],int n){
    int swap;
    for(int i=0;i<=n-1;i++)
        for(int j=0;j<n-1-i;j++)
            if(A[j]>A[j+1])
            {
                swap=A[j];
                A[j]=A[j+1];
                A[j+1]=swap;
            }
}

int bSearch(int A[],int inicio, int fin, int vs)
{
    while(inicio<=fin)
    {
        int medio=inicio+(fin-inicio)/2;
        if(A[medio]==vs)
            return medio;
        else if(vs>A[medio]) //compara con el vector derecho
            inicio=medio+1;
        else //comparar con el vector izquierdo
            fin=medio-1;
    }
    return -1;
}

int iSearch(int A[],int n, int vs)
{
    int indices[n],elementos[n],i,set=0;
    int inicio, fin,ind=0;   // inicio y fin de rango de busqueda, ind es indices deindices y elementos

    //crear los limites
    for(i=0;i<n;i+=3)
    {
        indices[ind]=i;
        elementos[ind]=A[i];
        ind++;
    }
    //verificar si el valor buscado
    //esta dentro del arreglo
    if(vs<A[0] || vs>A[n-1])
        return -1;
    else
    {
        for(i=1;i<=ind;i++)
            if(vs<=elementos[i])
            {
                //generamos rango de busqueda
                inicio=indices[i-1]; //indice anterior
                fin=indices[i]; //inide actual
                set=1;
                break;
            }
    }
    if(set==0)
    {
        inicio=indices[i];
        fin=n-1;
    }


    for(i=inicio;i<fin;i++)
    {
        if(vs==A[i])
            return i;
    }

    return -1;
}

int inpSearch(int A[],int inicio,int fin,int vs)
{
    int pos; //posición aproximada del valor
    while(inicio<=fin && vs>=A[inicio] && vs<=A[fin])
    {

        pos=inicio+((vs-A[inicio])*(fin-inicio)/(A[fin]-A[inicio]));
        if(vs==A[pos])
            return pos;
        else if (vs<A[pos])
            fin=pos-1;
        else
            inicio=pos+1;

    }
    return -1;
}

