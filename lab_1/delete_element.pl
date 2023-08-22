delete_element_from_list(Element, List) :-
   delete(Element, List, Result),
   write('The list after deleting the element is: '),
   write(Result), nl.
