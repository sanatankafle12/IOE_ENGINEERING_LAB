member(dave).
member(fred).
parent(fred, dad).
cant_waltz(dad).
can_do(X, Y) :- cant_do(Y, X).
cant_do(X, Y) :- cant_waltz(Y).
cant_do(X, Y) :- parent(Y, Z), can_do(X, Z).
can_jive(X) :- member(X), not(can_waltz(X)).
can_waltz(X) :- member(X), not(can_jive(X)).

% Define the query as a rule
?- not(can_jive(X)), member(X).