let maximum = function
  (x,y) when x<y -> y
  | (x,_) -> x;;
  maximum : 'a * 'a -> 'a = <fun>

let rec plus_grand = function
  [] -> invalid_arg "liste_vide, pas de plus grand élément"
  | d::[] -> d
  | e::r -> maximum(e, plus_grand(r));;
  #plus_grand : 'a list list -> 'a list = <fun>