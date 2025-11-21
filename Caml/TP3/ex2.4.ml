let rec pour_tout p  = function
  | [] -> true
  | x :: r -> p x && pour_tout p r;;

let rec il_existe (p : int -> bool) = function 
    [] -> false
    | x::r when p x = true -> true
    | x::r -> il_existe p r;;

let rec ens_def_simple = function
  | [] -> []
  | (x, y) :: q -> x :: y :: ens_def_simple q;;

let rec unique = function
  | [] -> []
  | x::q when List.mem x q = true -> unique q
  | x::q -> x::unique q;;


let symetrique r =
  pour_tout (fun (x, y) -> List.mem (y, x) r) r;;

let reflexive r =
  let def_r = unique (ens_def_simple r) in pour_tout (fun x -> List.mem (x, x) r) def_r;;


let transitive r =
  pour_tout (fun (x, y) -> pour_tout(fun (y', z) -> (y <> y') || List.mem (x, z) r) r) r;;


let equivalence r =
  reflexive r && symetrique r && transitive r;;

equivalence [(1,1);(1,2);(1,3);(2,1);(2,2);(2,3);(3,1);(3,2) ;(3,3)] ;;