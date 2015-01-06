require 'spec_helper'

include DS::BST

describe BST do
	subject {BST.new}

	it 'creates an instance of BST and properly initializes it' do
		expect(subject.nil?).to be false
		expect(subject.size).to eq(0)
	end

	it 'can add a new element into the bst' do
		expect(subject.include?(1)).to be false
		subject.add 1
		expect(subject.include?(1)).to be true
	end

	it 'can tell if an element is included' do
		subject.add 2
		subject.add 1
		subject.add 3

		expect(subject.include?(0)).to be false
		expect(subject.include?(1)).to be true
		expect(subject.include?(2)).to be true
		expect(subject.include?(3)).to be true
		expect(subject.include?(4)).to be false
	end

	it 'keeps track of size as elements are added' do
		expect(subject.size).to eq(0)
		subject.add 1
		expect(subject.size).to eq(1)
	end

	it 'can do a breadth first search'
	it 'can do a pre-order depth first search'
	it 'can do an in-order depth first search'
	it 'can do a post-order depth first search'
end
