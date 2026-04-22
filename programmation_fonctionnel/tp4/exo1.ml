type 'a stack =
  | EStack
  | Push of 'a * 'a stack;;

(** Question 1 **)
let ma_pile = Push(3, Push(8, Push(12, Push(4, EStack))));;

(** Question 2 **)
let rec somme p =
  match p with
  | EStack -> 0
  | Push(x, reste) -> x + (somme reste)

let res = somme ma_pile;;

(** Question 3 **)
let rec appartient e p =
  match p with
  | EStack -> false
  | Push(x, reste) -> x = e || appartient e reste
;;

appartient 5 ma_pile;;
appartient 3 ma_pile;;
appartient 12 ma_pile;;

(** Question 4 **)
let generer n =
  let rec aux k =
    if k > n then EStack
    else Push(k, aux (k + 1))
  in
  aux 1
;;

generer 4;;

(** Question 5 **)
let rec dump p1 p2 =
  match p1 with
  | EStack -> p2
  | Push(x, reste) -> dump reste (Push(x, p2))
;;

let p1 = Push(1, Push(2, Push(3, EStack)));;
let p2 = Push(4, Push(5, Push(6, EStack)));;

dump p1 p2;;
