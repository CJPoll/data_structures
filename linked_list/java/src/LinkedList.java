package link;
import java.lang.NullPointerException;
import java.lang.RuntimeException;

public class LinkedList<T> {

	private LinkedListNode<T> head;
	private int size;

	public LinkedList() {
		this.head = null;
		this.size = 0;
	}

	public int getSize() {
		return this.size;
	}

	public T getIndex(int index) {
		LinkedListNode<T> node = getNode(index);
		return node.value;
	}

	public LinkedList<T> pushValue(T value) {
		if (value == null) {
			throw new NullPointerException();
		}

		LinkedListNode<T> node = new LinkedListNode<T>(value);

		if (this.head == null) {
			this.head = node;
		} else {
			LinkedListNode<T> prev = this.getNode(this.size - 1);
			prev.setNext(node);
		}

		this.size++;

		return this;
	}

	private LinkedListNode<T> getNode(int index) throws RuntimeException {
		if (this.head == null) {
			return null;
		}

		if (index < 0 || index > this.size) {
			System.out.println("Index: " + index);
			System.out.println("Size: " + this.size);
			throw new RuntimeException();
		}

		int current = 0;
		LinkedListNode<T> currentNode = this.head;

		while (current < index) {
			currentNode = currentNode.getNext();
			current++;
		}

		return currentNode;
	}

	private LinkedList<T> shiftRight(int index) {
		return this;
	}

	private LinkedList<T> shiftLeft(int index) {
		return this;
	}

	private class LinkedListNode<T> {
		private T value;
		private LinkedListNode<T> next;

		public LinkedListNode(T value) {
			this.value = value;
			this.next = null;
		}

		public T getValue() {
			return this.value;
		}

		public LinkedListNode<T> getNext() {
			return this.next;
		}

		public LinkedListNode<T> setNext(LinkedListNode<T> node) {
			this.next = node;
			return this;
		}
	}
}
