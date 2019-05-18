#!/usr/bin/env ruby

NOT_FOUND = -1

def linear_search(array, size, target)
  answer = NOT_FOUND
  size.times do |i|
    v = array[i]
    answer = i if v == target
  end
  return answer
end

if $0 == __FILE__
  a = (0..99).to_a

  result = linear_search(a, a.size, 8)
  abort "Expected #{8} but got #{result}" unless result == 8

  result = linear_search(a, a.size, 100)
  abort "Expected #{NOT_FOUND} but got #{result}" unless result == NOT_FOUND
end
