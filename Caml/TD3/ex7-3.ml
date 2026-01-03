let rec payer = function
| ([],prix) when prix = 0 -> [] 
| (t::q,prix) when prix >= t -> t::payer(q,prix-t)
| (t::q,prix) -> payer(q,prix);;
Attention: ce filtrage n'est pas exhaustif.
payer : int list * int -> int list = <fun>