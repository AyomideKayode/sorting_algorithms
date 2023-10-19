## Insertion Sort

* The Insertion Sort algorithm works by taking one element at a time from the unsorted portion of the list and inserting it into its correct position in the sorted portion of the list. This process continues until the entire list is sorted in ascending order. The use of a doubly linked list makes it easy to perform swaps and maintain the correct pointers during the sorting process.

- To explain the code:
1. `insertion_sort_list` is a function that takes a double pointer to a linked list, `listint_t **list`, as its parameter. The double pointer is used because the function may need to modify the head of the linked list if elements are swapped.

2. It begins with several checks to ensure the input list is valid and not empty. If `list` is `NULL`, or the list is empty (i.e., `*list is NULL`), or the list has only one element (i.e., `(*list)->next` is `NULL`), the function returns early because there is nothing to sort.

3. The function then initializes two pointers, `current` and `sorted`. `current` is used to traverse the list from the second element to the end, and `sorted` is used to track the element being considered for insertion.

4. The outer loop, controlled by `while (current)`, iterates through the list starting from the second element.

5. Inside the outer loop, the `sorted` element is compared to its predecessor (i.e., `sorted->prev`) in a nested loop:

	- The inner loop (`while (sorted->prev && sorted->n < sorted->prev->n)`) continues as long as sorted is smaller than its predecessor, and there's a predecessor to compare.

	- If `sorted` is smaller than its predecessor, a swap is performed:

		- `temp` is used as a temporary pointer to the predecessor of sorted.

		- The pointers are adjusted to perform the swap:

			- `sorted->next` is connected to `temp`.
			- `temp->next` is set to `sorted`.
		- This effectively moves `sorted` to its correct position in the `sorted` portion of the list.

		- The previous and next pointers of `sorted` and `temp` are updated to maintain the doubly linked list structure.

		- If `sorted` has a predecessor (`sorted->prev`), the next pointer of `sorted->prev` is updated to point to `sorted`. Otherwise, if `sorted` has no predecessor, it means `sorted` is now the new head of the list, so `*list` is updated to point to `sorted`.

	- After each swap, the `print_list` function is called to print the state of the list, allowing us to visualize the sorting process at each step.

6. The process continues until the outer loop has traversed the entire list, effectively sorting it.

- [Further reading](https://en.wikipedia.org/wiki/Insertion_sort)
