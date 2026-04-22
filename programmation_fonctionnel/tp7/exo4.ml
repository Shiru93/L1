(** Exercice 4 **)
type abrint =
  | Eabr
  | Noeudabr of int * abrint * abrint;;

let rec chercher i a =
  match a with
  | Eabr -> false
  | Noeudabr(v, g, d) ->
     if i = v then true
     else if i < v then chercher i g
     else chercher i d;;

let rec inserer i a =
  match a with
  | Eabr -> Noeudabr(i, Eabr, Eabr)
  | Noeudabr(v, g, d) ->
     if i <= v then Noeudabr(v, inserer i g, d)
     else Noeudabr(v, g, inserer i d);;
