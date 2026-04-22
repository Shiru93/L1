(** Exercice 3 **)
let rec estPrefixe l1 l2 =
  match (l1, l2) with
  | ([], _) -> true
  | (_, []) -> false
  | (t1::q1, t2::q2) ->
     if t1 = t2 then estPrefixe q1 q2
     else false;;

estPrefixe [1; 2; 3] [1; 2; 3; 4; 5];;
estPrefixe [] [1; 2; 3; 4; 5];;
estPrefixe [1; 5; 6] [1; 2; 3; 4; 5];;
estPrefixe [1; 2; 3; 4; 5] [1; 2; 3];;
estPrefixe [1; 2; 3] [];;
