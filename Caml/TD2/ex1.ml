let rec combien = function
| x when x = 0 -> 0
| x when x > 10 -> 1+combien(x-10)
| x when x > 5 -> 1+combien(x-5)
| x when x >= 1 -> 1+combien(x-1)
| _ -> 0;;
combien : int -> int = <fun>

combien(87);;