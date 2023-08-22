start:-
    write("Enter the numbers: ").
    nl,
    write("Enter 0 to stop: "),nl,
    read_a_list([]).

read_a_list(Y):-
    readint(X),
    insert(X,Y,Z),
    read_a_list(Z).

insert(0,Y,_):-
    write("these were the elements you inserted: "),nl,
    write("["),
    display(Y).

insert(X,Y,[X|Y]).
display([]):-
    write("]"),nl
display([H|T]):-
    write(H),write("/t"),display(T).