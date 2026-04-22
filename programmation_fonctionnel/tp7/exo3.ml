(** Exercice 3 **)
type op = Plus | Mult | Minus | Div;;
type eArith =
  | Num of int
  | Eop of op * eArith * eArith;;


let fun_of_op o =
  match o with
  | Plus -> (+)
  | Mult -> ( * )
  | Minus -> (-)
  | Div -> (/);;

let rec evaluer e =
  match e with
  | Num e -> e
  | Eop(op, e1, e2) -> (fun_of_op op) (evaluer e1) (evaluer e2);;

let rec simplifier e =
  match e with
  | Num e -> Num e
  | Eop(Plus, e, Num 0) | Eop(Plus, Num 0, e) | Eop(Minus, e, Num 0) | Eop(Mult, e, Num 1) | Eop(Mult, Num 1, e) | Eop(Div, e, Num 1) -> simplifier e
  | Eop(op, e1, e2) -> Eop(op, simplifier e1, simplifier e2);;
