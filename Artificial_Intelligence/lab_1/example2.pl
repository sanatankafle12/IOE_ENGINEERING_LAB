mother("Kaushaiya","Ram").
mother("Kaikai","Bharat").
mother("Sumitra","Laxman").
mother("Sumitra","Satrughan").

husband("Dasarath","Kaushalya").
husband("Dasarath","Kaikai").
husband("Dasarath","Sumitra").

son(A,C):- mother(C,A).
son(A,C):- husband(C,B),mother(B,A).
father(A,B):-husband(A,C),mother(C,B).
