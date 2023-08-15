fib = [1 1]

while fib(end) + fib(end-1) <10000
    fib(end+1) = fib(end) + fib(end-1)
end

even_count = sum(mod(fib,2) == 0)
odd_count = sum(mod(fib,2) == 1)

plot(fib, '-p')

fprintf("Even count = %d \n Odd count = %d",even_count,odd_count)