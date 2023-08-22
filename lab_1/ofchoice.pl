animal(lion).
animal(tiger).
animal(giraffe).
animal(zebra).
animal(monkey).

big_cat(X) :- animal(X), (X = lion ; X = tiger).

herbivore(X) :- animal(X), (X = giraffe ; X = zebra).