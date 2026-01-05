type Nombre =
    Ent of int
    |Reel of float
    |Comp of int*int;;

let carre = function
  | Ent m -> Ent (m * m)                    (* règle R1 *)
  | Reel x -> Reel (x *. x)                 (* règle R2 *)
  | Comp (a,b) -> Comp (a*a - b*b, 2*a*b)  (* règle R3 *)
;;