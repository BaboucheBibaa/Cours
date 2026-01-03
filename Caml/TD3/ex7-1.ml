let rec payer_illimite = function
  ([],_) -> []
  | (t::lst_prix, prix) when prix >= t -> payer_illimite(lst_prix, prix-t)
  | (t::lst_prix, prix) -> payer_illimite(lst_prix,prix)
#payer_illimite : int list * int -> 'a list = <fun>