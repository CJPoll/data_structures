require("../../doubly_linked_list/ruby/dblinkedlist.rb")

class Queue
	def initialize
		@list = DBLinkedList.new
	end

	def size
		@list.size
	end

	def push value
		@list.push value
		self
	end

	def peek
		@list.get 0
	end

	def pop
		value = @list.get 0
		@list.remove 0
		value
	end
end
