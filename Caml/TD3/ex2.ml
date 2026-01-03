let rec double_liste = function
| [] -> []
| x::y -> x::x::(double_liste(y));; 
#double_liste : 'a list -> 'a list = <fun>
double_liste[1;2;3;4];;
#- : int list = [1; 1; 2; 2; 3; 3; 4; 4]

let rec double = function
| [] -> []
| (x::y) -> [x;x]::double(y);;
#double : 'a list -> 'a list list = <fun>
double[1;2;3;4];;
#- : int list list = [[1; 1]; [2; 2]; [3; 3]; [4; 4]]



