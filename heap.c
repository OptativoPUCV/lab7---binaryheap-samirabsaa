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
  if(pq == NULL || pq == 0)return NULL; 
  void * aTop = pq->heapArray[0].data; 

  return aTop; 
}



void heap_push(Heap* pq, void* data, int priority){

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
