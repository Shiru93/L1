type couleur =
  | Trefle | Carreau | Coeur | Pique;;

(** Question 1 **)
type valeur =
  | As
  | Roi
  | Dame
  | Valet
  | Num of int

type carte =
  | Card of valeur * couleur;;

(** Question 2 **)
let trois_de_pique = Card (Num 3, Pique);;
let dame_de_carreau = Card (Dame, Carreau);;

(** Question 3 **)
let string_of_couleur c =
  match c with
  | Trefle -> "trèfle"
  | Carreau -> "carreau"
  | Coeur -> "coeur"
  | Pique -> "pique"

let string_of_valeur v =
  match v with
  | As -> "as"
  | Roi -> "roi"
  | Dame -> "dame"
  | Valet -> "valet"
  | Num v -> string_of_int v

let string_of_carte c =
  match c with
  | Card (v, c) -> string_of_valeur v ^ " de " ^ string_of_couleur c;;

(** Question 4 **)
let enRougeEtNoir c =
  match c with
      | Card (_, Carreau) | Card (_, Coeur) -> "rouge"
      | _ -> "noir"

(** Question 5 **)
let estFigure c =
  match c with
  | Card (Roi, _) | Card (Dame, _) | Card (Valet, _) -> true
  | _ -> false;;

(** Question 6 **)
