let palindrome s =
  let rec pdlrm i =
    let nb = String.length s in
    if (i<=nb - 1) then
      if(s.[i]!=s.[nb-1-i]) then
        false else
        pdlrm (i+1)
    else true
  in pdlrm 0;;

palindrome "test";;
palindrome "kaak";;
palindrome "radar";;
palindrome "";;
palindrome "e";;