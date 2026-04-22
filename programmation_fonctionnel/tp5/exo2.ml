(** Exercice 2 **)
let rec append l1 l2 =
  match l1 with
  | [] -> l2
  | t::q -> t :: append q l2;;

let liste1 = [1; 5; 8; 3; 4];;
let liste2 = [5; 6; 8; 9; 1; 2; 4];;

append liste1 liste2;;

let rec nbOccurrences e l =
  match l with
  | [] -> 0
  | t::q -> (if t = e then 1 else 0) + nbOccurrences e q;;

nbOccurrences 4 (append liste1 liste2);;

let rec enleveTout e l =
  match l with
  | [] -> []
  | t::q when t = e -> enleveTout e q
  | t::q -> t :: enleveTout e q;;

enleveTout 4 (append liste1 liste2);;

let rec enleveTout e l =
  match l with
  | [] -> []
  | t::q -> 
      if t = e then 
        enleveTout e q
      else 
        t :: enleveTout e q

let rec prefixe n l =
  match (n, l) with
  | (0, _) | (_, []) -> []
  | (n, t::q) -> t :: prefixe (n-1) q;;

prefixe 4 liste2;;

let rec rang e l =
  let rec aux i l =
    match l with
    | [] -> -1
    | t::q -> if t = e then i else aux (i+1) q
  in aux 0 l;;

rang 8 liste2;;
rang 1565 liste2;;
