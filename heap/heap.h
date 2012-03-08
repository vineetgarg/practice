/* heap data structure using array
 * data type - int
 * max size of heap is MAX_SIZE
 * 8 March, 2012
 * @Garg, Vineet
 */
#include<iostream>
#define MAX_SIZE 100

class heap{
	int max_heap[MAX_SIZE]; //array to store the heap elements
	int heap_size; //tracks the current heap size. 

	heap();

public:
	bool max_insert(int new_element); //it inserts a new element into heap. returns true if successfully added
	void max_heapify(int position); //restore the heap located at position position
	bool max_heap_increase_key(int pos, int key); //it increases the value of 

};
