let rec reverse = function
  | (x, acc) when x = 0 -> acc
  | (x, acc) -> reverse (x / 10, acc * 10 + x mod 10)
;;

let palidrome = function
| (x) -> reverse(x,0) = x;;

