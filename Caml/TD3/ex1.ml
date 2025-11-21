let rec dernier = function
| [] -> []
| [x] -> [x]
| (_::y) -> dernier(y);;

dernier([1;2;3;4]);;