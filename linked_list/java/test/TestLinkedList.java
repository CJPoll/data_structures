import junit.framework.*;
import link.LinkedList;
import java.lang.reflect.*;

public class TestLinkedList extends TestCase {
	public TestLinkedList(String name) {
		super(name);
	}

	public static void testGetSize() {
		LinkedList<Integer> list = new LinkedList<Integer>();
		list.pushValue(4);
		list.pushValue(8);
		list.pushValue(9);

		int size = list.getSize();
		assertEquals(3, size);
	}

	public static void testGetIndex() {
		LinkedList<Integer> list = new LinkedList<Integer>();
		list.pushValue(4);
		list.pushValue(8);
		list.pushValue(9);

		int value = list.getValue(1);
		assertEquals(8, value);
	}

	public static void testPushValue() {
		LinkedList<Integer> list = new LinkedList<Integer>();
		list.pushValue(45);

		try {
			Field headField = list.getClass().getDeclaredField("head");
			headField.setAccessible(true);

			Object head = headField.get(list);

			Field field = head.getClass().getDeclaredField("value");
			field.setAccessible(true);

			Object value = field.get(head);
			assertEquals(new Integer(45), value);
		} catch (Exception e) {
			System.out.println(e.getMessage());
			fail(e.getMessage());
		}
	}

	public static void testInsertValueMiddle() {
		LinkedList<Integer> list = new LinkedList<Integer>();

		list.pushValue(0);
		list.pushValue(1);
		list.pushValue(2);
		list.pushValue(3);
		list.pushValue(4);

		list.insert(5, 1);

		int value = list.getValue(1);
		assertEquals(5, value);
	}

	public static void testInsertValueHead() {
		LinkedList<Integer> list = new LinkedList<Integer>();

		list.pushValue(0);
		list.pushValue(1);
		list.pushValue(2);
		list.pushValue(3);
		list.pushValue(4);

		list.insert(5, 0);

		int value = list.getValue(0);
		assertEquals(5, value);
	}

	public static void testShiftRightHead() {
		LinkedList<Integer> list = new LinkedList<Integer>();

		list.pushValue(0);
		list.pushValue(1);

		try {
			Method shiftRight = list.getClass().getDeclaredMethod("shiftRight", int.class);
			shiftRight.setAccessible(true);
			shiftRight.invoke(list, 0);
		} catch (Exception e) {
			fail("Problem getting private method \"shiftRight\"" + "Exception: " + e.getMessage());
		}

		int head = list.getValue(0);
		assertEquals(1, head);

		int second = list.getValue(1);
		assertEquals(0, second);
	}

	public static void testShiftRightMiddle() {
		LinkedList<Integer> list = new LinkedList<Integer>();

		list.pushValue(0);
		list.pushValue(2);
		list.pushValue(1);

		try {
			Method shiftRight = list.getClass().getDeclaredMethod("shiftRight", int.class);
			shiftRight.setAccessible(true);
			shiftRight.invoke(list, 1);
		} catch (Exception e) {
			fail("Problem getting private method \"shiftRight\"" + "Exception: " + e.getMessage());
		}

		int head = list.getValue(0);
		assertEquals(0, head);

		int second = list.getValue(1);
		assertEquals(1, second);

		int last = list.getValue(2);
		assertEquals(2, last);
	}

	public static void testBubbleSortEmpty() {
		LinkedList<Integer> list = new LinkedList<Integer>();
		try {
			list.bubbleSort();
		} catch (Exception e) {
			fail();
		}
	}

	public static void testBubbleSortOne() {
		LinkedList<Integer> list = new LinkedList<Integer>();

		list.pushValue(1);

		list.bubbleSort();
		int value = list.getValue(0);
		assertEquals(1, value);
	}

	public static void testBubbleSortTwo() {
		LinkedList<Integer> list = new LinkedList<Integer>();
		list.pushValue(1);
		list.pushValue(0);

		list.bubbleSort();

		int value = list.getValue(0);
		assertEquals(0, value);
	}

	public static void testBubbleSort() {
		LinkedList<Integer> list = new LinkedList<Integer>();

		list.pushValue(4);
		list.pushValue(3);
		list.pushValue(2);
		list.pushValue(1);
		list.pushValue(0);

		list.bubbleSort();

		int value = list.getValue(0);
		assertEquals(0, value);

		int valueOne = list.getValue(1);
		assertEquals(1, valueOne);

		int valueTwo = list.getValue(2);
		assertEquals(2, valueTwo);

		int valueThree = list.getValue(3);
		assertEquals(3, valueThree);

		int valueFour = list.getValue(4);
		assertEquals(4, valueFour);
	}

	public static void testMergeSort() {
		LinkedList<Integer> list = new LinkedList<Integer>();

		list.pushValue(4);
		list.pushValue(3);
		list.pushValue(2);
		list.pushValue(1);
		list.pushValue(0);

		list.mergeSort();

		int value = list.getValue(0);
		assertEquals(0, value);

		int valueOne = list.getValue(1);
		assertEquals(1, valueOne);

		int valueTwo = list.getValue(2);
		assertEquals(2, valueTwo);

		int valueThree = list.getValue(3);
		assertEquals(3, valueThree);

		int valueFour = list.getValue(4);
		assertEquals(4, valueFour);
	}
}
