let rec suite_carre = function
  | (n, ent0, i) when i > n -> ent0
  | (n, ent0, i) when i mod 2 <> 0 -> suite_carre (n, (2 * ent0) - (i * i), i + 1)
  | (n, ent0, i) -> suite_carre (n, (2 * ent0) + (i * i), i + 1)
;;

suite_carre (5, 10, 1);;
