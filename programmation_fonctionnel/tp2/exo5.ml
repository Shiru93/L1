let boucle nb =
  let rec batonnets n =
    if (n <= nb) then
      (print_string "|";
       batonnets (n+1))
  in batonnets 1;; 

let rec joueur1 n =
  if (n <= 0) then print_endline "Joueur 1 a perdu"
  else if (n = 1) then print_endline "Il reste un batonnet, Joueur 1 a perdu"
  else
    (boucle n;
     print_newline();
     print_string "Il reste ";
     print_int n;
     print_string " batonnets, Joueur 1 en prend ";
     let strat_g =
       if n mod 4 = 1 then 1 + Random.int 3
       else (n-1) mod 4
     in
     print_int strat_g;
     print_newline();
     joueur2 (n-strat_g))
and joueur2 n =
  if (n <= 0) then print_endline "Joueur 2 a perdu"
  else if (n = 1) then print_endline "Il reste un batonnet, Joueur 2 a perdu"
  else
    (boucle n;
     print_newline();
     print_string "Il reste ";
     print_int n;
     print_string " batonnets, Joueur 2 en prend ";
     let strat_g =
       if n mod 4 = 1 then 1 + Random.int 3
       else (n-1) mod 4
     in
     print_int strat_g;
     print_newline();
     joueur2 (n-strat_g));;
