mammal(horse).
mammal(cow).
mammal(pig).

offspring_of(X, Y) :- parent_of(Y, X).
parent_of(bluebeard, charlie).
mammal_has_parent(X) :- mammal(X), parent_of(X, _).
horse(charlie) :- parent_of(bluebeard, charlie).