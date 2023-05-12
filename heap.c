#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
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
  pq->size = pq->size++;  
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){

  Heap * heap = (Heap *) malloc(sizeof(Heap)); 
  heap->capac = 3; 
  heap->size = 0;
  heap->heapArray = (heapElem *) malloc(sizeof(heapElem)*heap->capac); 
  

   return heap;
}
