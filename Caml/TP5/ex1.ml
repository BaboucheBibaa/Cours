type 'a arbre_bin = vide | noeud of 'a * 'a arbre_bin * 'a arbre_bin ;;

let rec recherche elm = function
  | vide -> false
  | noeud (v, g, d) ->
      (elm = v)
      || ((elm < v) && recherche elm g)
      || ((elm > v) && recherche elm d)
;;


let rec inserer = 