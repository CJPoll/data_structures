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

	it "should enqueue a value to the start of the queue and return the queue" do
		queue = @queue.enqueue 5
		queue.should == @queue
		@queue.size.should == 1
	end
	
	it "should show the value at the end of the queue and not remove it on peek" do
		@queue.enqueue 5
		@queue.peek.should == 5
		@queue.size.should == 1
	end

	it "should show the value as a FIFO structure on peek" do
		@queue.enqueue(5).enqueue(6)
		@queue.peek.should == 5
		@queue.size.should == 2
	end

	it "should remove and return the value at the end of the queue on dequeue as a FIFO structure" do
		@queue.enqueue(5).enqueue(6)
		@queue.dequeue.should == 5
		@queue.size.should == 1
	end
end
