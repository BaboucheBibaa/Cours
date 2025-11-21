let pair n = (n mod 2) = 0;;


let rec pour_tout (p : int -> bool)  = function
  | [] -> true
  | x :: r -> p x && pour_tout p r;;

let rec il_existe (p : int -> bool) = function 
    [] -> false
    | x::r when p x = true -> true
    | x::r -> il_existe p r;;


il_existe pair [(1;2),(2;1)] ;;