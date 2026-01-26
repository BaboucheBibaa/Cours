<html>
 <body>
    <p>
        <?php
        if (!isset($_GET['depart']) || !isset($_GET['arrivee']))
            die('manque les villes');
        $ville1=$_GET["depart"];
        $ville2=$_GET["arrivee"];
        $distance= array(array("paris", "nice", 900),
        array("nice", "tours", 800),
        array("tours", "lille", 500),
        array("paris", "lille", 300),
        array("nice", "lille", 1200) );

        $estDedans=false;
        $resultat= 0;
        $ville1=strtolower($ville1);
        $ville2=strtolower($ville2);
        for ($i = 0; $i < count(value: $distance); $i++){
            if ($ville1 == $distance[$i][0] && $ville2 == $distance[$i][1]){
                $estDedans = true;
                $resultat=$distance[$i][2];
            }
        }
        if ($estDedans){
            echo "La distance entre les deux villes est de $resultat kms.";
        }
        ?>
    </p>
</body>
</html>