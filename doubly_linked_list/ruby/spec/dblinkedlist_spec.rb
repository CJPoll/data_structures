require('./dblinkedlist.rb')

describe "DB Linked List" do
	before :each do 
		@list = DBLinkedList.new
	end

	it "should create a doubly linked list"  do
		@list.class.name.should == "DBLinkedList"

		tail = @list.instance_variable_get :@tail
		head = @list.instance_variable_get :@head
		size = @list.instance_variable_get :@size

		tail.class.name.should 	== "Node"
		tail.value.should 		== nil
		tail.previous.should 	== head
		tail.next.should 		== nil

		head.class.name.should 	== "Node"
		head.value.should 		== nil
		head.previous.should 	== nil
		head.next.should 		== tail
	end

	it "should push a value onto the doubly linked list" do
		list = @list.push(5)
		list.should == @list

		tail = @list.instance_variable_get :@tail
		head = @list.instance_variable_get :@head
		test = head.next

		test.should_not == nil
		test.value.should == 5
		test.next.should == tail
		test.previous.should == head

		tail.previous.should == test
		head.next.should == test

		@list.size.should == 1
	end

	it "should return nil if the index is greater than the size" do
		@list.push(5).push(6)
		@list.size.should == 2

		@list.get(2).should == nil
	end

	it "should return nil if the index is less than 0" do
		@list.push 5
		@list.get(-1).should == nil
	end

	it "should retrieve a value from the doubly linked list" do
		@list.push(5)
		value = @list.get 0
		value.should == 5
	end

	it "should retrieve a value even if there is more than one element" do
		## As a side note, this also tests that the travers_list_backward
		## functionality is working properly, as the index is in the second half
		## of the linked list.
		@list.push(5).push(6).push(3)
		value = @list.get 2
		value.should == 3
	end
end
