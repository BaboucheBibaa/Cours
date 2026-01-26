<html>
    <body>
    <h2 align="center">Jeu : plus grand, plus petit</h2>
        <p>
        <?php 
        if (!isset($_POST['a_trouver'])) {
            $a_trouver = mt_rand(0,100);
        } else {
            $a_trouver = intval($_POST['a_trouver']);
        }

        if (isset($_POST['propose'])) {
            $valeur_choisie = intval($_POST['propose']);

            if ($a_trouver > $valeur_choisie){
                echo "Plus grand";
            } else if ($a_trouver < $valeur_choisie){
                echo "Plus petit";
            } else {
                echo "Trouvé !";
            }
        }
        ?>
        <form method="post" action="jeu.php">
            Proposez une valeur entre 0 et 100 :
            <input type="text" name="propose"><br>
            <input type="hidden" name="a_trouver" value="<?php echo $a_trouver ?>">
            <input type="submit" value="Soumettre">
        </form>
        </p>
    </body>
</html>
