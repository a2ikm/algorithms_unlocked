#!/usr/bin/env ruby

NOT_FOUND = -1

def linear_search(array, size, target)
  size.times do |i|
    return i if array[i] == target
  end
  return NOT_FOUND
end

if $0 == __FILE__
  a = (0..99).to_a

  result = linear_search(a, a.size, 8)
  abort "Expected #{8} but got #{result}" unless result == 8

  result = linear_search(a, a.size, 100)
  abort "Expected #{NOT_FOUND} but got #{result}" unless result == NOT_FOUND
end
