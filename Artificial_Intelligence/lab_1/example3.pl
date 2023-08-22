length([],0).
length([H|T],L):-
    legnth(T,L1),
    L = L1+1.
