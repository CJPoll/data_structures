require ('./queue.rb')

describe "Queue" do
	before :each do
		@queue = Queue.new
	end

	it "should create a new queue and properly initialize it" do 
		@queue.nil?.should == false
		@queue.class.name.should == "Queue"
		@queue.size.should == 0
	end

	it "should push a value to the start of the queue and return the queue" do
		queue = @queue.push 5
		queue.should == @queue
		@queue.size.should == 1
	end
	
	it "should show the value at the end of the queue and not remove it on peek" do
		@queue.push 5
		@queue.peek.should == 5
		@queue.size.should == 1
	end

	it "should show the value as a FIFO structure on peek" do
		@queue.push(5).push(6)
		@queue.peek.should == 5
		@queue.size.should == 2
	end

	it "should remove and return the value at the end of the queue on pop as a FIFO structure" do
		@queue.push(5).push(6)
		@queue.pop.should == 5
		@queue.size.should == 1
	end
end
