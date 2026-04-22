(** Exercice 2 **)
type 'a anr =
  | EAnr
  | Noeudnr of 'a * 'a forest
and 'a forest =
  | Eforest
  | Fcons of 'a anr * 'a forest;;

let arbre1 = Noeudnr('B', Eforest);;
let arbre2 = Noeudnr('W', Fcons(Noeudnr('B', Fcons(Noeudnr('Y', Eforest), Fcons(Noeudnr('O', Eforest), Eforest))), Fcons(Noeudnr('L', Eforest), Fcons(Noeudnr('A', Eforest), Eforest))));;

let rec nbNoeuds a =
  match a with
  | EAnr -> 0
  | Noeudnr(_, f) -> 1 + nbNoeudsForest f
and nbNoeudsForest a =
  match a with
  | Eforest -> 0
  | Fcons(a, f) -> nbNoeuds a + nbNoeudsForest f;;

nbNoeuds arbre1;;
nbNoeuds arbre2;;

type 'a anr =
  | EAnr
  | Noeudnr of 'a * ('a anr) list;;

let rec nbNoeuds a =
  match a with
  | EAnr -> 0
  | Noeudnr(_, enfants) -> 1 + (nbNoeuds_liste enfants)
and nbNoeuds_liste a =
  match a with
  | [] -> 0
  | t::q -> nbNoeuds t + nbNoeuds_liste q;;

let rec nbNoeuds = function
  | EAnr -> 0
  | Noeudnr(_, enfants) ->
     let rec aux a =
       match a with
        | [] -> 0
        | t::q -> nbNoeuds t + aux q
      in 1 + aux enfants;;
