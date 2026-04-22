(** Exercice 1 **)
type reseau =
  | Feuille of string * int
  | Unaire of string * int * reseau
  | Binaire of string * int * reseau * reseau;;

Binaire("Paris", 0,
        Binaire("Saint-Denis", 4,
                Feuille("Villetaneuse", 2),
                Feuille("Epinay", 3)),
        Unaire("Aubervilliers", 5,
               Feuille("La Courneuve", 3)));;


(** Question 1 **)
let test = Binaire("Arnac-la-Poste", 0, 
  Feuille("Vatan", 8), 
  Unaire("Hébécrevon", 12, 
    Feuille("Montcuq", 7)
  )
  );;


(** Question 2 **)
let racineAZero r =
  match r with
  | Feuille (_, d) -> d = 0
  | Unaire (_, d, _) -> d = 0
  | Binaire (_, d, _, _) -> d = 0;;

racineAZero test;;

(** Question 3 **)
let rec distPos r =
  match r with
  | Feuille (_, d) -> d >= 0
  | Unaire (_, d, fils) -> d >= 0 && distPos fils
  | Binaire (_, d, fils_g, fils_d) -> d >= 0 && distPos fils_g && distPos fils_d;;

distPos test;;

(** Question 4 **)
let rec listeVilles r =
  match r with
  | Feuille (nom, _) -> [nom]
  | Unaire (nom, _, fils) -> nom :: listeVilles fils
  | Binaire (nom, _, fils_g, fils_d) -> nom :: (listeVilles fils_g @ listeVilles fils_d);;

listeVilles test;;

(** Question 5 **)
let rec maxListe l =
  match l with
  | [] -> failwith "La liste ne doit pas etre vide"
  | [x] -> x
  | hd::tl -> max hd (maxListe tl);;

maxListe [15; 52; 44; 36; 77; 89];;

(** Question 6 **)
let rec directions v r =
  match r with
  | Feuille (nom, d) -> 
      if nom = v then (d, []) 
      else (-1, [])
  | Unaire (nom, d, fils) ->
      if nom = v then (d, [])
      else
        let (dist, ins) = directions v fils in
        if dist = -1 then (-1, [])
        else (dist + d, "tout droit" :: ins)
  | Binaire (nom, d, fils_g, fils_d) ->
      if nom = v then (d, [])
      else
        let (dist_g, ins_g) = directions v fils_g in
        let (dist_d, ins_d) = directions v fils_d in
        if dist_g = -1 then
          if dist_d = -1 then (-1, [])
          else (dist_d + d, "droite" :: ins_d)
        else (dist_g + d, "gauche" :: ins_g);;

let r = Binaire("Paris", 0, 
           Binaire("Saint-Denis", 4, 
             Feuille("Villetaneuse", 2), 
             Feuille("Epinay", 3)), 
           Unaire("Aubervilliers", 5, 
             Feuille("La Courneuve", 3)))

let _ = directions "La Courneuve" r  (* (8, ["droite"; "tout droit"]) *);;
let _ = directions "Saint-Denis" r   (* (4, ["gauche"]) *);;
let _ = directions "Paris" r         (* (0, []) *);;
let _ = directions "Bobigny" r       (* (-1, []) *);;

(** Question 7 **)
let explications v r =
  let (_, instructions) = directions v r in
  List.map (function
    | "gauche" -> "Tourner à gauche"
    | "droite" -> "Tourner à droite"
    | "tout droit" -> "Aller tout droit"
    | _ -> "") instructions;;

let villesAvecDistance r =
  let villes = listeVilles r in
  List.map (fun ville -> 
    let (dist, _) = directions ville r in
    (ville, dist)
    ) villes;;

let villesDistanceMax r =
  let villes_dist = villesAvecDistance r in
  match villes_dist with
  | [] -> []
  | _ ->
      let sorted = List.sort (fun (_,d1) (_,d2) -> compare d2 d1) villes_dist in
      let max_dist = snd (List.hd sorted) in
      let filtered = List.filter (fun (_,d) -> d = max_dist) villes_dist in
      List.map fst filtered;;

let r = Binaire("Paris", 0, 
           Binaire("Saint-Denis", 4, 
             Feuille("Villetaneuse", 2), 
             Feuille("Epinay", 3)), 
           Unaire("Aubervilliers", 5, 
             Feuille("La Courneuve", 3)));;

let _ = explications "La Courneuve" r;;

let _ = villesAvecDistance r;;

let _ = villesDistanceMax r;;
