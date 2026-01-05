Exercice 3:

1.
f1 : ('a -> 'b) -> ('c -> 'a) -> 'c -> 'b = <fun>
let f1 = fun p x y -> p ( x ( y )) ;;

Exemple concret:
let double x = x * 2;;
let succ x = x + 1;;
f1 succ double 3;;

p = succ
x = double
et y le paramètre
('a -> 'b) : p car c'est la première fonction définie dans la ligne
('c -> 'a) : x car seconde fonction donc
on appelle x(y), donc on appelle double(3) (int -> int) qui donne 6
ensuite p(x(y)) fait succ(double(3)) donc 7.
f1 : ('a -> 'b) -> ('c -> 'a) -> 'c -> 'b = <fun>
Cette notation-ci dit: 
f1 prend deux fonctions : une fonction de 'a vers 'b et une fonction de 'c vers 'a. Elle les compose pour obtenir une fonction de 'c vers 'b.


let f2 = fun p g x y -> (p x , g y) ;;
f2: ('a -> 'b) -> ('c -> 'd) -> 'a -> 'c -> 'b * 'd 
Sort un couple de valeurs où chaque valeur 'a et 'c est gérée indépendamment

let f3 = fun p g x y -> p (g (x , y)) ;;
f3: ('c -> 'd) -> ('a * 'b -> 'c ) -> 'a * 'b -> 'd
fait g(x,y) pour ensuite faire p(g(x,y))

f4 = fun p g x y -> p ( g(x) , y) ;;
f4: ('d * 'b -> 'c) -> ('a -> 'd) -> 'a -> 'b -> 'c

2.
Exemple d'appel de F3:

let g (x, y) = x + y;;
(* g : int * int -> int *)

let p z = z * 2;;
(* p : int -> int *)
let f3 = fun p g x y -> p (g (x , y)) ;;

f3 p g 3 4;;

3.
f2 fonctionne pour toutes ces conditions, output -> (-5,20)

