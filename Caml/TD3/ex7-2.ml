let rec peut_payer = function
| ([], prix) -> prix = 0
| (t::q,prix) when prix >= t -> peut_payer(q,prix-t)
| (t::q,prix) -> peut_payer(q,prix);;
#peut_payer : int list * int -> bool = <fun>