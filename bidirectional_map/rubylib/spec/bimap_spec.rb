require './bimap.rb'

describe "BidirectionalMap" do
	before :each do
		@map = BidirectionalMap.new
	end

	it "should insert key & val into hashes" do
		keys = @map.instance_variable_get :@keys
		vals = @map.instance_variable_get :@vals

		keys.should == {}
		vals.should == {}

		newmap = @map.insert :key, :value

		keys = @map.instance_variable_get :@keys
		vals = @map.instance_variable_get :@vals

		keys.should == {key: :value}
		vals.should == {value: :key}
		newmap.should == @map
	end

	it "should remove key & val from hashes" do
		@map.insert :key, :value
		newmap = @map.remove :key

		keys = @map.instance_variable_get :@keys
		vals = @map.instance_variable_get :@vals

		keys.should == {}
		vals.should == {}
		newmap.should == @map
	end

	it "should return the value associated with a key" do
		@map.insert :key, :value
		
		value = @map.get :key

		value.should == :value
	end

	it "should return the key associated with a value" do
		@map.insert :key, :value
		
		value = @map.get :value

		value.should == :key
	end
end
