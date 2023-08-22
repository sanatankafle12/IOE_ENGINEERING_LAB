pompeian(X) :- roman(X).
roman(X) :- loyal_to_caesar(X).
roman(X) :- hates_caesar(X).
loyal_to(X, Y) :- roman(X), (loyal_to_caesar(Y); hates_caesar(Y)).
assassin(X, Y) :- not(loyal_to(X, Y)), not(X = Y).
tried_to_assassinate(marcus, caesar).
pompeian(marcus).

hates_caesar(X) :- pompeian(X), tried_to_assassinate(X, caesar).