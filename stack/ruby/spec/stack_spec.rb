require('./stack.rb')
describe "Stack" do
	before :each do
		@stack = Stack.new
	end

	it "should create a stack and properly initialize it" do
		@stack.nil?.should == false
		@stack.size.should == 0
		@stack.instance_variable_get(:@list).nil?.should == false
	end

	it "should push a value on the top of the stack and return the stack" do
		stack = @stack.push 5
		stack.should == @stack
		@stack.size.should == 1
	end

	it "should show the top value without removing it on peek" do
		@stack.push 5
		@stack.peek.should == 5
		@stack.size.should == 1
	end

	it "should remove & show the top value on pop" do
		@stack.push 5
		@stack.pop.should == 5
		@stack.size.should == 0
	end
end
