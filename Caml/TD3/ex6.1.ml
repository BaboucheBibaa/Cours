let rec nbr_egales = function
  ([],[]) -> 0
  | ([], lst) | (lst, []) -> 0
  | (t1::q1, t2::q2) when t1 = t2 -> 1 + nbr_egales(q1,q2)
  | (t1::q1, t2::q2) -> nbr_egales(q1,q2);;