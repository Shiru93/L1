type exprBool =
  | Vrai
  | Faux
  | Non of exprBool
  | Et of exprBool * exprBool
  | Ou of exprBool * exprBool
  | Impl of exprBool * exprBool;;

(** Question 1 **)
Non(Impl(Vrai, Faux));;
Et(Et(Vrai, Ou(Faux, Faux)), Vrai);;

(** Question 2 **)
let rec nbConnecteurs b =
  match b with
  | Vrai | Faux -> 0
  | Non(e) -> 1 + nbConnecteurs e
  | Et(e1, e2) | Ou(e1, e2) | Impl(e1, e2) -> 1 + nbConnecteurs e1 + nbConnecteurs e2
;;

(** Question 3 **)
let rec evaluerParesse b =
  match b with
  | Vrai -> true
  | Faux -> false
  | Non(e) -> not (evaluerParesse e)
  | Et(e1, e2) ->
     if not (evaluerParesse e1) then false
     else evaluerParesse e2
  | Ou(e1, e2) ->
     if evaluerParesse e1 then true
     else evaluerParesse e2
  | Impl(e1, e2) ->
     if not (evaluerParesse e1) then true
     else evaluerParesse e2
;;

(** Question 4 **)
let rec effacerNeg b =
  match b with
  | Vrai -> Vrai
  | Faux -> Faux
  | Non(Vrai) -> Faux
  | Non(Faux) -> Vrai
  | Non(Non(e)) -> effacerNeg e
  | Non(Et(e1, e2)) -> Ou(effacerNeg (Non(e1)), effacerNeg (Non(e2)))
  | Non(Ou(e1, e2)) -> Et(effacerNeg (Non(e1)), effacerNeg (Non(e2)))
  | Non(Impl(e1, e2)) -> Et(effacerNeg e1, effacerNeg (Non(e2)))
  | Et(e1, e2) -> Et(effacerNeg e1, effacerNeg e2)
  | Ou(e1, e2) -> Ou(effacerNeg e1, effacerNeg e2)
  | Impl(e1, e2) -> Impl(effacerNeg e1, effacerNeg e2)
;;

effacerNeg (Non(Et(Vrai, Faux)));;
effacerNeg (Non(Impl(Vrai, Faux)));;

(** Question 5 **)
let rec distribuer b =
  match b with
  | Vrai | Faux -> b
  | Non(e) -> Non(distribuer e)
  | Et(e1, Ou(e2, e3)) -> Ou(distribuer (Et(e1, e2)), distribuer (Et(e1, e3)))
  | Et(Ou(e1, e2), e3) -> Ou(distribuer (Et(e1, e3)), distribuer (Et(e2, e3)))
  | Et(e1, e2) ->
     let e1' = distribuer e1 in
     let e2' = distribuer e2 in
     if e1 != e1' || e2 != e2' then distribuer (Et(e1', e2'))
     else Et(e1', e2')
  | Ou(e1, e2) -> Ou(distribuer e1, distribuer e2)
  | Impl(e1, e2) -> Impl(distribuer e1, distribuer e2)
;;
