let aux n =
  (n, n-1);;

let (p1, p2) = aux n in
    if (n = 0) then (0, 1)
    else
      (p1, p2 - 1);;
