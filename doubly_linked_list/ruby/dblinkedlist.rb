class Node
	attr_accessor :value, :next, :previous
	def initialize value = nil, _next = nil, previous = nil
		@value = value
		@next = _next
		@previous = previous
	end
end

class DBLinkedList
	attr_reader :size

	def initialize
		head = Node.new nil, nil, nil
		tail = Node.new nil, nil, head
		head.next = tail
		@head = head
		@tail = tail
		@size = 0
	end

	def insert value, index
		return nil if index > @size
		return nil if index < 0

		previous = get_node(index - 1)

		node = Node.new value, previous.next, previous
		previous.next.previous = node
		previous.next = node

		@size += 1
		self
	end

	def get index
		return nil if index >= @size
		return nil if index < 0

		get_node(index).value
	end

	def remove index
		removing = get_node index
		removing.previous.next = removing.next
		removing.next.previous = removing.previous
		@size -= 1
		self
	end

	def push value
		insert value, @size
	end

	def peek
		@tail.previous.value
	end

	def pop
		pop = @tail.previous
		remove @size - 1
		pop.value
	end

	private

	def get_node index
		## -1 represents the "head" dummy index; 
		## 0 would represent the element itself
		if index <= @size/2
			traverse_list_forward(index, -1, @head)
		else
			traverse_list_backward(index, @size, @tail)
		end
	end

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
end
