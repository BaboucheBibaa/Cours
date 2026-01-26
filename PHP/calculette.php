<html>
 <body>
 <h2 align=center> Simple Calculette</h2>
 <p>
 <form method="post">
 Premiere valeur : <input type="text" name="valeur1"><br>
 Seconde valeur : <input type="text" name="valeur2"><br>
 <input type="submit" name="operation" value="+">
 <input type="submit" name="operation" value="-">
 </form>
 </p>

<?php
if (isset($_POST['valeur1']) && isset($_POST['valeur2']) && isset($_POST['operation'])) {

    $v1 = $_POST['valeur1'];
    $v2 = $_POST['valeur2'];
    $op = $_POST['operation'];

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
        default:
            echo "Opération invalide.";
            exit;
    }

    echo "<h2>Résultat</h2>";
    echo "$v1 $op $v2 = $resultat";

} else {
    echo "Veuillez remplir le formulaire.";
}
?>
 </body>
</html>
