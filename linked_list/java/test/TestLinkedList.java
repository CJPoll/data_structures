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

		int value = list.getIndex(1);
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
}
