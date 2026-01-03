let f = function x -> 1;;
f : 'a -> int = <fun>

let f = function x -> x;;
f : 'a -> 'a = <fun>

let f = function x -> x + 1;;
f : int -> int = <fun>

(f 1);;
- : int = 2

f 1;;
- : int = 2

f(1);;
- : int = 2

(f(f 1));;
- : int = 3

(f f 1);;
Cette expression est de type int -> int,
mais est utilisée avec le type int.

let f = function x -> function y -> x + y;;
f : int -> int -> int = <fun>

(f 1);;
- : int -> int = <fun>

((f 1) 2);;
- : int = 3

(f 1 2);;
- : int = 3

f(1,2);;
Cette expression est de type int * int,
mais est utilisée avec le type int.

f(1 2);;
Cette expression n'est pas une fonction, elle ne peut être appliquée.

let f = function x -> (f x);;
f : int -> int -> int = <fun>

(f 1);;
- : int -> int = <fun>

((f 1) 2);;
- : int = 3

(f 1 2);;
- : int = 3

