import junit.framework.*;
import java.lang.reflect.*;
public class TestDoublyLinkedList extends TestCase {
	public TestDoublyLinkedList(String name) {
		super(name);
	}

	private DoublyLinkedList<Integer> list;

	@Override
	protected void setUp() throws Exception {
		super.setUp();
		this.list = new DoublyLinkedList<Integer>();
	}

	public void testCreation() {
		assertNotNull(list);
		assertEquals(0, list.getSize());

		try {
			accessPrivateField("head");
			accessPrivateField("tail");
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}

		assertNotNull(list.head);
		assertNotNull(list.tail);
	}

	public void testInsert() {
		list.insert(5, 0);

		assertEquals(1, list.getSize());
	}

	public void testGet() {
		list.insert(5,0);
		assertEquals(1, list.getSize());

		int value = list.get(0);
		assertEquals(5, value);
	}

	public void testRemove() {
		list.insert(5,0).insert(6,1).insert(7,2);
		assertEquals(3, list.getSize());

		int value = list.remove(1);
		assertEquals(6, value);
		assertEquals(2, list.getSize());
	}

	public void testPush() {
		list.push(5);
		assertEquals(1, list.getSize());

		int value = list.get(0);
		assertEquals(5, value);
	}

	public void testPeek() {
		list.push(5);
		int value = list.peek();
		assertEquals(5, value);
		assertEquals(1, list.getSize());
	}

	public void testPop() {
		list.push(5);
		int value = list.pop();
		assertEquals(5, value);
		assertEquals(0, list.getSize());
	}


	private void accessPrivateField(String field) throws Exception {
		Field headField = list.getClass().getDeclaredField(field);
		headField.setAccessible(true);
	}
}
