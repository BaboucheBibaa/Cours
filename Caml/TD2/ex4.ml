let rec decimale = function
(m,n,i) when i = n -> m mod 10
| (m,n,i) -> decimale(m / 10, n,i+1);;

decimale(169725,3,1);;