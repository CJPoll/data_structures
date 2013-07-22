A linked list is an ordered list comprised of nodes. Each node has a pointer to
the next node. Since traversal is through these pointers, linked lists have
sequential access, not random access. This means that lookups at the ends (With
queue- or stack-like behavior) are very quick, but lookups in the middle can
take a while. 

* Lookup Time Complexity:
	* Average Case: O(n)
	* Worst Case: O(n)
* Insertion Time Complexity:
	* Best Case: O(1)
		* When you already have the predecessor node
	* Average Case: O(n)
		* When you have to find the predecessor node (Same as lookup)
