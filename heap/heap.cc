/* Implementation of heap */
#include"heap.h"

/* inline constructor for heap
 * initialized heap size to -1*/
inline heap::heap():heap_size(-1){}


/* insert new element into heap*/
bool heap::max_insert(int new_element){
	(heap_size)++; //increment the position
	
	max_heap_increase_key(heap_size, new_element);
	//max_heap[heap_size-1] = new_element; //insert the element at last position
}
