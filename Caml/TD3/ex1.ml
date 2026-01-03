let rec dernier = function
| [] -> []
| [x] -> [x]
| (_::y) -> dernier(y);;
#dernier : 'a list -> 'a list = <fun>
dernier([1;2;3;4]);;