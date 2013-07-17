class RSpecGreeter
	def greet
		return "Hello World!"
	end

	def hello
		return 'hi!'
	end
end

describe "RSpec Greeter" do
	it "should say 'Hello World!' when it reeives the greet() message" do
		greeter = RSpecGreeter.new
		greeting = greeter.greet
		greeting.should == "Hello World!"
	end

	it "should say 'hi!' when it receives the hello message" do
		greeter = RSpecGreeter.new
		greeting = greeter.hello
		greeting.should == "hi!"
	end
end
