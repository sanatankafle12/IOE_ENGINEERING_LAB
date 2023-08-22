likes(bhogendra, X) :- food(X).
food(oranges).
food(chicken).
food(X) :- eats(Y, X), not(kills(Y, X)).
eats(jogendra, peanuts).
eats(shailendra, X) :- likes(bhogendra, X).

likes(shailendra, chicken).