## QuickSort

* The Quick Sort algorithm divides the array into smaller partitions using the [Lomuto partition](https://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort/) scheme, and then recursively sorts each partition. The use of the swap function and printing the array at each step allows for visualization of the sorting process. This results in an efficient and in-place sorting algorithm.

* Using helper functions seem to be the reasonable way to go about it. For readability and a better visual code flow:

1. `swap` function:
	- `swap` is a helper function that takes two integer pointers, `a` and `b`, and swaps the values they point to. Used it for swapping elements in the array.

2. `lomuto_partition` function:
	- `lomuto_partition` takes four parameters: `array`, `low`, `high`, and `size`. It partitions the array using the Lomuto partition scheme and returns the index of the pivot element.
	- `low` and `high` are the indices specifying the range of the array to be partitioned.
	- The function selects the pivot element as the last element in the given range (i.e., `array[high]`).
	- It initializes `i` to `low - 1`, which represents the index where elements less than the pivot will be placed.
	- A loop iterates from `low` to `high - 1` (inclusive) to compare each element with the pivot.
	- If an element is less than the pivot, it is swapped with the element at index `i + 1`, and `i` is incremented.
	- After each swap, the array is printed to visualize the partitioning process.
	- Finally, the pivot is swapped with the element at index `i + 1`, placing the pivot in its correct position within the partition.
	The function returns the index `i + 1` as the new pivot index.

3. `quick_sort_recursive` function:
	- `quick_sort_recursive` is a recursive function that sorts the array using the quicksort algorithm.
	- It takes four parameters: `array`, `low`, `high`, and `size`. `low` and `high` specify the range of the array to be sorted.
	- Inside this function, it first checks if `low` is less than `high`, which ensures that there is more than one element in the range to be sorted.
	- It calls `lomuto_partition` to partition the array and retrieve the pivot index.
	- Then, it recursively sorts the subarrays on both sides of the pivot index: the elements before the pivot and the elements after the pivot.

4. `quick_sort` function:
	- quick_sort is the main entry point for the quicksort algorithm.
	- It takes two parameters: array and size.
	- It checks if the input array is NULL or if the size is less than 2 (no sorting needed for 0 or 1 element), and if so, it returns early.
	- Otherwise, it calls the quick_sort_recursive function to start the sorting process from the entire array.
