sum_list_and_display(List) :-
   sum_list(List, Sum),
   write('The sum of the elements in the list is: '),
   write(Sum).