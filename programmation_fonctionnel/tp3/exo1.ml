(** Question 1 **)
let rec factorielle n =
  match n with
  | 1 -> 1
  | n -> n * factorielle (n-1);;

factorielle 5;;

(** Question 2 **)
let rec puissance x n =
  match n with
  | 0 -> 1
  | n when n mod 2 = 0 -> puissance (x * x) (n / 2)
  | n -> x * puissance (x * x) (n / 2);;

puissance 5 2;;
