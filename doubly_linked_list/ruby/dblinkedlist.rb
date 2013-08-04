class Node
	attr_accessor :value, :next, :previous
	def initialize value = nil, _next = nil, previous = nil
		@value = value
		@next = _next
		@previous = previous
	end
end

class DBLinkedList
	attr_accessor :size

	def initialize
		head = Node.new nil, nil, nil
		tail = Node.new nil, nil, head
		head.next = tail
		@head = head
		@tail = tail
		@size = 0
	end

	def insert value, index
		@size += 1
		self
	end

	def get index
		return nil if index >= @size
		return nil if index < 0
		## -1 represents the "head" index; 
		## 0 would represent the element itself
		if index <= @size/2
			traverse_list_forward(index, -1, @head).value 
		else
			traverse_list_backward(index, @size, @tail).value
		end
	end

	def remove index
		removing = traverse_list index
		removing.previous.next = removing.next
		removing.next.previous = removing.previous
		@size -= 1
		self
	end

	def push value
		node = Node.new value, @tail, nil
		@tail.previous.next = node
		node.previous = @tail.previous
		@tail.previous = node

		@size += 1
		self
	end

	def peek
		@tail.previous.value
	end

	def pop
		pop = @tail.previous
		pop.previous.next = @tail
		pop.next.previous = pop.previous
		pop
	end

	private

	def traverse_list_forward index, current, node
		if index > current
			traverse_list_forward index, current += 1, node.next 
		else
			node
		end
	end

	def traverse_list_backward index, current, node
		if index < current
			traverse_list_backward index, current -= 1, node.previous
		else
			node
		end
	end

	## For sorting
	def shift_right node
	end

	def shift_left node
	end

	def insert_node node
	end

	def remove_node node
	end
end
