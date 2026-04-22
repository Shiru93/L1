let boucle nb =
  let rec batonnets n =
    if (n <= nb) then
      (print_string "|";
       batonnets (n+1))
  in batonnets 1;; 

boucle 10;;
