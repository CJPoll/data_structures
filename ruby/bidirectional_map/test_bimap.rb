#!/usr/bin/env ruby
require './bimap.rb'

bimap = BidirectionalMap.new
bimap.insert "Key", "Value"
puts bimap.get "Key"
puts bimap.get "Value"
bimap.remove "Key"
puts bimap.get "Key"
puts bimap.get "Value"
bimap.insert "Key", "Value"
puts bimap.get "Key"
puts bimap.get "Value"
bimap.remove "Value"
puts bimap.get "Key"
puts bimap.get "Value"
