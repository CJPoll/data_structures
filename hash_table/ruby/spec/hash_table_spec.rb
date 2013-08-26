require('./hash_table.rb')
describe "HashTable" do
	before :each do
		@table = HashTable.new
	end

	it "should create a new, properly initialized HashTable" do
		@table.nil?.should == false
		@table.size.should == 0
	end

	it "should map a key to a value" do
		@table.put :key, :value
		@table.size.should == 1
	end
end
