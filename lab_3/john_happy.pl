happy(X) :- wealthy(X), smart(X).
smart(X) :- can_read(X).
can_read(john).
wealthy(john).
exciting_life(X) :- happy(X).