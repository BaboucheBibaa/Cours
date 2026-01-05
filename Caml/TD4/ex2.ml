let h = function x -> x + 1 ;;
#h : int -> int = <fun>

let g = function h -> function x -> (h x) ;;
#g : ('a -> 'b) -> 'a -> 'b = <fun>

(f 1);;
#- : int = 1

(f h);;
#- : int -> int = <fun>

(f h 1);;
#- : int = 2

(g 1);;
#Entrée interactive:
>(g 1);;
>   ^
Cette expression est de type int,
mais est utilisée avec le type 'a -> 'b.

(g h) ;;
#- : int -> int = <fun>

(g h 1) ;;
#- : int = 2

let g2 = function h -> function x -> (h x + 1) in (g2 h 1) ;;
- : int = 3

let f1 = function f2 -> (function x -> f2 x) in let g = function x -> x + 1 in f1 g 2 ;;
- : int = 3




