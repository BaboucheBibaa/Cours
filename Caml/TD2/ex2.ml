let rec syracuse = function
| (x,i) when x = 1 -> i
| (x,i) when x mod 2 = 0 -> syracuse(x/2, i+1)
| (x,i) when x mod 2 != 0 -> syracuse(3*x +1, i+1)
| _ -> 0;;
syracuse : int * int -> int = <fun>

syracuse(6,0);;