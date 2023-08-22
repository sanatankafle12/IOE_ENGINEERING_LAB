% filter_ones_and_twos(List, Result)
filter_ones_and_twos([], []).
filter_ones_and_twos([1|Tail], [1|Result]) :-
   filter_ones_and_twos(Tail, Result).
filter_ones_and_twos([2|Tail], [2|Result]) :-
   filter_ones_and_twos(Tail, Result).
filter_ones_and_twos([_|Tail], Result) :-
   filter_ones_and_twos(Tail, Result).

% main predicate
display_ones_and_twos(List) :-
   filter_ones_and_twos(List, Result),
   write('The list of 1s and 2s is: '),
   write(Result), nl.