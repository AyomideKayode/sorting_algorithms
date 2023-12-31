# Project: 0x1B. C - Sorting algorithms & Big O
<img src="./main/willy-wonka-bubble-sort.png" alt="Willy-Wonka" width=100%>

## Resources

#### Read or watch:

* [Sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm)
* [Big O notation](https://stackoverflow.com/questions/487258/what-is-a-plain-english-explanation-of-big-o-notation)
* [Sorting algorithms animations](https://www.toptal.com/developers/sorting-algorithms)
* [15 sorting algorithms in 6 minutes](https://www.youtube.com/watch?v=kPRA0W1kECg) <em>(**WARNING**: The following video can trigger seizure/epilepsy. It is not required for the project, as it is only a funny visualization of different sorting algorithms)</em>
* [CS50 Algorithms explanation in detail by David Malan](https://www.youtube.com/watch?v=yb0PY3LX2x8&t=2s)
* [All about sorting algorithms](https://www.geeksforgeeks.org/sorting-algorithms/)
## Learning Objectives

### General

* At least four different sorting algorithms
* What is the Big O notation, and how to evaluate the time complexity of an algorithm
* How to select the best sorting algorithm for a given input
* What is a stable sorting algorithm

## More Info

### Data Structure and Functions:
* For this project you are given the following `print_array`, and `print_list` functions:
	```sh
	#include <stdlib.h>
	#include <stdio.h>

	/**
	* print_array - Prints an array of integers
	*
	* @array: The array to be printed
	* @size: Number of elements in @array
	*/
	void print_array(const int *array, size_t size)
	{
		size_t i;

		i = 0;
		while (array && i < size)
		{
			if (i > 0)
				printf(", ");
			printf("%d", array[i]);
			++i;
		}
		printf("\n");
	}
	```
	```sh
	#include <stdio.h>
	#include "sort.h"

	/**
	* print_list - Prints a list of integers
	*
	* @list: The list to be printed
	*/
	void print_list(const listint_t *list)
	{
		int i;

		i = 0;
		while (list)
		{
			if (i > 0)
				printf(", ");
			printf("%d", list->n);
			++i;
			list = list->next;
		}
		printf("\n");
	}
	```

	- Our files `print_array.c` and `print_list.c` (containing the `print_array` and `print_list` functions) will be compiled with your functions during the correction.
	- Please declare the prototype of the functions `print_array` and `print_list` in your `sort.h` header file
	- Please use the following data structure for doubly linked list:
	```sh
	/**
	* struct listint_s - Doubly linked list node
	*
	* @n: Integer stored in the node
	* @prev: Pointer to the previous element of the list
	* @next: Pointer to the next element of the list
	*/
	typedef struct listint_s
	{
		const int n;
		struct listint_s *prev;
		struct listint_s *next;
	} listint_t;
	```

* Please, note this format is used for Quiz and Task questions.

	- `O(1)`
	- `O(n)`
	- `O(n!)`
	- n square -> `O(n^2)`
	- log(n) -> `O(log(n))`
	- n * log(n) -> `O(nlog(n))`
	- n + k -> `O(n+k)`
	- …
- Please use the “short” notation (don’t use constants). Example: `O(nk)` or `O(wn)` should be written `O(n)`. If an answer is required within a file, all your answers files must have a newline at the end.

### Tests
* Here is a quick tip to help you test your sorting algorithms with big sets of random integers: [Random.org](https://www.random.org/integer-sets/)


## Description of what each files show (Tasks):
* main	--- folder that will hold the `main.c` files used as test cases for functions we'd be creating.
* sort.h	--- header file that contains all function prototypes and data structures.
* notes	--- markdown that contains thoughts and frustrations to better help me understand the algorithms.
* Files that start with:

0. [Bubble Sort](./0-bubble_sort.c) :
- Write a function that sorts an array of integers in ascending order using the [Bubble sort](https://en.wikipedia.org/wiki/Bubble_sort) algorithm.
	- Prototype: `void bubble_sort(int *array, size_t size);`
	- You’re expected to print the array after each time you swap two elements (See example below)
- Write in the file `0-O`, the big O notations of the time complexity of the Bubble sort algorithm, with 1 notation per line:
	- in the best case
	- in the average case
	- in the worst case
	```sh
	kazzywiz@Kazzywiz:~/sorting_algorithms$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 0-bubble_sort.c 0-main.c print_array.c -o bubble
	kazzywiz@Kazzywiz:~/sorting_algorithms$ ./bubble
	19, 48, 99, 71, 13, 52, 96, 73, 86, 7

	19, 48, 71, 99, 13, 52, 96, 73, 86, 7
	19, 48, 71, 13, 99, 52, 96, 73, 86, 7
	19, 48, 71, 13, 52, 99, 96, 73, 86, 7
	19, 48, 71, 13, 52, 96, 99, 73, 86, 7
	19, 48, 71, 13, 52, 96, 73, 99, 86, 7
	19, 48, 71, 13, 52, 96, 73, 86, 99, 7
	19, 48, 71, 13, 52, 96, 73, 86, 7, 99
	19, 48, 13, 71, 52, 96, 73, 86, 7, 99
	19, 48, 13, 52, 71, 96, 73, 86, 7, 99
	19, 48, 13, 52, 71, 73, 96, 86, 7, 99
	19, 48, 13, 52, 71, 73, 86, 96, 7, 99
	19, 48, 13, 52, 71, 73, 86, 7, 96, 99
	19, 13, 48, 52, 71, 73, 86, 7, 96, 99
	19, 13, 48, 52, 71, 73, 7, 86, 96, 99
	13, 19, 48, 52, 71, 73, 7, 86, 96, 99
	13, 19, 48, 52, 71, 7, 73, 86, 96, 99
	13, 19, 48, 52, 7, 71, 73, 86, 96, 99
	13, 19, 48, 7, 52, 71, 73, 86, 96, 99
	13, 19, 7, 48, 52, 71, 73, 86, 96, 99
	13, 7, 19, 48, 52, 71, 73, 86, 96, 99
	7, 13, 19, 48, 52, 71, 73, 86, 96, 99

	7, 13, 19, 48, 52, 71, 73, 86, 96, 99
	kazzywiz@Kazzywiz:~/sorting_algorithms$ 
	```
1. [Insertion sort](./1-insertion_sort_list.c) :
- Write a function that sorts a doubly linked list of integers in ascending order using the [Insertion sort](https://en.wikipedia.org/wiki/Insertion_sort) algorithm
	- Prototype: `void insertion_sort_list(listint_t **list);`
	- You are not allowed to modify the integer `n` of a node. You have to swap the nodes themselves.
	- You’re expected to print the list after each time you swap two elements (See example below)
- Write in the file `1-O`, the big O notations of the time complexity of the Insertion sort algorithm, with 1 notation per line:
	- in the best case
	- in the average case
	- in the worst case
	```sh
	kazzywiz@Kazzywiz:~/sorting_algorithms$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 1-main.c 1-insertion_sort_list.c print_list.c -o insertion
	kazzywiz@Kazzywiz:~/sorting_algorithms$ ./insertion 
	19, 48, 99, 71, 13, 52, 96, 73, 86, 7

	19, 48, 71, 99, 13, 52, 96, 73, 86, 7
	19, 48, 71, 13, 99, 52, 96, 73, 86, 7
	19, 48, 13, 71, 99, 52, 96, 73, 86, 7
	19, 13, 48, 71, 99, 52, 96, 73, 86, 7
	13, 19, 48, 71, 99, 52, 96, 73, 86, 7
	13, 19, 48, 71, 52, 99, 96, 73, 86, 7
	13, 19, 48, 52, 71, 99, 96, 73, 86, 7
	13, 19, 48, 52, 71, 96, 99, 73, 86, 7
	13, 19, 48, 52, 71, 96, 73, 99, 86, 7
	13, 19, 48, 52, 71, 73, 96, 99, 86, 7
	13, 19, 48, 52, 71, 73, 96, 86, 99, 7
	13, 19, 48, 52, 71, 73, 86, 96, 99, 7
	13, 19, 48, 52, 71, 73, 86, 96, 7, 99
	13, 19, 48, 52, 71, 73, 86, 7, 96, 99
	13, 19, 48, 52, 71, 73, 7, 86, 96, 99
	13, 19, 48, 52, 71, 7, 73, 86, 96, 99
	13, 19, 48, 52, 7, 71, 73, 86, 96, 99
	13, 19, 48, 7, 52, 71, 73, 86, 96, 99
	13, 19, 7, 48, 52, 71, 73, 86, 96, 99
	13, 7, 19, 48, 52, 71, 73, 86, 96, 99
	7, 13, 19, 48, 52, 71, 73, 86, 96, 99

	7, 13, 19, 48, 52, 71, 73, 86, 96, 99
	kazzywiz@Kazzywiz:~/sorting_algorithms$ 
	```
2. [Selection sort](./2-selection_sort.c) :
- Write a function that sorts an array of integers in ascending order using the [Selection sort](https://en.wikipedia.org/wiki/Selection_sort) algorithm
	- Prototype: `void selection_sort(int *array, size_t size);`
	- You’re expected to print the array after each time you swap two elements (See example below)
- Write in the file `2-O`, the big O notations of the time complexity of the Selection sort algorithm, with 1 notation per line:
	- in the best case
	- in the average case
	- in the worst case
	```sh
	kazzywiz@Kazzywiz:~/sorting_algorithms$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 2-main.c 2-selection_sort.c print_array.c -o select
	kazzywiz@Kazzywiz:~/sorting_algorithms$ ./select 
	19, 48, 99, 71, 13, 52, 96, 73, 86, 7

	7, 48, 99, 71, 13, 52, 96, 73, 86, 19
	7, 13, 99, 71, 48, 52, 96, 73, 86, 19
	7, 13, 19, 71, 48, 52, 96, 73, 86, 99
	7, 13, 19, 48, 71, 52, 96, 73, 86, 99
	7, 13, 19, 48, 52, 71, 96, 73, 86, 99
	7, 13, 19, 48, 52, 71, 73, 96, 86, 99
	7, 13, 19, 48, 52, 71, 73, 86, 96, 99

	7, 13, 19, 48, 52, 71, 73, 86, 96, 99
	kazzywiz@Kazzywiz:~/sorting_algorithms$ 
	```
3. [Quick sort](./3-quick_sort.c) :
- Write a function that sorts an array of integers in ascending order using the [Quick sort](https://en.wikipedia.org/wiki/Quicksort) algorithm
	- Prototype: `void quick_sort(int *array, size_t size);`
	- You must implement the `Lomuto partition` scheme.
	- The pivot should always be the last element of the partition being sorted.
	- You’re expected to print the `array` after each time you swap two elements (See example below)
- Write in the file `3-O`, the big O notations of the time complexity of the Quick sort algorithm, with 1 notation per line:
	- in the best case
	- in the average case
	- in the worst case
	```sh
	kazzywiz@Kazzywiz:~/sorting_algorithms$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 3-main.c 3-quick_sort.c print_array.c -o quick
	kazzywiz@Kazzywiz:~/sorting_algorithms$ ./quick 
	19, 48, 99, 71, 13, 52, 96, 73, 86, 7

	7, 48, 99, 71, 13, 52, 96, 73, 86, 19
	7, 13, 99, 71, 48, 52, 96, 73, 86, 19
	7, 13, 19, 71, 48, 52, 96, 73, 86, 99
	7, 13, 19, 71, 48, 52, 73, 96, 86, 99
	7, 13, 19, 71, 48, 52, 73, 86, 96, 99
	7, 13, 19, 48, 71, 52, 73, 86, 96, 99
	7, 13, 19, 48, 52, 71, 73, 86, 96, 99

	7, 13, 19, 48, 52, 71, 73, 86, 96, 99
	kazzywiz@Kazzywiz:~/sorting_algorithms$ 
	```
4. [Shell sort - Knuth Sequence](./100-shell_sort.c) :
- Write a function that sorts an array of integers in ascending order using the [Shell sort](https://en.wikipedia.org/wiki/Shellsort) algorithm, using the `Knuth sequence`
	- Prototype: `void shell_sort(int *array, size_t size);`
	- You must use the following sequence of intervals (a.k.a the Knuth sequence):
		- `n+1 = n * 3 + 1`
		- `1, 4, 13, 40, 121, ...`
	- You’re expected to print the `array` each time you decrease the interval (See example below).
- **No big O notations of the time complexity of the Shell sort (Knuth sequence) algorithm needed - as the complexity is dependent on the size of array and gap.**
	```sh
	kazzywiz@Kazzywiz:~/sorting_algorithms$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 100-main.c 100-shell_sort.c print_array.c -o shell
	kazzywiz@Kazzywiz:~/sorting_algorithms$ ./shell 
	19, 48, 99, 71, 13, 52, 96, 73, 86, 7

	13, 7, 96, 71, 19, 48, 99, 73, 86, 52
	7, 13, 19, 48, 52, 71, 73, 86, 96, 99

	7, 13, 19, 48, 52, 71, 73, 86, 96, 99
	kazzywiz@Kazzywiz:~/sorting_algorithms$ 
	```
5. [Cocktail shaker sort](./101-cocktail_sort_list.c) :
- Write a function that sorts a doubly linked list of integers in ascending order using the [Cocktail shaker sort](https://en.wikipedia.org/wiki/Cocktail_shaker_sort) algorithm
	- Prototype: `void cocktail_sort_list(listint_t **list);`
	- You are not allowed to modify the integer `n` of a node. You have to swap the nodes themselves.
	- You’re expected to print the `list` after each time you swap two elements (See example below)
- Write in the file `101-O`, the big O notations of the time complexity of the Cocktail shaker sort algorithm, with 1 notation per line:
	- in the best case
	- in the average case
	- in the worst case
	```sh
	kazzywiz@Kazzywiz:~/sorting_algorithms$  gcc -Wall -Wextra -Werror -pedantic -std=gnu89 101-main.c 101-cocktail_sort_list.c print_list.c -o cocktail
	kazzywiz@Kazzywiz:~/sorting_algorithms$ ./cocktail 
	19, 48, 99, 71, 13, 52, 96, 73, 86, 7

	19, 48, 71, 99, 13, 52, 96, 73, 86, 7
	19, 48, 71, 13, 99, 52, 96, 73, 86, 7
	19, 48, 71, 13, 52, 99, 96, 73, 86, 7
	19, 48, 71, 13, 52, 96, 99, 73, 86, 7
	19, 48, 71, 13, 52, 96, 73, 99, 86, 7
	19, 48, 71, 13, 52, 96, 73, 86, 99, 7
	19, 48, 71, 13, 52, 96, 73, 86, 7, 99
	19, 48, 71, 13, 52, 96, 73, 7, 86, 99
	19, 48, 71, 13, 52, 96, 7, 73, 86, 99
	19, 48, 71, 13, 52, 7, 96, 73, 86, 99
	19, 48, 71, 13, 7, 52, 96, 73, 86, 99
	19, 48, 71, 7, 13, 52, 96, 73, 86, 99
	19, 48, 7, 71, 13, 52, 96, 73, 86, 99
	19, 7, 48, 71, 13, 52, 96, 73, 86, 99
	7, 19, 48, 71, 13, 52, 96, 73, 86, 99
	7, 19, 48, 13, 71, 52, 96, 73, 86, 99
	7, 19, 48, 13, 52, 71, 96, 73, 86, 99
	7, 19, 48, 13, 52, 71, 73, 96, 86, 99
	7, 19, 48, 13, 52, 71, 73, 86, 96, 99
	7, 19, 13, 48, 52, 71, 73, 86, 96, 99
	7, 13, 19, 48, 52, 71, 73, 86, 96, 99

	7, 13, 19, 48, 52, 71, 73, 86, 96, 99
	kazzywiz@Kazzywiz:~/sorting_algorithms$
	```
6. [Counting sort](./102-counting_sort.c) :
- Write a function that sorts an array of integers in ascending order using the [Counting sort](https://en.wikipedia.org/wiki/Counting_sort) algorithm
	- Prototype: `void counting_sort(int *array, size_t size);`
	- You can assume that array will contain only numbers `>= 0`
	- You are allowed to use `malloc` and `free` for this task
	- You’re expected to print your `counting array` once it is set up (See example below)
		- This array is of size `k + 1` where `k` is the largest number in array
- Write in the file `102-O`, the big O notations of the time complexity of the Counting sort algorithm, with 1 notation per line:
	- in the best case
	- in the average case
	- in the worst case
	```sh
	kazzywiz@Kazzywiz:~/sorting_algorithms$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 102-main.c 102-counting_sort.c print_array.c -o counting
	kazzywiz@Kazzywiz:~/sorting_algorithms$ ./counting 
	19, 48, 99, 71, 13, 52, 96, 73, 86, 7

	0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 10

	7, 13, 19, 48, 52, 71, 73, 86, 96, 99
	kazzywiz@Kazzywiz:~/sorting_algorithms$ valgrind ./counting 
	==6148== Memcheck, a memory error detector
	==6148== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
	==6148== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
	==6148== Command: ./counting
	==6148== 
	19, 48, 99, 71, 13, 52, 96, 73, 86, 7

	0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 10

	7, 13, 19, 48, 52, 71, 73, 86, 96, 99
	==6148== 
	==6148== HEAP SUMMARY:
	==6148==     in use at exit: 0 bytes in 0 blocks
	==6148==   total heap usage: 3 allocs, 3 frees, 1,464 bytes allocated
	==6148== 
	==6148== All heap blocks were freed -- no leaks are possible
	==6148== 
	==6148== For lists of detected and suppressed errors, rerun with: -s
	==6148== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
	kazzywiz@Kazzywiz:~/sorting_algorithms$ 
	```
7. [Merge sort](./103-merge_sort.c) :
- Write a function that sorts an array of integers in ascending order using the [Merge sort](https://en.wikipedia.org/wiki/Merge_sort) algorithm
	- Prototype: `void merge_sort(int *array, size_t size);`
	- You must implement the `top-down` merge sort algorithm
		- When you divide an array into two sub-arrays, the size of the left array should always be <= the size of the right array. i.e. `{1, 2, 3, 4, 5}` -> `{1, 2}, {3, 4, 5}`
		- Sort the left array before the right array
	- You are allowed to use `printf`
	- You are allowed to use `malloc` and `free` only once (only one call)
	- Output: see example
- Write in the file `103-O`, the big O notations of the time complexity of the Merge sort algorithm, with 1 notation per line:
	- in the best case
	- in the average case
	- in the worst case
	```sh
	kazzywiz@Kazzywiz:~/sorting_algorithms$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 103-main.c 103-merge_sort.c print_array.c -o merge
	kazzywiz@Kazzywiz:~/sorting_algorithms$ ./merge 
	19, 48, 99, 71, 13, 52, 96, 73, 86, 7

	Merging...
	[left]: 19
	[right]: 48
	[Done]: 19, 48
	Merging...
	[left]: 71
	[right]: 13
	[Done]: 13, 71
	Merging...
	[left]: 99
	[right]: 13, 71
	[Done]: 13, 71, 99
	Merging...
	[left]: 19, 48
	[right]: 13, 71, 99
	[Done]: 13, 19, 48, 71, 99
	Merging...
	[left]: 52
	[right]: 96
	[Done]: 52, 96
	Merging...
	[left]: 86
	[right]: 7
	[Done]: 7, 86
	Merging...
	[left]: 73
	[right]: 7, 86
	[Done]: 7, 73, 86
	Merging...
	[left]: 52, 96
	[right]: 7, 73, 86
	[Done]: 7, 52, 73, 86, 96
	Merging...
	[left]: 13, 19, 48, 71, 99
	[right]: 7, 52, 73, 86, 96
	[Done]: 7, 13, 19, 48, 52, 71, 73, 86, 96, 99

	7, 13, 19, 48, 52, 71, 73, 86, 96, 99
	kazzywiz@Kazzywiz:~/sorting_algorithms$ 
	```
- Don't forget to check valgrind for allocated memory.
8. [Heap Sort](./104-heap_sort.c) :
- Write a function that sorts an array of integers in ascending order using the [Heap sort](https://en.wikipedia.org/wiki/Heapsort) algorithm
	- Prototype: `void heap_sort(int *array, size_t size);`
	- You must implement the `sift-down` heap sort algorithm
	- You’re expected to print the `array` after each time you swap two elements (See example below)
- Write in the file `104-O`, the big O notations of the time complexity of the Heap sort algorithm, with 1 notation per line:
	- in the best case
	- in the average case
	- in the worst case
	```sh
	kazzywiz@Kazzywiz:~/sorting_algorithms$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 104-main.c 104-heap_sort.c print_array.c -o heap
	kazzywiz@Kazzywiz:~/sorting_algorithms$ ./heap 
	19, 48, 99, 71, 13, 52, 96, 73, 86, 7

	19, 48, 99, 86, 13, 52, 96, 73, 71, 7
	19, 86, 99, 48, 13, 52, 96, 73, 71, 7
	19, 86, 99, 73, 13, 52, 96, 48, 71, 7
	99, 86, 19, 73, 13, 52, 96, 48, 71, 7
	99, 86, 96, 73, 13, 52, 19, 48, 71, 7
	7, 86, 96, 73, 13, 52, 19, 48, 71, 99
	96, 86, 7, 73, 13, 52, 19, 48, 71, 99
	96, 86, 52, 73, 13, 7, 19, 48, 71, 99
	71, 86, 52, 73, 13, 7, 19, 48, 96, 99
	86, 71, 52, 73, 13, 7, 19, 48, 96, 99
	86, 73, 52, 71, 13, 7, 19, 48, 96, 99
	48, 73, 52, 71, 13, 7, 19, 86, 96, 99
	73, 48, 52, 71, 13, 7, 19, 86, 96, 99
	73, 71, 52, 48, 13, 7, 19, 86, 96, 99
	19, 71, 52, 48, 13, 7, 73, 86, 96, 99
	71, 19, 52, 48, 13, 7, 73, 86, 96, 99
	71, 48, 52, 19, 13, 7, 73, 86, 96, 99
	7, 48, 52, 19, 13, 71, 73, 86, 96, 99
	52, 48, 7, 19, 13, 71, 73, 86, 96, 99
	13, 48, 7, 19, 52, 71, 73, 86, 96, 99
	48, 13, 7, 19, 52, 71, 73, 86, 96, 99
	48, 19, 7, 13, 52, 71, 73, 86, 96, 99
	13, 19, 7, 48, 52, 71, 73, 86, 96, 99
	19, 13, 7, 48, 52, 71, 73, 86, 96, 99
	7, 13, 19, 48, 52, 71, 73, 86, 96, 99
	13, 7, 19, 48, 52, 71, 73, 86, 96, 99
	7, 13, 19, 48, 52, 71, 73, 86, 96, 99

	7, 13, 19, 48, 52, 71, 73, 86, 96, 99
	kazzywiz@Kazzywiz:~/sorting_algorithms$ 
	```
9. [Radix sort](./105-radix_sort.c) :
- Write a function that sorts an array of integers in ascending order using the [Radix sort](https://en.wikipedia.org/wiki/Radix_sort) algorithm

	- Prototype: `void radix_sort(int *array, size_t size);`
	- You must implement the `LSD` radix sort algorithm
	- You can assume that `array` will contain only numbers `>= 0`
	- You are allowed to use `malloc` and `free` for this task
	- You’re expected to print the `array` each time you increase your `significant digit` (See example below)
	```sh
	kazzywiz@Kazzywiz:~/sorting_algorithms$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 105-main.c 105-radix_sort.c print_array.c -o radix
	kazzywiz@Kazzywiz:~/sorting_algorithms$ ./radix 
	19, 48, 99, 71, 13, 52, 96, 73, 86, 7

	71, 52, 13, 73, 96, 86, 7, 48, 19, 99
	7, 13, 19, 48, 52, 71, 73, 86, 96, 99

	7, 13, 19, 48, 52, 71, 73, 86, 96, 99
	kazzywiz@Kazzywiz:~/sorting_algorithms$ 
	```
10. [Bitonic Sort]()
- Write a function that sorts an array of integers in ascending order using the [Bitonic sort] algorithm
	- Prototype: `void bitonic_sort(int *array, size_t size);`
	- You can assume that size will be equal to `2^k`, where `k >= 0` (when array is not NULL …)
	- You are allowed to use `printf`
	- You’re expected to print the `array` each time you swap two elements (See example below)
- Write in the file `106-O`, the big O notations of the time complexity of the Bitonic sort algorithm, with 1 notation per line:
	- in the best case
	- in the average case
	- in the worst case
	```sh
	alex@/tmp/sort$ gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 106-main.c 106-bitonic_sort.c print_array.c -o bitonic
	alex@/tmp/sort$ ./bitonic
	100, 93, 40, 57, 14, 58, 85, 54, 31, 56, 46, 39, 15, 26, 78, 13

	Merging [16/16] (UP):
	100, 93, 40, 57, 14, 58, 85, 54, 31, 56, 46, 39, 15, 26, 78, 13
	Merging [8/16] (UP):
	100, 93, 40, 57, 14, 58, 85, 54
	Merging [4/16] (UP):
	100, 93, 40, 57
	Merging [2/16] (UP):
	100, 93
	Result [2/16] (UP):
	93, 100
	Merging [2/16] (DOWN):
	40, 57
	Result [2/16] (DOWN):
	57, 40
	Result [4/16] (UP):
	40, 57, 93, 100
	Merging [4/16] (DOWN):
	14, 58, 85, 54
	Merging [2/16] (UP):
	14, 58
	Result [2/16] (UP):
	14, 58
	Merging [2/16] (DOWN):
	85, 54
	Result [2/16] (DOWN):
	85, 54
	Result [4/16] (DOWN):
	85, 58, 54, 14
	Result [8/16] (UP):
	14, 40, 54, 57, 58, 85, 93, 100
	Merging [8/16] (DOWN):
	31, 56, 46, 39, 15, 26, 78, 13
	Merging [4/16] (UP):
	31, 56, 46, 39
	Merging [2/16] (UP):
	31, 56
	Result [2/16] (UP):
	31, 56
	Merging [2/16] (DOWN):
	46, 39
	Result [2/16] (DOWN):
	46, 39
	Result [4/16] (UP):
	31, 39, 46, 56
	Merging [4/16] (DOWN):
	15, 26, 78, 13
	Merging [2/16] (UP):
	15, 26
	Result [2/16] (UP):
	15, 26
	Merging [2/16] (DOWN):
	78, 13
	Result [2/16] (DOWN):
	78, 13
	Result [4/16] (DOWN):
	78, 26, 15, 13
	Result [8/16] (DOWN):
	78, 56, 46, 39, 31, 26, 15, 13
	Result [16/16] (UP):
	13, 14, 15, 26, 31, 39, 40, 46, 54, 56, 57, 58, 78, 85, 93, 100

	13, 14, 15, 26, 31, 39, 40, 46, 54, 56, 57, 58, 78, 85, 93, 100
	alex@/tmp/sort$
	```
11. [Quick Sort - Hoare Partition scheme](./107-quick_sort_hoare.c) :
- Write a function that sorts an array of integers in ascending order using the [Quick sort](https://en.wikipedia.org/wiki/Quicksort) algorithm
	- Prototype: `void quick_sort_hoare(int *array, size_t size);`
	- You must implement the `Hoare partition` scheme.
	- The pivot should always be the last element of the partition being sorted.
	- You’re expected to print the array after each time you swap two elements (See example below)
- Write in the file `107-O`, the big O notations of the time complexity of the Quick sort algorithm, with 1 notation per line:
	- in the best case
	- in the average case
	- in the worst case
	```sh
	kazzywiz@Kazzywiz:~/sorting_algorithms$ gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 107-main.c 107-quick_sort_hoare.c print_array.c -o quick
	kazzywiz@Kazzywiz:~/sorting_algorithms$ ./quick 
	19, 48, 99, 71, 13, 52, 96, 73, 86, 7

	7, 48, 99, 71, 13, 52, 96, 73, 86, 19
	7, 19, 99, 71, 13, 52, 96, 73, 86, 48
	7, 19, 13, 71, 99, 52, 96, 73, 86, 48
	7, 13, 19, 71, 99, 52, 96, 73, 86, 48
	7, 13, 19, 48, 99, 52, 96, 73, 86, 71
	7, 13, 19, 48, 71, 52, 96, 73, 86, 99
	7, 13, 19, 48, 52, 71, 96, 73, 86, 99
	7, 13, 19, 48, 52, 71, 86, 73, 96, 99
	7, 13, 19, 48, 52, 71, 73, 86, 96, 99

	7, 13, 19, 48, 52, 71, 73, 86, 96, 99
	kazzywiz@Kazzywiz:~/sorting_algorithms$ 
	```