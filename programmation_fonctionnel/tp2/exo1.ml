(** Question 1 **)
let rec puissance x n =
  if (n=0) then 1.0
  else x*.puissance x (n-1);;

puissance 5.0 5;;

(** Question 2 **)
let rec fibonacci n =
  if (n=0 || n=1) then 1 else fibonacci (n-1) + fibonacci (n-2);;

fibonacci 8;;
