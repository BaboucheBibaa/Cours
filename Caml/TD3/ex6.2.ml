let rec nbr_pos_egales = function
([],[],pos)-> []
| ([], _, pos) -> []
| (_,[], pos) -> []
| (t1::q1,t2::q2,pos) when t1=t2 -> (t1;pos)::nbr_pos_egales(q1,q2,pos+1)
| (t1::q1,t2::q2,pos) -> nbr_pos_egales(q1,q2,pos+1);;

#nbr_poses_egales : 'a list * 'a list * int -> int list = <fun>