(** Exercice 4 **)
let rec decoupe n l =
  match (n, l) with
  | (0, _) -> ([], l)
  | (_, []) -> ([], [])
  | (n, t::q) ->
     let (preums, deuz) = decoupe (n-1) q in (t::preums, deuz);;

let rec interclasser l1 l2 =
  match (l1, l2) with
  | ([], l) | (l, []) -> l
  | (t1::q1, t2::q2) ->
     if t1 <= t2 then
       t1 :: interclasser q1 l2
     else
       t2 :: interclasser l1 q2;;

let rec fusion l =
  match l with
  | [] -> []
  | [x] -> [x]
  | _ ->
     let n = List.length l / 2 in
     let (preums, deuz) = decoupe n l in
     interclasser (fusion preums) (fusion deuz);;

decoupe 2 [1; 2; 3; 4];;

interclasser [1; 3; 5] [2; 4; 6];;

fusion [4; 2; 5; 1; 6; 3];;
