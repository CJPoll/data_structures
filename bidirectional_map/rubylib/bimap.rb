class BidirectionalMap
	def initialize
		@keys = {}
		@vals = {}
	end

	def get key
		value = nil
		if @keys.has_key? key
			value = @keys[key]
		elsif @vals.has_key? key
			value = @vals[key]
		end
		return value
	end

	def insert key, value
		@keys[key] = value
		@vals[value] = key
		return self
	end

	def remove key
		if @keys.has_key? key
			val = @keys[key]
			@keys.delete key
			@vals.delete val
		elsif @vals.has_key? key
			val = @vals[key]
			@vals.delete key
			@keys.delete val
		end
		return self
	end
end
