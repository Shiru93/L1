(** Exercice 1 **)
let rec somme l =
  match l with
  | [] -> 0
  | t::q -> t + somme q;;

let test = [1; 2; 3];;
somme test;;

let rec ajouteN n l =
  match l with
  | [] -> []
  | t::q -> (t + n) :: ajouteN n q;;

ajouteN 10 test;;

let rec pairs l =
  match l with
  | [] -> []
  | t::q -> if t mod 2 = 0 then t :: pairs q else pairs q;;

pairs test;;

let rec pairs2 l =
  match l with
  | [] -> []
  | t::q when t mod 2 = 0 -> t :: pairs2 q
  | _::q -> pairs2 q

let test_pairs2 = [6; 1; 1; 2; 4; 7; 12]

let rec sommeNonVide l =
  match l with
  | [] -> failwith "Erreur: liste vide !"
  | [x] -> x
  | t::q -> t + sommeNonVide q;;

sommeNonVide test_pairs2;;
