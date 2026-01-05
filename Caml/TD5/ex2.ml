type polynome = Nul | PlusXfois of int * polynome ;;
let P = PlusXfois (4, PlusXfois (5, PlusXfois (1, Nul))) ;;
