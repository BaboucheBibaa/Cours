let rec compter = function
  (elt, []) -> 0
  | (elt,e::r) when (elt=e) -> 1+compter(elt,r)
  | (elt,e::r) -> compter(elt,r);;
  #compter : 'a * 'a list -> int = <fun>