require('./src/bst.rb')
describe "Binary Search Tree" do

	before :each do
		@bst = BST.new
	end

	it "should properly initialize" do
		@bst.nil?.should == false
		@bst.size.should == 0
	end

	it "should properly add a node to an empty tree" do
		@bst.insert 5, 5
		root = @bst.instance_variable_get(:@root)
		root.key.should == 5
		root.value.should == 5
		@bst.size.should == 1
	end

	it "should recognize a value is contained in root" do
		@bst.insert 5, 5
		@bst.contains?(5).should == true
	end

	it "should recognize if a value isn't contained in an empty list" do
		@bst.contains?(5).should == false
	end

	it "should recognize that a value isn't in the tree" do
		@bst.insert 5, 5
		@bst.contains?(6).should == false
	end

	it "should properly insert a smaller node into a non-empty tree (< root)" do
		@bst.insert 5, 5
		@bst.insert 4, 4

		root = @bst.instance_variable_get(:@root)
		@bst.size.should == 2
		root.left.key.should == 4
	end

	it "should properly insert a smaller node into a non-empty tree (> root)" do
		@bst.insert 5, 5
		@bst.insert 6, 6

		root = @bst.instance_variable_get(:@root)
		@bst.size.should == 2
		root.right.key.should == 6
	end

	it "should properly remove root in tree of size 1" do
		@bst.insert 5, 5
		@bst.remove 5

		@bst.size.should == 0
		root = @bst.instance_variable_get(:@root)
		root.nil?.should == false
		root.key.nil?.should == true
	end

	it "should properly remove a child smaller than root" do
		root = @bst.instance_variable_get(:@root)
		root.key.nil?.should == true
		@bst.insert(5, 5).insert(4, 4)
		root.nil?.should == false
		root.key.nil?.should == false
		@bst.remove 4

		@bst.size.should == 1
		root.key.nil?.should == false
		root.left.key.should == nil
	end

	it "should properly remove a child larger than root" do
		@bst.insert(5, 5).insert(6, 6)
		@bst.remove 6

		@bst.size.should == 1
		root = @bst.instance_variable_get(:@root)
		root.key.nil?.should == false
		root.right.key.should == nil
	end

	it "should fail to remove a node that still has children" do
		@bst.insert(5,5).insert(4, 4).insert(6, 6)
		@bst.size.should == 3

		expect {@bst.remove 5}.to raise_error("Node still has children")
		@bst.size.should == 3
	end

	it "should fail to remove a non-existent node" do
		expect {@bst.insert(5, 5).remove(4)}.to raise_error("No such node")
		@bst.size.should == 1
	end
end
