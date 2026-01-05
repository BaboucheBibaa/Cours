Exercice 4

let rec appliquer_n  = function
    | (n, f, x) when n <= 0 -> x       (* 0 fois : on retourne x *)
    | (n, f, x) -> appliquer_n (n-1, f, f x)  (* on applique f une fois puis on répète *)
;;
let puissance = function
  (x,n) -> appliquer_n (n, (fun y -> x * y), 1)
;;
puissance(5,2);;
let pair = function
	n -> appliquer_n (n, (fun x -> x - 1), 0) = 0;;
