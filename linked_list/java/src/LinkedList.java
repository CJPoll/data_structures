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

	public T getValue(int index) {
		LinkedListNode<T> node = getNode(index);
		return node.value;
	}

	public LinkedList<T> insert(T value, int index) {
		if (index > this.size) {
			throw new RuntimeException("No such index");
		}

		LinkedListNode<T> node = new LinkedListNode<T>(value);

		if (index == 0) {
			node.setNext(this.head);
			this.head = node;
		} else {
			LinkedListNode<T> previous = getNode(index - 1);
			node.setNext(previous.getNext());
			previous.setNext(node);
		}

		return this;
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

	public LinkedList<T> mergeSort() {
		mergeSort(this);
		return this;
	}

	private LinkedList<T> mergeSort(LinkedList<T> list) {
		return list;
	}

	public LinkedList<T> bubbleSort() {
		// A list of length 1 or 0 is already sorted
		if (this.size <= 1) {
			return this;
		}

		boolean hasChanged = false;

		do {
			hasChanged = false;
			int currentIndex = 0;
			LinkedListNode<T> current = this.head;
			while (current.getNext() != null) {
				Comparable currentValue = (Comparable)current.getValue();
				Comparable nextValue = (Comparable)current.getNext().getValue();
				if (currentValue.compareTo(nextValue) > 0) {
					shiftRight(currentIndex);
					hasChanged = true;
				} else {
					current = current.getNext();
				}
				currentIndex++;
			}
		} while (hasChanged);

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
		// Can't shift the last node right!
		if (index >= this.size - 1 || index < 0) {
			throw new RuntimeException();
		}

		if (index == 0) {
			LinkedListNode<T> temp = this.head;
			this.head = temp.getNext();
			temp.setNext(this.head.getNext());
			this.head.setNext(temp);
		} else {
			LinkedListNode<T> previous = getNode(index - 1);
			LinkedListNode<T> shifting = previous.getNext();
			LinkedListNode<T> next = shifting.getNext();
			LinkedListNode<T> tail = next.getNext();

			previous.setNext(next);
			shifting.setNext(tail);
			next.setNext(shifting);
		}

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
