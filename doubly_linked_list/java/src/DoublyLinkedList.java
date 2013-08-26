public class DoublyLinkedList<T> { 

	int size;
	Node<T> head;
	Node<T> tail;

	public DoublyLinkedList() {
		size = 0;
		this.head = new Node<T>(null, null, null);
		this.tail = new Node<T>(null, null, null);

		this.head.next = this.tail;
		this.tail.previous = this.head;
	}

	public T get(int index) {
		return this.getNode(index).value;
	}

	public int getSize() {
		return this.size;
	}

	public DoublyLinkedList<T> insert(T value, int index) {
		if (index > size) return null;
		if (index < 0 ) return null;

		Node<T> previous = getNode(index - 1);
		Node<T> next = previous.next;

		Node<T> node = new Node<T>(value, next, previous);

		next.previous = node;
		previous.next = node;
		
		this.size++;
		return this;
	}

	public T remove(int index) {
		if (index > size) return null;
		if (index < 0) return null;

		Node<T> previous = getNode(index - 1);
		Node<T> node = previous.next;
		Node<T> next = node.next;

		previous.next = next;
		next.previous = previous;

		this.size--;

		return node.value;
	}

	public DoublyLinkedList<T> push(T value) {
		return this.insert(value, 0);
	}

	public T peek() {
		if (size < 1) return null;
		return this.head.next.value;
	}

	public T pop() {
		T value = get(0);
		this.remove(0);
		return value;
	}

	private Node<T> getNode(int index) {
		if (index > this.size) return null;
		return traverseListForward(this.head, -1, index);
	}

	private Node<T> traverseListForward(Node<T> node, int currentIndex, int index) {
		if (currentIndex > index) return null;
		if (currentIndex < index) return traverseListForward(node.next, ++currentIndex, index);
		return node;
	}

	private class Node<T> {
		public T value;
		public Node<T> next;
		public Node<T> previous;
		
		protected Node(T value, Node<T> next, Node<T> previous) {
			this.value = value;
			this.next = next;
			this.previous = previous;
		}
	}
} 
