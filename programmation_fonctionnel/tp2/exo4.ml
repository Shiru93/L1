(** Question 1 **)
let rec pascal l c =
  if (l=1 || c=1 || (c=l)) then 1 else
    pascal (l-1) (c-1) + pascal (l-1) c;;

pascal 3 2;;

(** Question 2 **)
let afficherPascal n =
  let rec afficher l c =
    if (l<=n) then
      if (c<=l) then
        (print_int(pascal l c);
         print_string " ";
        afficher l (c+1))
      else
        (print_newline ();
         afficher (l+1) 1)
         
  in afficher 1 1;;
      

afficherPascal 5;;
