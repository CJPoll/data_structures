require('../../doubly_linked_list/ruby/dblinkedlist.rb')
class Stack
	attr_reader :size
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
		@list.peek
	end

	def pop
		@list.pop
	end
end
