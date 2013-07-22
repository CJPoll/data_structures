require('./linkedlist.rb')

describe "Linked List" do
	before :each do
		@list = LinkedList.new
	end

	it "should create a new linked list" do
		@list.should_not == nil
	end

	it "should set size to 0" do
		@list.size.should == 0
	end

	it "should set a nil head on creation" do
		@list.head.should == nil
	end

	it "should setup a node properly" do
		value = :value
		_next = :next

		node = @list.send :setup_node, :value, :next

		node.next.should == :next
		node.value.should == :value
	end

	it "should insert a new node/value into the list" do
		@list.push 5

		@list.head.value.should == 5
	end

	it "should get the final element of the list" do
		@list.push 5
		@list.push 6

		five = @list.get 0
		six  = @list.get 1

		five.should == 5
		six.should  == 6
	end

	it "should insert an element without losing the rest of the list" do
		@list.push 5
		@list.push 6
		@list.insert 9, 1

		five = @list.get 0
		nine = @list.get 1
		six  = @list.get 2
		
		nine.should == 9
		six.should  == 6
	end

	it "should shift the head node to the right without losing the rest of the list" do
		@list.push 5
		@list.push 6
		@list.shift_right 0

		six = @list.get 0
		six.should == 6

		five = @list.get 1
		five.should == 5
	end

	it "should shift a central node to the right without losing the rest of the list" do
		@list.push 5
		@list.push 6
		@list.push 7
		@list.push 8

		@list.shift_right 1

		five = @list.get 0
		five.should == 5

		seven = @list.get 1
		seven.should == 7

		six = @list.get 2
		six.should == 6
	end

	it "should delete an element without losing the rest of the list" do
		@list.push 5
		@list.push 7
		@list.push 6

		@list.delete 1

		six = @list.get 1

		six.should == 6
	end
end

describe "Linked List Node" do
	before :each do
		@node = LinkedListNode.new
	end

	it "should create a linked list node" do
		@node.should_not == nil
	end

	it "should have a nil 'next' when created" do
		@node.next.should == nil
	end

	it "should have a default nil 'value' when created" do
		@node.value.should == nil
	end

	it "should set the 'value' when created" do
		@node = LinkedListNode.new :value
		@node.value.should == :value
	end

	it "should set 'value' & 'next' when created" do
		@node = LinkedListNode.new :value, :next
		@node.value.should == :value
		@node.next.should == :next
	end

	it "should set 'next' to another node" do
		node2 = LinkedListNode.new
		@node.next = node2
		@node.next.should == node2
	end

	it "should set 'value' to :value" do
		@node.next = :value
		@node.next.should == :value
	end
end
