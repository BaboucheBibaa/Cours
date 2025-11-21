let rec pour_tout p  = function
  | [] -> true
  | x :: r -> p x && pour_tout p r;;

let rec il_existe (p : int -> bool) = function 
    [] -> false
    | x::r when p x = true -> true
    | x::r -> il_existe p r;;

let transitive r =
  pour_tout (fun (x, y) -> pour_tout(fun (y', z) -> (y <> y') || List.mem (x, z) r) r) r;;


transitive [(1,1);(1,2);(1,3);(2,1);(2,2);(2,3);(3,1);(3,2);(3,3)] ;;
