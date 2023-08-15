from addition import binary_adder


def adjust_number(x, y):
    l1, l2 = len(x), len(y)
    max_bit = max(l1, l2)
    x = x.rjust(2 * max_bit, "0")
    y = y.rjust(2 * max_bit, "0")
    return (x, y)


def binary_multiplication(x, y, count):
    sum = "0" * len(x)
    for i in range(count):
        if y[-1] == "1":
            sum, carry = binary_adder(sum, x)
        x = x[1:] + "0"
        y = "0" + y[:-1]
    return sum


if __name__ == "__main__":
    x = input("Enter multiplicand: ")
    y = input("Enter multiplier: ")
    count = len(y) 
    x, y = adjust_number(x, y)
    product = binary_multiplication(x, y, count)
    print(f"Product = {product}")