class LinkedList
	attr_accessor :head, :size
	def initialize
		@head = nil
		@size = 0
	end

	def insert value, index = 0
		node = setup_node value
		if @size == 0
			@head = node
		else
			prevnode = get_node index - 1
			node.next = prevnode.next
			prevnode.next = node
		end
		@size += 1
	end

	def push value
		insert value, @size
	end

	def get index
		node = get_node index
		node.value
	end

	def delete index
		return nil if @head == nil
		return nil if index < 0
		return nil if index >= @size
		@head = head.next if index == 0
		prevnode = get_node index - 1
		prevnode.next = prevnode.next.next
	end

	private

	def get_node index
		return nil if @head == nil
		traverse_list @head, 0, index
	end

	def setup_node value = nil, _next = nil
		LinkedListNode.new value, _next
	end

	def traverse_list node, current_index, desired_index
		return nil if node == nil
		return node if current_index == desired_index

		traverse_list node.next, current_index + 1, desired_index
	end

	def add_node new_node, current_node, insert_index, current_index
		if insert_index == current_index
			new_node.next = current_node.next
			current_node.next = new_node
		elsif index_index > current_index
			return nil
		end
		add_node new_node, current_node.next, insert_index, current_index + 1
	end
end

class LinkedListNode
	attr_accessor :next, :value
	def initialize value = nil, _next = nil
		@next = _next
		@value = value
	end
end

