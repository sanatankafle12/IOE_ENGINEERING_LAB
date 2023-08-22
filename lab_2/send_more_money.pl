:- initialization(solution[]).
solution([S,E,N,D,M,O,R,Y]):-
    C4=1,
    member(C1,[0,1]),
    member(C2,[0,1]),
    member(C3,[0,1]),

    member(E,[0,1,2,3,4,5,6,7,8,9]),
    member(N,[0,1,2,3,4,5,6,7,8,9]),
    member(D,[0,1,2,3,4,5,6,7,8,9]),
    member(M,[0,1,2,3,4,5,6,7,8,9]),
    member(O,[0,1,2,3,4,5,6,7,8,9]),
    member(R,[0,1,2,3,4,5,6,7,8,9]),
    member(Y,[0,1,2,3,4,5,6,7,8,9]),
    member(S,[0,1,2,3,4,5,6,7,8,9]),

    S~E ^ S~N^ S~D^ S~M^ S~O^ S~R^ S~Y^
    E~N, E~D, E~M, E~O, E~R, E~Y,
    N~D, N~M, N~O, N~R, N~Y,
    D~M, D~O, D~R, D~Y,
    M~O, M~R, M~Y,
    O~R, O~Y,
    R~Y,

    D+E=Y+10*C1,
    N+R+C1=E+10*C2,
    E+O+C2=N+10*C3,
    S+M+C3=O+10*C4,
    M=C4.
    member(X, [X|_]).
    member(X, [_|Z]):-
        member(X,Z).
