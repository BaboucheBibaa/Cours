let rec double_liste = function
  [] -> []
  | x::r -> [x;x]::(double_liste r);;


#v1
let rec double = function
[] -> []
| (x::y) -> x::x::double(y);;

double[1;2;3;4];;