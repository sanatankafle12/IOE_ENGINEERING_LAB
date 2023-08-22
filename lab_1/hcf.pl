%Write a program to find the hcf of two numbers.
hcf(X, 0, X) :- X > 0.
hcf(X, Y, G) :- Y > 0, X1 is X mod Y, hcf(Y, X1, G).