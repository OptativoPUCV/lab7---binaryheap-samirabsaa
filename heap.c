#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){

  //ver si primer elemento es nulo
  if(pq->size == 0)return NULL; 
  void * aTop = pq->heapArray[0].data;
  return aTop; 
  
}

void heap_push(Heap* pq, void* data, int priority){

  //insertar nuevo dato con prioridad p 
  //si el arreglo está lleno aumentar capacidad (doble + 1) usando realloc
  //arreglo = realloc(arreglo, nueva_capacidad)
  //verificar si arreglo está lleno y aumentar capacidad
  if(pq->size == pq->capac ){
    pq->capac = pq->capac *2 + 1; 
    pq->heapArray = (heapElem*) realloc(pq->heapArray, sizeof(heapElem)*pq->capac); 
  }
  int nuevoD = pq->size; 
  pq->heapArray[nuevoD].data = data; 
  pq->heapArray[nuevoD].priority = priority; 
  //aumentar size
  pq->size = pq->size+1;

 heapElem padre, aux; 
  while(nuevoD!=0){
    padre = pq->heapArray[(nuevoD-1)/2];
    if(padre.priority > pq->heapArray[nuevoD].priority)break; 

    aux = padre; 
    
    pq->heapArray[(nuevoD-1)/2] = pq->heapArray[nuevoD]; 
    pq->heapArray[nuevoD] = aux; 

    nuevoD= (nuevoD -1)/2; 
  }

}

void heap_pop(Heap* pq){

  //hijos del nodo en posición X: 2X+1 y 2X+2
  //padre del nodo en posición Y: (Y-1)/2

  //si el montículo esta vacío 
  if(pq->size ==0) return; 

  //se elimina el mayor elemento 
  pq->heapArray[0] = pq->heapArray[pq->size-1];
  pq->size= pq->size-1;

  //organizar nuevamente 
  int aux = 0;
  int hijoI, hijoD , padre; 
  //hijo1 = 2*pq->size+1; 
  //hijo2 = 2*pq->size +2;
  //padre = (pq->size-1)/2; 

  while(true){
    hijoI = 2 * pq->size + 1; //aux ?
    hijoD = 2 * pq->size + 2;


    //hijo izquierdo es mayor que aux
    if(hijoI < pq->size && pq->heapArray[hijoI].priority > pq->heapArray[aux].priority) padre = hijoI; 
    else padre = aux; 


    //hijo derecho es mayor que padre
    if(hijoD < pq->size && pq->heapArray[hijoD].priority > pq->heapArray[padre].priority) padre = hijoD;

    //aux es el mayor se termina ciclo 

    if(aux == padre) break;

    
    
  }

  

  

  

}

Heap* createHeap(){

  Heap * heap = (Heap *) malloc(sizeof(Heap)); 
  heap->capac = 3; 
  heap->size = 0;
  heap->heapArray = (heapElem *) malloc(sizeof(heapElem)*heap->capac); 
  

   return heap;
}
