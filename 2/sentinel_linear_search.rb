#!/usr/bin/env ruby

NOT_FOUND = -1

def linear_search(array, size, target)
  a = array.dup
  last, a[size-1] = a[size-1], target

  i = 0
  while a[i] != target
    i += 1
  end

  a[size-1] = last
  # 最後もしくはそれより前に見つかったかをチェック
  if i < size-1 || a[size-1] == target
    i
  else
    NOT_FOUND
  end
end

if $0 == __FILE__
  a = (0..99).to_a

  result = linear_search(a, a.size, 8)
  abort "Expected #{8} but got #{result}" unless result == 8

  result = linear_search(a, a.size, 99)
  abort "Expected #{99} but got #{result}" unless result == 99

  result = linear_search(a, a.size, 100)
  abort "Expected #{NOT_FOUND} but got #{result}" unless result == NOT_FOUND
end
