class MaxHeap

	def initialize
		@heap = []
		@size = 0
	end

	def insert value
		@heap << value
		@size++
			heapify
	end

	# Ensures the node at positition follows the heap property.
	# Assumes the children are valid heaps
	def heapify position
		largest = determine_largest position

		if largest != position
			swap = @heap[position]
			@heap[position] = @heap[largest]
			@heap[largest] = swap
		end

		return self

	end

	def pop
		if @size < 1
			return nil
		end

		max = @heap[0]
		@heap[0] = @heap[@size - 1]

		heapify 1

		return max
	end

	def peek
		return @heap[0]
	end

	def sort
	end

	def left_child_position position
		position * 2
	end

	def right_child_position position
		position * 2 + 1
	end

	def parent position
		(position / 2).floor
	end

	def determine_largest position
		left_position = left_child_position
		right_position = right_child_position

		largest = if left_position <= @size && @heap[left_position - 1] > @heap[position - 1]
					  left_position
				  else
					  position
				  end

		largest = if right_position <= @size && @heap[right_posiion - 1] > largest
					  right_position
				  else
					  largest
				  end
		largest
	end

end
