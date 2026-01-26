<?php
// Vérifie que les valeurs existent
if (isset($_GET['valeur1']) && isset($_GET['valeur2']) && isset($_GET['operation'])) {

    $v1 = $_GET['valeur1'];
    $v2 = $_GET['valeur2'];
    $op = $_GET['operation'];

    if (!is_numeric($v1) || !is_numeric($v2)) {
        echo "Erreur : veuillez entrer deux nombres valides.";
        exit;
    }

    $v1 = (float)$v1;
    $v2 = (float)$v2;

    switch ($op) {
        case '+':
            $resultat = $v1 + $v2;
            break;
        case '-':
            $resultat = $v1 - $v2;
            break;
    }

    echo "<h2>Résultat</h2>";
    echo "$v1 $op $v2 = $resultat";

} else {
    echo "Veuillez remplir le formulaire.";
}

/*
Question 2. Afin de voir la transmission des données par le formulaire, son action est
mise à « GET ». Quelles modifications seraient nécessaires pour une transmission non
visible par « POST »?


Question 3. Comment peut-on effectuer l'appel à calcul.php pour faire une opération sans
passer par calculette.html et sans modifier le script calcul.php ?

on écrit ça sur l'url: ?valeur1=5&valeur2=6&operation=-
*/
?>

