def XOR(a, b):
    return a != b
def AND(a, b):
    return a * b
def OR(a, b):
    return int(bool(a + b))
def adjust_number(x, y):
    l1, l2 = len(x), len(y)
    if l1 > l2:
        y = y.rjust(l1, "0")
    elif l2 > l1:
        x = x.rjust(l2, "0")
    return (x, y)
def full_adder(x, y, cin):
    sum = XOR(XOR(x, y), cin)
    cout = OR(OR(AND(x, y), AND(y, cin)), AND(x, cin))
    return (sum, cout)
def binary_adder(x, y, cin=0):
    l = len(x)
    sum = ""
    carry = cin
    for i in range(l - 1, -1, -1):
        bit_sum, carry = full_adder(int(x[i]), int(y[i]), carry)
        sum = str(int(bit_sum)) + sum
    return (sum, carry)
def twos_complement(y):
    n = len(y)
    i = n - 1
    y1 = ""
    while i >= 0:
        y1 = y[i] + y1
        if y[i] == "1":
            i = i - 1  # first 1 found
            break
        i = i - 1
    while i >= 0:
        if y[i] == "0":
            y1 = "1" + y1
        else:
            y1 = "0" + y1
        i = i - 1
    return y1
if __name__ == "__main__":
    x = input("Enter first number X: ")
    y = input("Enter second number Y: ")
    x, y = adjust_number(x, y)
    sum, end_carry = binary_adder(x, twos_complement(y))
    print(f"Difference = {sum}")