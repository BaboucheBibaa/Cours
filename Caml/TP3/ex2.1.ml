let rec pour_tout p  = function
  | [] -> true
  | x :: r -> p x && pour_tout p r;;


let symetrique r =
  pour_tout (fun (x, y) -> List.mem (y, x) r) r;;


symetrique [ (1,2) ; (3,2) ; (2,1) ; (2,3)] ;;