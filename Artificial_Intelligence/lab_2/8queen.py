def no_attack(new_queen, queens):
    for queen in queens:
        if queen[1] == new_queen[1] or abs(queen[0] - new_queen[0]) == abs(queen[1] - new_queen[1]):
            return False
    return True

def solution(queens, result):
    if len(queens) == 8:
        result.append(queens)
        return
    for i in range(1, 9):
        new_queen = (len(queens) + 1, i)
        if no_attack(new_queen, queens):
            solution(queens + [new_queen], result)

result = []
solution([], result)
print("Total number of solutions:", len(result))
for i, res in enumerate(result):
    print("Solution", i+1, ":")
for queen in res:
    print("Queen at", queen[0], ",", queen[1])
print("\n")
