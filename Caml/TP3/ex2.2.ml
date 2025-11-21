let rec pour_tout p  = function
  | [] -> true
  | x :: r -> p x && pour_tout p r;;


let rec ens_def_simple = function
  | [] -> []
  | (x, y) :: q -> x :: y :: ens_def_simple q;;

let rec unique = function
  | [] -> []
  | x::q when List.mem x q = true -> unique q
  | x::q -> x::unique q;;


let reflexive r =
  let def_r = unique (ens_def_simple r) in pour_tout (fun x -> List.mem (x, x) r) def_r;;


let a =  [ (1 , 2) ; (1 , 1) ; (3 ,3) ; (2 , 2)] ;;
reflexive  a;;
