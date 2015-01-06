module DS
	module BST
		class BST
			attr_reader :size

			def initialize
				@root = nil
				@size = 0
			end

			def add value
				if @root.nil?
					node = Node.new(value)
					@root = node
					@size += 1
				else
					unless self.include? value
						@root.add(value)
						@size += 1
					end
				end
			end

			def include? value
				if @root.nil?
					return false
				else
					!(@root.search_for(value).nil?)
				end
			end
		end
	end
end

module DS
	module BST
		private
		class Node
			attr_accessor :left, :right, :value

			def initialize value
				@@sentinel ||= nil

				@value = value

				@left = @@sentinel
				@right = @@sentinel
			end

			def is_value? value
				return @value == value
			end

			def can_search_for? value
				return !(next_node(value) == @@sentinel)
			end

			def search_for value
				return self if self.is_value?(value)
				return next_node(value).search_for(value) if self.can_search_for?(value)
				return nil
			end

			def add value
				return if self.is_value?(value)
				return next_node(value).add(value) unless next_node(value).nil?
				add_child(value)
			end

			private
			def next_node value
				if next_direction(value) == :left
					self.left
				else
					self.right
				end
			end

			def add_child value
				node = Node.new(value)

				if next_direction(value) == :left
					self.left = node
				else
					self.right = node
				end
			end

			def next_direction value
				if @value > value
					:left
				else
					:right
				end
			end
		end
	end
end
