class BST
	class Node

		attr_accessor :key, :value, :parent, :left, :right

		def initialize key = nil, value = nil
			@key = key
			@value = value
			@parent = nil
			@left = nil
			@right = nil
		end

		def left? 
			return self == @parent.left if @parent
			return nil
		end

		def right? 
			return self == @parent.right if @parent
			return nil
		end

		def nil_key?
			@key.equal? nil
		end
	end

	attr_reader :size
	def initialize
		@root = Node.new
		@size = 0
	end

	def insert key, value
		node = traverse @root, key

		node.key = key
		node.value = value

		left = Node.new
		node.left = left
		left.parent = node

		right = Node.new
		right.parent = node
		node.right = right

		@size += 1
		self
	end

	def contains? value
		false if @root == nil
		node = traverse @root, value
		node.key.nil? != true
	end

	# Returns nil if no such key
	def retrieve key
		node = traverse @root, key
		node.key
	end

	def remove key
		node = traverse @root, key
		raise "No such node" if node.key.nil? == true
		raise "Node still has children" unless node.left.nil_key? and node.right.nil_key?
		if node.left?
			node.parent.left = Node.new
		elsif node.right?
			node.parent.right = Node.new
		else
			@root = Node.new
		end

		@size -= 1
	end

	def empty?
		@size == 0
	end

	private

	def traverse node, key
		return node if node.key == key || node.nil_key?
		if key < node.key
			traverse node.left, key
		else
			traverse node.right, key
		end
	end
end
