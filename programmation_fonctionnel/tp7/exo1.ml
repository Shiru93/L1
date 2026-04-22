(** Exercice 1 **)

type 'a aBin =
  | Etree
  | Noeud of 'a * 'a aBin * 'a aBin;;

let arbre1 = Noeud('B', Noeud('L', Noeud('A', Etree, Etree), Noeud('B', Etree, Etree)), Noeud('L', Etree, Etree));;
let arbre2 = Noeud('B', Noeud('L', Etree, Noeud('A', Noeud('B', Etree, Etree), Etree)), Etree);;

let rec nbNoeuds a =
  match a with
  | Etree -> 0
  | Noeud(_, t1, t2) -> 1 + nbNoeuds t1 + nbNoeuds t2;;

nbNoeuds arbre1;;
nbNoeuds arbre2;;

let rec haut a =
  match a with
  | Etree -> 0
  | Noeud(_, t1, t2) -> 1 + max (haut t1) (haut t2);;

haut arbre1;;
haut arbre2;;

let rec parcoursPrefixe a =
  match a with
  | Etree -> ()
  | Noeud(t1, t2, t3) -> print_char t1;
                         print_string " ";
                         parcoursPrefixe t2;
                         parcoursPrefixe t3;;

parcoursPrefixe arbre1;;
parcoursPrefixe arbre2;;

let rec parcoursInfixe a =
  match a with
  | Etree -> ()
  | Noeud(v, g, d) -> parcoursInfixe g;
                      print_char v;
                      print_string " ";
                      parcoursInfixe d;;

parcoursInfixe arbre1;;
parcoursInfixe arbre2;;

let rec parcoursSuffixe a =
  match a with
  | Etree -> ()
  | Noeud(v, g, d) -> parcoursSuffixe g;
                      parcoursSuffixe d;
                      print_char v;
                      print_string " ";;

parcoursSuffixe arbre1;;
parcoursSuffixe arbre2;;
