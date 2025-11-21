let rec compter = function
  (elt, []) -> 0
  | (elt,e::r) when (elt=e) -> 1+compter(elt,r)
  | (elt,e::r) -> compter(elt,r);;

let rec duplicata = function
  [] -> []
  | (t::q) when compter(t,q) > 0 -> duplicata(q)
  | (t::q) -> t::duplicata(q);;