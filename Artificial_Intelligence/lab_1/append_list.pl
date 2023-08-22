append([], List2, List2).
append([Head|Tail], List2, [Head|Result]) :-
   append(Tail, List2, Result).
